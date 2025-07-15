#include "MyInetAddress.h"
#include "MySocket.h"
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

#define MAX_BUF_LENS  1024

int main()
{
    MySocket *clientSocket = new MySocket();
    MyInetAddress *serverAddress = new MyInetAddress("127.0.0.1", 12345);
    clientSocket->MyConnect(serverAddress);

    while(true)
    {
        char buf[MAX_BUF_LENS] = {0};
        scanf("%s", buf);

        ssize_t writeBytes = write(clientSocket->getFd(), buf, MAX_BUF_LENS);

        if(writeBytes == -1){
            printf("socket already disconnected, can't write any more!\n");
            break;
        }

        bzero(buf, MAX_BUF_LENS);
        ssize_t read_bytes = read(clientSocket->getFd(), buf, MAX_BUF_LENS);
        if(read_bytes > 0)
        {
            printf("message from server: %s\n", buf);
        }
        else if(read_bytes == 0)
        {
            printf("server socket disconnected!\n");
            break;
        }
        else if(read_bytes == -1)
        {
            printf("socket read error!\n");
            break;
        }
    }

    return 0;
}
