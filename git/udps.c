// UDP Server
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    struct sockaddr_in client,servaddr;
    int udpsocket, n;

    char b1[100], b2[100];

    udpsocket=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=2000;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    bind(udpsocket, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("\nServer ready,waiting for client....\n");

    n = sizeof(client);
    while(1)
    {
        recvfrom(udpsocket, b1, sizeof(b1), 0, (struct sockaddr *) &client, &n);
        
        printf("\nClient:%s",b1);

        printf("\nServer:");
        gets(b2);

        sendto(udpsocket, b2, sizeof(b2), 0, (struct sockaddr *) &client, n);
               
    }
  return 0;
}