/*
============================================================================
Name : handson27d.c
Author : Murli Talreja
Description :Write a program to execute ls -Rl by the following system calls
d. execv

Date: 09th Sept, 2023.
============================================================================
*/

#include <unistd.h> 
#include <stdio.h>  

void main()
{
    char *args[] = {"/bin/ls", "-Rl",  NULL}; // Set the last but one element if you want to execute `ls` command on a particular file

    printf("============OUTPUT USING execv===============\n");
    execv(args[0], args);
    printf("\n");
}
