#ifndef ERROR_H
#define ERROR_H
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void error(const char *mssg){
	perror(mssg);
	exit(0);
}
#endif
