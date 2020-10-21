#ifndef KALI_SOCK
#define KALI_SOCK

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>


typedef struct KALI_SERVER
{
    int addrFamily;

    int protocol;

    int type;

    int fileDescriptor;

    int portNum;

    struct sockaddr_in servSock;

} KALI_SERVER;

void constructServer(KALI_SERVER* serv, int addrFamily, int protocol, int type, int port);

typedef struct KALI_CLIENT
{

    int addrFamily;

    int protocol;

    int type;

    int fileDescriptor;

    int portNum;

    const char* servAddr;

    struct sockaddr_in servSock;

} KALI_CLIENT;

int constructClient(KALI_CLIENT* client, const char* servAddr,int addrFamily, int type, int protocol, int port);

void getPacket(char ** packet, unsigned short packNum);

#endif