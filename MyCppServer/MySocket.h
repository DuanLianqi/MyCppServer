#ifndef MYSOCKET_H
#define MYSOCKET_H

class MyInetAddress;

class MySocket
{
private:
    int fd;

public:
    MySocket();
    MySocket(int fd);
    ~MySocket();

    void MyBind(MyInetAddress *serverAddress);
    void MyListen();
    void setNonBlocking();
    int MyAccept(MyInetAddress *clientAddress);
    int MyConnect(MyInetAddress* serverAddress);
    int getFd();
};

#endif // MYSOCKET_H