#include "MyInetAddress.h"
#include "MySocket.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF_LENS  1024

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

    while(true)
    {
        char buf[MAX_BUF_LENS] = {0};
        char bufReply[MAX_BUF_LENS] = {0};
        strcpy(bufReply, "this is a reply.");

        ssize_t readBytes = read(clientFd, buf, MAX_BUF_LENS);
        if(readBytes > 0)
        {
            printf("message from client fd : %d, content is : %s\n", clientFd, buf);
            write(clientFd, bufReply, MAX_BUF_LENS);
        }
        else if(readBytes == 0)
        {
            printf("client fd : %d disconnect.\n", clientFd);
            close(clientFd);
            break;
        }
        else if(readBytes == -1)
        {
            printf("socket read error! client fd : %d.\n", clientFd);
            close(clientFd);
            break;
        }
    }

    close(clientFd);

    return 0;
}