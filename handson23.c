#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(){

int p=fork();
if(p==0){
printf("i am chlid having pid %d\n", getpid());
printf("my parent pid is %d\n", getppid());

}
else{
sleep(10);
printf("i am parent having pid %d\n" , getpid());
printf("my chlid pid is %d\n",p);
}
return 0;
}
