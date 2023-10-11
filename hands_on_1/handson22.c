/*
============================================================================
Name : handson22.c
Author : Murli Talreja
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 09th Sept, 2023.
============================================================================
*/


#include <unistd.h>    
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     

void main()
{
    char *filename = "temp3.txt";
    int childPid, fileDescriptor;
    fileDescriptor = open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);

    if ((childPid = fork()) != 0) // Only parent can enter this branch
        write(fileDescriptor, "Parent\n!", 7);
    else // Only child can enter this branch
        write(fileDescriptor, "Child\n!", 6);
    close(fileDescriptor);
}
