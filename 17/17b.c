#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<pthread.h>
void main(){
	int fd[2];
	pipe(fd);
	if(!fork()){
		close(1);
		close(fd[0]);
		dup2(fd[1],1);
		execlp("ls","ls","-l",(char *)NULL);
	}else{
		close(0);
		close(fd[1]);
		dup2(fd[0],0);
		execlp("wc","wc",(char *)NULL);
	}
}