/*
============================================================================
Name : Client.c
Author : Murli Talreja
Description : Chat application between two machines using socket.
Date: 11th Oct, 2023.
============================================================================
*/
#include <arpa/inet.h> 
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> 
#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
  #include <unistd.h>




void main()
{
    int sfd; 
    int cs;        

    struct sockaddr_in address; 

    ssize_t rb, wb; 
    char dataFromServer[1024];

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Client side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8083);

    cs = connect(sfd, (struct sockaddr *)&address, sizeof(address));
    if (cs == -1)
    {
        perror("Error while connecting to server!");
        _exit(0);
    }
    printf("Client to server connection successfully established!\n");

while(1){
bzero(dataFromServer,1024);
printf("enter the message\n");
fgets(dataFromServer,1024,stdin);
wb=write(sfd,dataFromServer,strlen(dataFromServer));
if(wb<0){printf("error in writing");
exit(1);}
bzero(dataFromServer,1024);
rb=read(sfd,dataFromServer,1024);
if(rb<0){printf("error in writing");
exit(1);}

printf("\n server --> %s", dataFromServer);

if(!strncmp("bye", dataFromServer,3)){break;}


}
    
    close(sfd);
}
