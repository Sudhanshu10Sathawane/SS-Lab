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
	int fd=open("fifo",O_WRONLY);
	printf("Enter the text: ");
	scanf("%[^\n]",buff);
	write(fd,buff,sizeof(buff));
}