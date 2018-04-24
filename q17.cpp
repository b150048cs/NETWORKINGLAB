#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main(void){
	int fd[2];
	char s[100];
	float height,weight,BMI;
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) < 0){
		perror("Fork");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Your Name: ");
		gets(s);
		printf("Your weight in kilograms: ");
		scanf("%f",&weight);
		printf("Your height in meter: ");
		scanf("%f",&height);
		BMI = weight/(height*height);
		write(fd[1],&BMI,sizeof(BMI));
		write(fd[1],&s,sizeof(s));
		exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&BMI,sizeof(BMI));
		read(fd[0],&s,sizeof(s));
		printf("Hello! %s, Your BMI is:%f",s,BMI);
	}
	return(0);
}
