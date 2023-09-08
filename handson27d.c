#include <unistd.h> 
#include <stdio.h>  

void main()
{
    char *args[] = {"/bin/ls", "-Rl",  NULL}; // Set the last but one element if you want to execute `ls` command on a particular file

    printf("============OUTPUT USING execv===============\n");
    execv(args[0], args);
    printf("\n");
}
