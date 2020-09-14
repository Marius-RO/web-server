#pragma once
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

class TcpListener {

public:
	TcpListener(const char* ipAdress, int port):m_ipAdress(ipAdress), m_port(port){}

	// Initialize the listener
	int init();

	// Run the listener
	int run();

protected:

	//	Handelor for client connections
	virtual void onClientConected(int clientSocket);

	//	Handelor for client disconnections
	virtual void onClientDisconected(int clientSocket);


	//	Handler for when a message is received from the client
	virtual void onMessageReceived(int clientSocket, const char* msg, int length);

	//	send a message to client
	void sendToClient(int clientSocket, const char* msg, int length);

	//Broadcast message from a client
	void broadcastToClients(int sendingClient, const char* msg, int length);

private:
	const char*		m_ipAdress; // IP adress server will run on
	int				m_port;		// port number for web service
	int				m_socket;	// internal socket file descriptor for the listening socket
	fd_set			m_master;   // master file descriptor set
};