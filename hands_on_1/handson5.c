/*
============================================================================
Name : handson5.c
Author : Murli Talreja
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 09th SEpt, 2023.
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>    

void main()
{
    while (1)
    {
        creat("./sample-files/file_1", O_CREAT);
        creat("./sample-files/file_2", O_CREAT);
        creat("./sample-files/file_3", O_CREAT);
        creat("./sample-files/file_4", O_CREAT);
        creat("./sample-files/file_5", O_CREAT);
    }
}
