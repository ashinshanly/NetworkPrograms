// UDP Client
#include <stdio.h>
#include <string.h>
#include <sys/stat.h> //**
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    struct sockaddr_in servaddr;
    int udpsocket, n;

    char b1[100], b2[100];

    udpsocket=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=2000;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    printf("\nClient ready....\n");
    n = sizeof(servaddr);
    while(1)
    {
        printf("\nClient:");
        gets(b1);

        sendto(udpsocket, b1, sizeof(b1), 0, (struct sockaddr *) &servaddr, n);
        
        recvfrom(udpsocket, b2, sizeof(b2), 0, NULL, NULL);

        printf("\nServer:%s",b2);
    }
    return 0;
}