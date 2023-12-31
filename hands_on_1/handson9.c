/*
============================================================================
Name : handson9.c
Author : Murli Talreja
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 09th Sept, 2023.
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>  
#include <unistd.h>    
#include <stdio.h>     
#include <time.h>      

void main(int argc, char *argv[])
{
    char *filename;
    int status;

    struct stat statbuf;
    if (argc != 2)
        printf("Pass the file name as the argument!\n");
    else
    {
        filename = argv[1];
        status = stat(filename, &statbuf);

        if (status == -1)
            perror("Error while executing the file!");
        else
        {
            printf("Inode -> %ld\n", statbuf.st_ino);
            printf("Number of hardlinks -> %ld\n", statbuf.st_nlink);
            printf("UID -> %d\n", statbuf.st_uid);
            printf("GID -> %d\n", statbuf.st_gid);
            printf("Size -> %ld\n", statbuf.st_size);
            printf("Block Size -> %ld\n", statbuf.st_blksize);
            printf("Number of Blocks -> %ld\n", statbuf.st_blocks);
            // Use the `ctime` function in `time.h` header to convert the timestamp in epoch to a more human readable form
            printf("Time of last access -> %s", ctime(&statbuf.st_atim.tv_sec));
            printf("Time of last modification -> %s", ctime(&statbuf.st_mtim.tv_sec));
            printf("Time of last change -> %s", ctime(&statbuf.st_ctim.tv_sec));
        }
    }
}
