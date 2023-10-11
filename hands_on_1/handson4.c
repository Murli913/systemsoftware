/*
============================================================================
Name : handson4.c
Author : Murli Talreja
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 09th Sept, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

void main() {
  int fd=open("temp3.txt", O_RDWR | O_CREAT|O_EXCL, 0777);

  if(fd == -1) {
    printf("Error %d\n", errno);
    perror("Program");
  }
  printf("fd=%d \n", fd);
  char* str="This is a test line.";
  int wr=write(fd, str, strlen(str)+1);
  printf("Status of writing in the file : %d\n", wr);
  close(fd);
  fd=open("temp3.txt", O_RDWR);
  char str2[80];
  read(fd, str2, 80);
  printf("Read = %s\n", str2);
  close(fd);
}

