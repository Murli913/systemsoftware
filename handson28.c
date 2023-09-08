#include<stdio.h>
#include<unistd.h>
#include<sched.h>
int main(void)
{
struct sched_param sp={sp.sched_priority=0};
int ret;
int politica;
ret=sched_setscheduler(getpid(), SCHED_OTHER, &sp);

if(ret==-1){
perror("ERROR sched_setscheduler\n");
return 1;

}

politica=sched_getscheduler(getpid());
printf("\n %d %d %d\n",SCHED_OTHER,SCHED_RR,SCHED_FIFO);
switch(politica){
	case SCHED_OTHER: printf("sched_other\n"); break;
	case SCHED_RR: printf("sched_rr\n"); break;
	case SCHED_FIFO: printf("sched_fifo\n"); break;
					 default : printf("unkonow   \n");

}

int max=sched_get_priority_max(politica);

int min= sched_get_priority_min(politica); 
printf("max %d\n", max);
printf("max %d\n", min);

}

