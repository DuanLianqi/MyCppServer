#include "MyInetAddress.h"
#include "MySocket.h"

int main()
{
    MySocket *clientSocket = new MySocket();
    MyInetAddress *serverAddress = new MyInetAddress("127.0.0.1", 12345);
    clientSocket->MyConnect(serverAddress);

    return 0;
}
