// Time Server
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

int main(){

	int sockfd,n;
	char buff[100];

	struct sockaddr_in servaddr, client;
	n = sizeof client;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = 2000;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sockfd, (struct sockaddr*) &servaddr, sizeof servaddr);
	printf("\nServer ready,waiting for client....\n");
    
	recvfrom(sockfd, buff, 100, 0, (struct sockaddr*) &client, &n);

	time_t t;
	t=time(NULL);
	strcpy(buff, ctime(&t));
	
	printf("%s\n", buff);
	sendto(sockfd, buff, sizeof buff, 0, (struct sockaddr*) &client, n);

	close(sockfd);
	return 0;
}