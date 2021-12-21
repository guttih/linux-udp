#include "udpcomunication.h"
#include <string.h>

using namespace std;

UdpComunication::UdpComunication(const char *ipAddress, unsigned int port)
{
    init(ipAddress, port);
}

bool UdpComunication ::init(const char *ipAddress, unsigned int port)
{
    if (!ipAddress)
        return false;

    int i = strlen(ipAddress);

    if (i > 6 && i < 16 && port > 1000) {
        strcpy(this->strIpAddress, ipAddress);
        this->port = port;
        return true;
    }

    return false;
}

bool UdpComunication::connect() {
    // https://www.geeksforgeeks.org/udp-server-client-implementation-c/
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "{\"Hei\": \"dude\"}";
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(this->port);
    servaddr.sin_addr.s_addr = inet_addr(this->strIpAddress);

    int n, len;

    n = sendto(sockfd, (const char *)hello, strlen(hello),
        MSG_CONFIRM, (const struct sockaddr *) &servaddr,
            sizeof(servaddr));
    printf("Hello message sent.\n");
    int sin_size = sizeof(sockaddr_in);
    n = recvfrom(   sockfd,
                    (char *)buffer,
                    MAXLINE,
                    MSG_WAITALL,
                    ( struct sockaddr *) &servaddr,
                    (socklen_t*)&sin_size
                );
    buffer[n] = '\0';
    printf("Recived %d chars : \"%s\"\n", n, buffer);
    close(sockfd);
    return true;
}
