// TCP Server
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    struct sockaddr_in client,server;
    int sockfd, connfd, n;
    char b1[100], b2[100];

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockfd, (struct sockaddr *) &server, sizeof(server));

    listen(sockfd, 5);

    printf("\nServer ready,waiting for client....\n");
    
    n=sizeof(client);
    connfd = accept(sockfd, (struct sockaddr *) &client, &n);
  
    while(1)
    {
        recv(connfd, b1, sizeof(b1), 0);
       
        printf("\nClient:%s",b1);

        printf("\nServer:");
        gets(b2);

        send(connfd, b2, sizeof(b2), 0);
      
    }
    
    close(connfd);
    close(sockfd);
    return 0;
}

