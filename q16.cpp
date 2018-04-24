#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void){
	int fd[2],a;
	float r,si,co,ta;
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) < 0){
		perror("Fork");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Enter angle: ");
		scanf("%d",&a);
		r = a*3.14159 / 180;
		si = sin(r);
		co = cos(r);
		ta = tan(r);
		write(fd[1],&si,sizeof(si));
		write(fd[1],&co,sizeof(co));
		write(fd[1],&ta,sizeof(ta));
		exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&si,sizeof(si));
		read(fd[0],&co,sizeof(co));
		read(fd[0],&ta,sizeof(ta));
		printf("Sine: %f\n",si);
		printf("Cosine: %f\n",co);
		printf("Tangent: %f",ta);
	}
}
