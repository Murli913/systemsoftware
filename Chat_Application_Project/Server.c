/*
============================================================================
Name : Server.c
Author : Murli Talreja
Description :  Chat application to communicate between two machines using socket.
Date: 11th Oct, 2023.
============================================================================
*/

#include <arpa/inet.h> 
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>

#include <string.h>
#include <strings.h> 
#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdlib.h>
    

void main()
{
    int sfd, cfd;
    int bs; // Determines success of `bind`
    int ls; // Determines success of `listen`
    int clientSize;

    struct sockaddr_in address, client;

    ssize_t rb, wb;
    char dataFromClient[1024];

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        perror("Error while creating socket!");
        exit(0);
    }
    printf("Server side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8083);

    bs = bind(sfd, (struct sockaddr *)&address, sizeof(address));
    if (bs == -1)
    {
        perror("Error while binding name to socket!");
        exit(0);
    }
    printf("Binding to socket was successful!\n");

    ls = listen(sfd, 2);
    if (ls == -1)
    {
        perror("Error while trying to listen for connections!");
        exit(0);
    }
    printf("Now listening for connections on a socket!\n");

    clientSize = (int)sizeof(client);
    cfd = accept(sfd, (struct sockaddr *)&client, &clientSize);
    if (cfd == -1)
        perror("Error while accepting a connection!");
    else
    {
while(1){
bzero(dataFromClient,1024);
rb=read(cfd,dataFromClient,1024);
if(rb<0){printf("error in reading..");
exit(1);}

printf("\nclient --> %s", dataFromClient);

bzero(dataFromClient,1024);
printf("enter the message\n");
fgets(dataFromClient,1024,stdin);
wb=write(cfd,dataFromClient,1024);
if(wb<0){printf("error in writing..");
exit(1);}

if(!strncmp("bye",dataFromClient,3)){break;}
	    

}
}

    close(cfd);

    close(sfd);
}
