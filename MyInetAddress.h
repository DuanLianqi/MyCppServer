#ifndef MYINETADDRESS_H
#define MYINETADDRESS_H

#include <arpa/inet.h>

class MyInetAddress
{
public:
    struct sockaddr_in inetAddr;
    socklen_t addrLen;

    MyInetAddress();
    MyInetAddress(const char *ip, uint16_t port);
    ~MyInetAddress();
};

#endif // MYINETADDRESS_H