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
