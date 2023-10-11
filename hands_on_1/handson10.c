/*
============================================================================
Name : handson10.c
Author :  Murli Talreja
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 09th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	fd = open("temp10.txt",O_RDWR|O_CREAT);
	if(fd == -1)
	{
		printf("Error occured!!\n");
	}
	int w;
	write(fd,"1234567890",strlen("1234567890"));
	int seek = lseek(fd,10,SEEK_CUR);
	
	write(fd,"9876543210",strlen("9876543210"));

	printf("\nPointer after lseek : %d\n",seek);
	system("od -c temp10.txt");
	return 0;
}
