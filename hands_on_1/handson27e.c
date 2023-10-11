/*
============================================================================
Name : handson27e.c
Author : Murli Talreja
Description :Write a program to execute ls -Rl by the following system calls
e. execvp

Date: 09th Sept, 2023.
============================================================================
*/

#include <unistd.h> 
#include <stdio.h>  

void main()
{
 
    char *args[] = {"/bin/ls", "-Rl",NULL}; 

    printf("============OUTPUT USING execvp===============\n");
    execvp(args[0], args);
    printf("\n");
}
