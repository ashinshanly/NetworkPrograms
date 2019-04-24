//FTP Client
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int sockfd, n;
	char buff[100];

	struct sockaddr_in servaddr;
	n = sizeof servaddr;

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = 2000;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	printf("Enter filename: \n");
	gets(buff);

	sendto(sockfd, buff, sizeof buff, 0, (struct sockaddr*) &servaddr, n);
	recvfrom(sockfd, buff, 100, 0, NULL, NULL);

	printf("The contents of the file are: %s \n", buff);

	close(sockfd);
	return 0;
}