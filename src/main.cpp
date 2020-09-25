#include "../headers/WebServer.h"

int main(){

    WebServer webServer(SERVER_ADDRESS, SERVER_PORT);

    if (webServer.init() != 0)
        return -1;

    webServer.run();

    system("pause");

    return 0;
}