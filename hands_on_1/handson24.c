/*
============================================================================
Name : handson24.c
Author : Murli Talreja
Description : Write a program to create an orphan process.
Date: 09th Sept, 2023.
============================================================================
*/



#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(){
	int p=fork();
	if(p==0){
		sleep(20);
		printf("i am chlid having pid %d\n", getpid());
		printf("my parent pid is %d\n", getppid());
	}
	else{
		
		printf("i am parent having pid %d\n", getpid());
		printf("my chlid pid is %d\n", p);
	}

}
