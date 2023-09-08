 #include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(void){
int fd;
char buf[80];

fd=read(0,buf,sizeof(buf));
write(1, buf, fd);
printf("%s\n", buf);
}
