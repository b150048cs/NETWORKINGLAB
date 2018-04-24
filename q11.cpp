
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void){
	int fd[2],num1,num2,rand1,rand2;
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) < 0){
		perror("Fork");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Enter a number: ");
		scanf("%d",&num1);
		printf("Enter second number: ");
		scanf("%d",&num2);
		rand1 = (num2 - num1)*(double)rand()/(double)RAND_MAX + num1;
		rand2 = (num2 - num1)*(double)rand()/(double)RAND_MAX + num1;
		write(fd[1],&rand1,sizeof(rand1));
		write(fd[1],&rand2,sizeof(rand2));
		exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&rand1,sizeof(rand1));
		read(fd[0],&rand2,sizeof(rand2));
		printf("First Random number:%d ",rand1);
		printf("Second Random number:%d ",rand2);
	}
}




