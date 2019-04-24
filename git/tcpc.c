// TCP Client
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
    struct sockaddr_in server;
    int sockfd;
    char b1[100]="", b2[100]="";

    sockfd = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("\nClient ready....\n");
    connect(sockfd, (struct sockaddr *)&server, sizeof(server));

    while(1)
    {
        printf("\nClient:");
        gets(b2);
        //write(sockfd, b2, sizeof b2);
        send(sockfd, b2, sizeof b2, 0);
        
        recv(sockfd, b1, sizeof b1, 0);
        //read(sockfd, b1, sizeof b1);
        
        printf("\nServer:%s",b1);
    }
    close(sockfd);
    return 0;
}
