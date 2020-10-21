#include <stdio.h>
#include <stdlib.h>
#include "../lib/kaliSock.h"
#include "../lib/wackString.h"


int main()
{
  /*
  KALI_CLIENT* testClient = (KALI_CLIENT* )malloc(sizeof(KALI_CLIENT));
  //int constructRes = constructClient(testClient, "127.0.0.1", AF_PACKET, SOCK_DGRAM, ETH_P_ALL, 0);
  int constructRes = constructClient(testClient, "127.0.0.1", AF_PACKET, SOCK_DGRAM, ETH_P_ALL, 0);
  printf("CLIENT RESTULT: %d\n\n\n", constructRes);

  //while(1){
  for ( int x = 0; x < 20; x++){
    unsigned char* buffer = (unsigned char *)malloc(65534);
    int bufferSize = 0;
    bufferSize = recv(testClient->fileDescriptor, buffer, 65534, 0);

    printf("GOT A PACKET OF SIZE: %d BYTES\n", bufferSize);
    for (int i = 0; i < bufferSize; i++)
    {
      printf("%x ",(unsigned char)buffer[i]);
    }
    printf("\n\n\n");
  }
  */

  char ** arrOfStrs = (char **)malloc(65534);
  refStringArr(&arrOfStrs);

  return 0;
}
