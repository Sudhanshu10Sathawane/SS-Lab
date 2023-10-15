#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<pthread.h>
void main(){
	char buff1[100];
	char buff2[100];
	int fd1=open("fifo1",O_WRONLY);
	int fd2=open("fifo2",O_RDONLY);
	printf("Enter the text: ");
	scanf("%[^\n]",buff1);
	write(fd1,buff1,sizeof(buff1));
	read(fd2,buff2,sizeof(buff2));
	printf("Message from FIFO is: %s\n",buff2);	
}