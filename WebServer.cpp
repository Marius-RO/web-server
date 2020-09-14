#include <string>
#include <istream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include "WebServer.h"

void WebServer::onClientConected(int clientSocket) {

}

void WebServer::onClientDisconected(int clientSocket) {

}

void WebServer::onMessageReceived(int clientSocket, const char* msg, int length) {
	
	// GET /index.html HTTP/1.1


	// Parse out the document requested
	std::istringstream iss(msg);
	std::vector<std::string> parsed((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

	std::string content = "<h1>404 Not Found</h1>";
	std::string htmlFile = "";
	int errorCode = 404;

	if (parsed.size() >= 3 && parsed[0] == "GET") {
		htmlFile = parsed[1];
		if (htmlFile == "/")
			htmlFile = "/index.html";
	}

	// Open the document in the local file system
	std::ifstream f(".\\wwwroot" + htmlFile);

	if (f.good()) {
		std::string str((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
		content = str;
		errorCode = 200;
	}

	f.close();


	// Write the document back to the client
	std::ostringstream oss;
	oss << "HTTP/1.1 " << errorCode << " OK\r\n";
	oss << "Cache-Control: no-cache, private\r\n";
	oss << "Content-Type: text/html\r\n";
	oss << "Content-Length: " << content.size() << "\r\n";
	oss << "\r\n";
	oss << content;

	std::string output = oss.str();
	int size = output.size() + 1;

	sendToClient(clientSocket, output.c_str(), size);

}