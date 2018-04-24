#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include<math.h>
int main(void){
    int fd[2],i,num[10],num2[10];
	double sum = 0,sum2 = 0;
	double mean,sd;
	pid_t childpid;
	pipe(fd);
	if ((childpid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Enter ten numbers: ");
		for(i = 0; i <=9 ;i++){
			scanf("%d",&num[i]);
		}
		for(i = 0;i<=9; i++){
			sum = sum + num[i];
		}
		printf("%d\n",sum);
		mean = (sum)/10;
		printf("%f\n",mean);
		for (i = 0;i<=9;i++){
		    printf("%d\n",num[i]);
			num2[i] = num[i] - mean;
			printf("%d\n",num2[i]);
		}
		for (i = 0;i<=9;i++){
			sum2 = sum2 + pow(num2[i],2);
		}
		printf("\n%d",sum2);
		sd = sum2 / pow(10,1/2);
		write(fd[1],&mean,sizeof(mean));
		write(fd[1],&sd,sizeof(sd));
		exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&mean,sizeof(mean));
		read(fd[0],&sd,sizeof(sd));
		printf("The mean of numbers:%f ",mean);
		printf("The Standard deviation of numbers:%f",sd);
	}
	return 0;
}
