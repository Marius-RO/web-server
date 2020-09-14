#pragma once
#pragma once
#include "TcpListener.h"

class WebServer : public TcpListener {

public:
	WebServer(const char* ipAddress, int port) :TcpListener(ipAddress, port) {}

protected:

	//	Handelor for client connections
	virtual void onClientConected(int clientSocket);

	//	Handelor for client disconnections
	virtual void onClientDisconected(int clientSocket);

	//	Handler for when a message is received from the client
	virtual void onMessageReceived(int clientSocket, const char* msg, int length);

};