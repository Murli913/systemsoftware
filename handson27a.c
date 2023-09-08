#include <unistd.h> 
#include <stdio.h>  

void main()
{
    char *command_path = "/bin/ls";
    char *options = "-Rl";

    printf("============OUTPUT USING execl===============\n");
    execl(command_path, command_path, options, NULL);
    printf("\n");
}
