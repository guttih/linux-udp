#ifndef UDPCOMUNICATION_H
#define UDPCOMUNICATION_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLINE 1024

class UdpComunication
{
    public:
        UdpComunication(const char*IPAddress, unsigned int port);
        bool connect();

    private:
        char strIpAddress[512] = "";
        unsigned int port = 0;
        bool init(const char *ipAddress, unsigned int port);
};

#endif // UDPCOMUNICATION_H
