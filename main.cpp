//#include "MultiClientChat.h"
#include "WebServer.h"

using namespace std;

void main()
{
	
	//MultiClientChat X("0.0.0.0", 54010);
	WebServer X("0.0.0.0", 8080);
	if (X.init() != 0)
		return;

	X.run();
	

	system("pause");
}