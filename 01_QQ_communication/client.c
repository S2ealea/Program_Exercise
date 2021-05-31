#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 80
#define PORT 9000
#define SA struct sockaddr


void func(int sockfd)
{
	char buff[MAX];
	int n;
	for(;;){
		memset(buff,0,sizeof(buff));
		printf("Enter the string: \n");
		n = 0;
		while((buff[n++] = getchar()) !='\n')
			;
		write(sockfd,buff,sizeof(buff));
		memset(buff,0,sizeof(buff));
		read(sockfd,buff,sizeof(buff));
		printf("From Server: %s\n",buff );
		if((strncmp("exit",buff,4))==0){
			printf("Client Exit...\n");
			break;
		}
	}
}


int main()
{
	int sockfd,connfd;
	struct sockaddr_in servaddr,cli;
	

	//Socket create and verification 
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
		printf("Socket Creation failed...\n");
	    exit(0);
	}
	else
		printf("Socket successfully created...\n");
	memset(&servaddr,0,sizeof(servaddr));

	// Assign IP,PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	// Connect the client socket to server socket 
	if (connect(sockfd,(SA*)&servaddr,sizeof(servaddr)) !=0 ){
		printf("Connection with the server failed...\n");
		exit(0);
	}
	else
		printf("Connection the the server...\n");

	// Function for chat
	func(sockfd);

	// Close the socket
	close(sockfd);


		















}



