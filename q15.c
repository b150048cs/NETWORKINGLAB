#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void)
{
	int a[10]; 
	int fd[2];
	int i =1;
	float mean;
	pid_t childpid;
	pipe(fd);
	 if((childpid = fork()) < -1)
        {
                perror("fork");
                exit(1);
        }
     if(childpid == 0)
     {
      close(fd[0]);
      printf("Enter the ten Numbers: ");
      for(i = 1; i < 10; i++)
       {
      scanf("%d", &a[10]);
         }

        mean = (sum(a[i])) / 10 ;
       write(fd[1], &a[10], sizeof(a[10]);
        exit(0);

        
       else{
        	close(fd[1]);
        	read(fd[0], &a[], sizeof(a[]));
        	printf("The mean of ten num is: %d",mean);
        	

        }
        return 0;
    

      
    