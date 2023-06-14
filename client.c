// Client side implementation of UDP client-server model
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
	
	struct sockaddr_in	 servaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	//memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	int check=0;
	
	while(1)
	{
		int n, len;
		char buffer[MAXLINE]="";
		printf("Client 1 Message: \n");
		char hello[200] = "";
		fgets(hello, 100, stdin);
		sendto(sockfd, (const char *)hello, strlen(hello),
			0, (const struct sockaddr *) &servaddr,
				sizeof(servaddr));
		
		int val=strcmp(buffer,"quit");
			if(val==0)
			{
				close(sockfd);
				return 0;
			}	
		n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, (struct sockaddr *) &servaddr,
					&len);
		
		//buffer[n] = '\0';
		printf("Server Message: %s\n",buffer);
		//printf("Server Message byte size: %d\n", strlen(buffer)-1);
		val=strcmp(buffer,"quit");
			if(val==0)
			{
				close(sockfd);
				return 0;
			}
	}
	close(sockfd);
	return 0;
}
