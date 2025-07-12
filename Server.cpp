#include "MyInetAddress.h"
#include "MySocket.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    MySocket *serverSocket = new MySocket();

    // 此处可以修改为将IP和端口改为main函数的参数
    MyInetAddress *serverInetAddress = new MyInetAddress("127.0.0.1", 12345);

    serverSocket->MyBind(serverInetAddress);
    serverSocket->MyListen();

    MyInetAddress *clientInetAddress = new MyInetAddress();
    int clientFd = serverSocket->MyAccept(clientInetAddress);

    //MySocket *clientSocket = new MySocket(clientFd);

    printf("new client fd %d, IP : %s, port : %d.\n", clientFd, inet_ntoa(clientInetAddress->inetAddr.sin_addr), ntohs(clientInetAddress->inetAddr.sin_port));

    return 0;
}