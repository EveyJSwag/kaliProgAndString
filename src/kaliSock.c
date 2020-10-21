#include "../lib/kaliSock.h"

void constructServer(KALI_SERVER* serv, int addrFamily, int protocol, int type, int port)
{
    serv->addrFamily = addrFamily;
    serv->protocol   = protocol;
    serv->portNum    = port;
    serv->type       = type;

    serv->servSock.sin_family = addrFamily;
    serv->servSock.sin_port = htons(port);
    serv->servSock.sin_addr.s_addr = INADDR_ANY;

    if (protocol == SOCK_STREAM)
        serv->fileDescriptor = socket(addrFamily, SOCK_STREAM, 0);
    else if (protocol == SOCK_DGRAM)
        serv->fileDescriptor = socket(addrFamily, SOCK_DGRAM, 0);

    if (serv->fileDescriptor > 0)
        bind(serv->fileDescriptor, (struct sockaddr *)&serv->servSock, sizeof(serv->servSock) );


}

int constructClient(KALI_CLIENT* client, const char* servAddr,int addrFamily, int type, int protocol, int port)
{
    
    client->addrFamily = addrFamily;
    client->protocol   = protocol;
    client->portNum    = port;
    client->type       = type;
    client->servSock.sin_family = addrFamily;
    client->servSock.sin_port   = htons(port);

    if ((uint16_t)protocol != ETH_P_ALL)
        inet_pton(addrFamily, servAddr, &client->servSock.sin_addr);
    else
        client->protocol = htons(protocol);

    client->fileDescriptor = socket(client->addrFamily, client->type, client->protocol);
    printf("FILE DESCRIPTOR: %d\n", client->fileDescriptor);
    if (client->fileDescriptor > 0)
    {
        if ((uint16_t)client->protocol != htons(ETH_P_ALL))
        {
            if (client->fileDescriptor > 0)
            {
                if (connect(client->fileDescriptor, (struct sockaddr*)&client->servSock, sizeof(client->servSock)) > 0)
                    return 0;
                else
                    return -1;
            }
            else
                return -1;
        }
        else
            return 0;
    }
    else
        return -1;
    
}

void getPacket(char ** packet, unsigned short packNum)
{

    

}