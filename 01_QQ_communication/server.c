#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 80
#define PORT 9000
#define SA struct sockaddr


// Function designed for chat between client and server
void func(int sockfd)
{

	char buff[MAX];
	int n;

	// Infinite loop for chat 
	for(;;){
		bzero(buff,MAX);
		//Read the message from client and copy it in buffer
		read(sockfd,buff,sizeof(buff));
		//Print buffer which contains the client contents
		printf("From client: %s \t To client: ", buff);
		bzero(buff,MAX);
		
		n = 0;
		//Copy server message in the buffer
		while ((buff[n++] = getchar()) !='\n');
		//and send that buffer to client
		write(sockfd,buff,sizeof(buff));

		//If message contains "Exit" then server exit and chat ended.
		if(strncmp("exit",buff,4)==0){
			printf("Server Exit ......\n");
			break;
		}

	}
}



int main ()
{
	int sockfd,connfd,len;
	struct sockaddr_in servaddr,cli;

	//Socket create and verification
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
		printf("Socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully creanted...\n");

	/* Clear structure */
	memset(&servaddr, 0, sizeof(struct sockaddr_in));
                               

	// Assign IP,PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly create socket to given IP  and verification
	if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr))) !=0){
		printf("Socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded...\n");

	//Now server is ready to listen and verification
	if((listen(sockfd,1)) !=0 ){
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening ...\n");
	len = sizeof(cli);
	sleep(3600);

	// Accept the data packet from client and verification
	connfd = accept(sockfd,(SA*)&cli,&len);
	if (connfd < 0)
	{
		printf("Server accept failed...\n");
		exit(0);
	}
	else
		printf("Server accept the client...\n");

	// Function for chatting between client and server
	func(connfd);

	// After chatting close the socket
	close(sockfd);


}
