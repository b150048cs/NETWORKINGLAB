#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void)
{
	int cel,far,fd[2];
	pid_t childpid;
	pipe(fd);
	
	if ((childpid) = fork() < 0){
		perror("fork error");
		exit(1);
	}
	if (childpid == 0){
		close(fd[0]);
		
		printf("Enter the temprature in celsius:");
		scanf("%d",&cel);
		far = 1.8*cel + 32;
		write(fd[1],&far,sizeof(far));
		exit(0);
	}
	else{
		close(fd[1]);
		
		read(fd[0],&far,sizeof(far));
		printf("The Temprature in Farenhite is:%d",far);
		
	}
	return 0;
}
