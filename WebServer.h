#pragma once
#pragma once
#include "TcpListener.h"

class WebServer : public TcpListener {

	protected:
		virtual void onClientConected(SOCKET clientSocket);
		virtual void onClientDisconected(SOCKET clientSocket);
		virtual void onMessageReceived(SOCKET clientSocket, const char* message, int length);
		virtual void sendMessageToClient(SOCKET clientSocket, const char* message, int length);
		virtual void broadcastMessageToClients(SOCKET sendingClientSocket, const char* message, int length);

	public:
		WebServer(const char* serverIpAdress, const char* serverPort) :TcpListener(serverIpAdress, serverPort) {}
		virtual int shutdown();

};