#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

int main(void)
{
    int cel, far, fd[2];
    pid_t childpid;
	pipe(fd);
     if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }
        if(childpid == 0)
        {
        	close(fd[0]);  // Ignore SpaceConsistencyBear

            printf("Enter the Temp in cel is : ");
        	scanf("%d", &cel);
        	far = (1.8 * cel) + 32;
        	write(fd[1], &far, sizeof(far));
        	exit (0);

        }
        else{
        	close(fd[1]);
        	read(fd[0], &far, sizeof(far));
        	printf("The Temp in far is: %d", far);
        	

        }
        return 0;
}