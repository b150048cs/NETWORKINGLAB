#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

int main(void)
{
        int     fd[2], a,b,sum;
        pid_t   childpid;
        //char    string[] = "Hello, world!\n";
       // char    readbuffer[80];

        pipe(fd);

        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                /* Child process closes up input side of pipe */
                close(fd[0]);

                /* Send data value through the output side of pipe */

                printf("Enter the values");
                scanf("%d%d",&a,&b);
                sum=a+b;
                write(fd[1], &sum, sizeof(sum));

                exit(0);
        }

        else

        {

                /* Parent process closes up output side of pipe */
                close(fd[1]);

                /* Read in a string from the pipe */
                read(fd[0], &sum, sizeof(sum));
                printf("The total sum= %d", sum);
        }

        return(0);
}
