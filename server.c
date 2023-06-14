// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024

// Driver code
int main() {
	int sockfd;
	
	struct sockaddr_in servaddr, cliaddr[2];// work like pipe
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	//memset(&servaddr, 0, sizeof(servaddr));
	//memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	int len = sizeof(cliaddr); //len is value/resuslt
	int check=0;
	while(1)
	{
		//if(fork())
		//{
			int len, n;
			char buffer[MAXLINE]="";
			char hello[200] = "";
			

			n = recvfrom(sockfd, (char *)buffer, MAXLINE,
						0, ( struct sockaddr *) &cliaddr[0],
						&len);
			
			sendto(sockfd, (const char *)buffer, strlen(buffer),
				0, (const struct sockaddr *) &cliaddr[1],
					len);
			
			//buffer[n] = '\0';
			
			
			//printf("Client Message: %s\n",buffer);
			//printf("Client Message byte size: %d\n", strlen(buffer)-1);
			int val=strcmp(buffer,"quit");
			if(val==0)
			{
				close(sockfd);
				return 0;
			}
			//printf("Enter Server Message: \n");
			//fgets(hello, 100, stdin);
			n = recvfrom(sockfd, (char *)hello, MAXLINE,
						0, ( struct sockaddr *) &cliaddr[1],
						&len);
						
			sendto(sockfd, (const char *)hello, strlen(hello),
				0, (const struct sockaddr *) &cliaddr[0],
					len);
					
		
		val=strcmp(hello,"quit");
		if(val==0)
		{
			close(sockfd);
			return 0;
		}
		//}
	}
	return 0;
}
