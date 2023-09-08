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
