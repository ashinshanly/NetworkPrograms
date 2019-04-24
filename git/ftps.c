//FTP Server
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
// netbufsize = 100
void clearbuf(char *b){
	int i;
	for(i=0;i<100;i++)
		b[i]='\0';	
}
int main(){
	int sockfd, n;
	char buff[100];
	int ch;

	struct sockaddr_in servaddr, client;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = 2000;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));

	FILE *fp;
	clearbuf(buff);

	n = sizeof client;

	recvfrom(sockfd, buff, 100, 0, (struct sockaddr*) &client, &n);
	printf("File name: %s\n", buff);
	
	fp = fopen(buff, "r");

	if (fp == NULL)
	{
		printf("File open failed!\n");
		exit(0);
	}
	else
		printf("Success!\n");	
	int i=0;
	while((ch = fgetc(fp)) != EOF){

		buff[i++] = ch;
	}

	sendto(sockfd, buff, sizeof buff, 0, (struct sockaddr*) &client, n);
	fclose(fp);
	close(sockfd);
	return 0;

}