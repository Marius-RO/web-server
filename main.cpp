#include "MultiClientChat.h"
//#include "WebServer.h"

int main(){
	
    //MultiClientChat X(SERVER_ADDRESS, SERVER_PORT);
	//WebServer X(SERVER_ADDRESS, SERVER_PORT);

	MultiClientChat X(SERVER_ADDRESS, "54000");
	//WebServer X(SERVER_ADDRESS, "8080");
	if (X.init() != 0)
		return 0;

	X.run();
	
	system("pause");

	return 0;
}