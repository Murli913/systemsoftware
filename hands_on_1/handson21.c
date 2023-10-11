/*
============================================================================
Name : handson21.c
Author : Murli Talreja
Description : Write a program, call fork and print the parent and child process id.
Date: 09th Sept, 2023.
============================================================================
*/


#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    int childPid, pid;

    pid = getpid();

    printf("Parent PID: %d\n", pid);

    childPid = fork();

    if (childPid != 0)
        printf("Child PID: %d\n", childPid);
}
