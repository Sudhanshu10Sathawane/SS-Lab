#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<pthread.h>
int main(){
	int fd[2];
	pipe(fd);
	int childId=0;
	if(!fork()){
		//child process: reading
		close(fd[1]); //close write-descriptor
		read(fd[0],&childId,sizeof(childId));
		printf("Child %d recieved childId: %d\n",getpid(),childId);
		//close the read-desciptor
		close(fd[0]);
	}else{
		close(fd[0]);
		childId=1;
		write(fd[1],&childId,sizeof(childId));
		printf("Parent %d send childId: %d\n",getpid(),childId);
		close(fd[1]);
	}
	return 0;
}
