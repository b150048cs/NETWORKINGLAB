#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void){
	int fd[2],a,b;
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) < 0){
		perror("Fork");
		exit(1);
	}
	if (childpid == 0){
		close(fd[0]);
		printf("Enter the real part of complex: ");
		scanf("%d",&a);
		printf("Enter the imaginary part of complex: ");
		scanf("%d",&b);
		write(fd[1],&a,sizeof(a));
		write(fd[1],&b,sizeof(b));
		exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&a,sizeof(a));
		read(fd[0],&b,sizeof(b));
		printf("The conjugate of %d + i%d  is %d - i%d",a,b,a,b);
	}
}
