/*
============================================================================
Name : handson27b.c
Author : Murli Talreja
Description :Write a program to execute ls -Rl by the following system calls
b. execlp

Date: 09th Sept, 2023.
============================================================================
*/

#include <unistd.h> 
#include <stdio.h>  

void main()
{
    char *command_path = "/bin/ls";
    char *options = "-Rl";
   

    printf("============OUTPUT USING execlp===============\n");
    execlp(command_path, command_path, options, NULL);
    printf("\n");
}
