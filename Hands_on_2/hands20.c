/*
============================================================================
Name : hands20.c
Author : Murli Talreja
Description :Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 11th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
int res;
res=mkfifo("fifo1",0777);
printf("named pipe created\n");
}
