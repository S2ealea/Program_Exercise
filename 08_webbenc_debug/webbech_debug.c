// Webbench debug

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char url[] = "http://10.90.100.1:8080/";
	int i;

	/* protocol/host delimiter */
    i=strstr(url,"://")-url+3;
    printf("%d\n",i); 

    if(strchr(url+i,'/')==NULL) 
    {
      fprintf(stderr,"\nInvalid URL syntax - hostname don't ends with '/'.\n");
      exit(2);
    }

    // Get host
    #define MAXHOSTNAMELEN 50
    char host[MAXHOSTNAMELEN];
    bzero(host,MAXHOSTNAMELEN);
    int tmp[10];
    strncpy(host,url+i,strchr(url+i,':')-url-i);
    printf("Host=%s\n",host);
	bzero(tmp,10);
	strncpy(tmp,index(url+i,':')+1,strchr(url+i,'/')-index(url+i,':')-1);
	printf("tmp=%s\n",tmp); 

	

	// Build resquest
	#define PROGRAM_VERSION "v-zou.0.1"
	#define http10 1
	#define REQUEST_SIZE 2048
	char request[REQUEST_SIZE];
	bzero(request,REQUEST_SIZE);

	// Request line
	//Using Get method 
	strcpy(request,"GET");
	strcat(request," ");
	strcat(request,url);

	// Using http 1.0 protocol
	strcat(request," HTTP/1.0");
	strcat(request,"\r\n");

	if(http10>0)
	strcat(request,"User-Agent: WebBench "PROGRAM_VERSION"\r\n");

	//Request head--host
	strcat(request,"Host: ");
	strcat(request,host);
	strcat(request,"\r\n");

	if(http10>1)
	strcat(request,"Connection: close\r\n");
    
    /* add empty line at end */
    if(http10>0) 
    strcat(request,"\r\n"); 
    printf("Req=%s\n",request);





	return 0;
}