#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<pthread.h>
void main(){
	char buff[100];
	int fd=open("fifo",O_RDONLY);
	read(fd,buff,sizeof(buff));
	printf("Message from 20w.c is: %s\n",buff);	
}