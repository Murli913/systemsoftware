/*
============================================================================
Name : handson1.c
Author : Murli Talreja
Description : Create the following types of a files using (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 09,Sept, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int v = symlink("dest.txt"," destSL");
	if(v<0)
		{perror("failed"); return 1;}

		int f = link("dest.txt", "destHL");
		if(f<0)
		{perror("failed");return 1;}

		int e = mknod("destFIFO", S_IFIFO,0);

		if(e<0)
			perror("failed");
		return 0;

	
}


