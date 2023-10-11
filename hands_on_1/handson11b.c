/*
============================================================================
Name : handson11a.c
Author : Murli Talreja
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
b. use dup2
Date: 09th Sept, 2023.
============================================================================
*/


#include <unistd.h>    
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <stdio.h>     

void main(int argc, char *argv[])
{

    char *filename;                        
    int fileDescriptor, dupFileDescriptor; 
    int writeByteCount;                  

    if (argc != 2)
        printf("Pass the file name as the argument!");
    else
    {
        filename = argv[1];
        fileDescriptor = open(filename, O_WRONLY | O_APPEND);
        if (fileDescriptor == -1)
            perror("Error while opening file");
        else
        {
            dupFileDescriptor = dup2(fileDescriptor, 123);

           
            writeByteCount = write(fileDescriptor, "Using original FD", 17);
            if (writeByteCount == -1)
                perror("Error while writing file using original FD");

            
            writeByteCount = write(dupFileDescriptor, "Using duplicate FD", 18);
            if (writeByteCount == -1)
                perror("Error while writing file using duplicate FD");

            close(fileDescriptor);
        }
    }
}
