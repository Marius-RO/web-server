#include <string>
#include <istream>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <regex>
#include "headers/WebServer.h"

void WebServer::onClientConnected(SOCKET clientSocket) {
    cout << "Client #" << clientSocket << " connected" << NEWLINE;
}

void WebServer::onClientDisconnected(SOCKET clientSocket) {
    cout << "Client #" << clientSocket << " disconnected" << NEWLINE;
}

void WebServer::sendMessageToClient(SOCKET clientSocket, const char* message, int length) {
	send(clientSocket, message, length,0);
}

void WebServer::onMessageReceived(SOCKET clientSocket, const char* message, int length) {

	// Parse out the request header (request is made by browser)
	// split by spaces https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
	istringstream iss(message);
	vector<string> parsed((istream_iterator<string>(iss)), istream_iterator<string>());

	string pageContent = "<h1>404 Not Found</h1>";
	string contentType;
	string htmlFileName;
	int errorCode = 404;

	if (parsed.size() >= 3 && parsed[0] == "GET") {

        htmlFileName = parsed[1];

        // if no page is requested return index.html
		if (htmlFileName == "/")
            htmlFileName = "/index.html";

        if (regex_match(htmlFileName, regex("(.*).html")))
            contentType = "text/html";

        if (regex_match(htmlFileName, regex("(.*).css")))
            contentType = "text/css";

        if (regex_match(htmlFileName, regex("(.*).js")))
            contentType = "application/javascript";

	}

	// Open the document in the local file system
	ifstream fin(WEB_FILES_DIRECTORY + htmlFileName);

	if (fin.good()) {
		string str((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
        pageContent = str;
		errorCode = 200;
	}

	fin.close();


	// Write the document back to the client
	ostringstream oss;
	oss << "HTTP/1.1 " << errorCode << " OK" << NEWLINE;
	oss << "Cache-Control: no-cache, private" << NEWLINE;
	oss << "Content-Type: " << contentType << NEWLINE;
	oss << "Content-Length: " << pageContent.size() << NEWLINE;
	oss << NEWLINE;
	oss << pageContent;

	std::string output = oss.str();
	int size = (int)output.size() + 1;

	sendMessageToClient(clientSocket, output.c_str(), size);

}
