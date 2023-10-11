/*
============================================================================
Name : handson3.c
Author : Murli Talreja
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 9th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>

void main() {
  char* file_name="temp.txt";
  mode_t mode=S_IRUSR;
  int fd;
  if((fd=creat(file_name, mode))<0)
    perror("Error while creation of file!");
  else
    printf("Created File Successfully! %d", fd);
}
