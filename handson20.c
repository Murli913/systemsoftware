#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h> 
#include<sched.h>
#include<sys/time.h>
#include<sys/resource.h>

void main(int argc, char *argv[])
{
	
    int priority, newp;
    if (argc != 2)
        printf("Please pass the integer value to be added to the current nice value\n");
    else
    {
       
        newp = atoi(argv[1]);
       int pri=getpriority(PRIO_PROCESS, getpid());
      
      
        printf("Current priority: %d\n", pri);
        priority = nice(newp); 
        printf("New priority: %d\n", priority);
    }
}
