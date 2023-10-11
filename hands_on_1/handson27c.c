/*
============================================================================
Name : handson27c.c
Author : Murli Talreja
Description :Write a program to execute ls -Rl by the following system calls
c. execle

Date: 09th Sept, 2023.
============================================================================
*/



#include <unistd.h> 
#include <stdio.h>  

void main()
{
    char *command_path = "/bin/ls";
    char *options = "-Rl";
   

    printf("============OUTPUT USING execle===============\n");
    execle(command_path, command_path, options, NULL, NULL);
    printf("\n");
}
