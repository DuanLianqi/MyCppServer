#include "MyInetAddress.h"
#include <string.h>

MyInetAddress::MyInetAddress() : addrLen(sizeof(inetAddr))
{
    bzero(&inetAddr, addrLen);
}

MyInetAddress::MyInetAddress(const char *ip, uint16_t port) : addrLen(sizeof(inetAddr))
{
    bzero(&inetAddr, addrLen);
    inetAddr.sin_family = AF_INET;
    inetAddr.sin_addr.s_addr = inet_addr(ip);
    inetAddr.sin_port = htons(port);
}

MyInetAddress::~MyInetAddress()
{
}
