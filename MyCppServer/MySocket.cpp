#include "MySocket.h"
#include "MyInetAddress.h"
#include "util.h"
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

MySocket::MySocket() : fd(-1)
{
    fd = socket(AF_INET, SOCK_STREAM, 0);
    errif(fd == -1, "socket create failed.\n");
}

MySocket::MySocket(int _fd) : fd(_fd)
{
}

MySocket::~MySocket()
{
    if(fd == -1)
    {
        close(fd);
        fd = -1;
    }
}

void MySocket::MyBind(MyInetAddress *serverAddress)
{
    int ret = bind(fd, (sockaddr *)&(serverAddress->inetAddr), serverAddress->addrLen);
    errif(ret == -1, "socket bind failed.\n");
}

void MySocket::MyListen()
{
    int ret = listen(fd, SOMAXCONN);
    errif(ret == -1, "socket listen failed.\n");
}

void MySocket::setNonBlocking()
{
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);
}

int MySocket::MyAccept(MyInetAddress *clientAddress)
{
    int clientFd = accept(fd, (sockaddr *)&(clientAddress->inetAddr), &(clientAddress->addrLen));
    errif(clientFd == -1, "socket accept failed.\n");
    return clientFd;
}

int MySocket::MyConnect(MyInetAddress *serverAddress)
{
    int serverFd = connect(fd, (sockaddr *)serverAddress, serverAddress->addrLen);
    errif(serverFd == -1, "socket connect failed.\n");
    return serverFd;
}

int MySocket::getFd()
{
    return fd;
}
