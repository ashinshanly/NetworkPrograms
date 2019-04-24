// Time Client
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

	int sockfd;
	char buff[100]=" ";

	struct sockaddr_in servaddr;
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = 2000;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	sendto(sockfd, buff, sizeof buff, 0, (struct sockaddr*) &servaddr, sizeof servaddr);
	recvfrom(sockfd, buff, sizeof buff, 0, NULL, NULL);
	printf("Received time : %s", buff);

	close(sockfd);
	return 0;
}