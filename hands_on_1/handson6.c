/*
============================================================================
Name : handson6.c
Author : Murli Talreja
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 09th Sept, 2023.
============================================================================
*/ 
 
 #include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(void){
int fd;
char buf[80];

fd=read(0,buf,sizeof(buf));
write(1, buf, fd);
printf("%s\n", buf);
}
