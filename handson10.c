#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	fd = open("temp10.txt",O_RDWR|O_CREAT);
	if(fd == -1)
	{
		printf("Error occured!!\n");
	}
	int w;
	write(fd,"1234567890",strlen("1234567890"));
	int seek = lseek(fd,10,SEEK_CUR);
	
	write(fd,"9876543210",strlen("9876543210"));

	printf("\nPointer after lseek : %d\n",seek);
	system("od -c temp10.txt");
	return 0;
}
