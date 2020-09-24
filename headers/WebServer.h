#pragma once
#pragma once
#include "TcpListener.h"

class WebServer : public TcpListener {

	protected:
		void onClientConnected(SOCKET clientSocket) override;
		void onClientDisconnected(SOCKET clientSocket) override;
		void onMessageReceived(SOCKET clientSocket, const char* message, int length) override;
		void sendMessageToClient(SOCKET clientSocket, const char* message, int length) override;

	public:
		WebServer(const char* serverIpAddress, const char* serverPort) :TcpListener(serverIpAddress, serverPort) {}

};