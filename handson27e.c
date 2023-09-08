#include <unistd.h> 
#include <stdio.h>  

void main()
{
 
    char *args[] = {"/bin/ls", "-Rl",NULL}; 

    printf("============OUTPUT USING execvp===============\n");
    execvp(args[0], args);
    printf("\n");
}
