#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

int main(void)
{
        int fd[2];
        float a,b,pro=1.0,qt=1.0;
        pid_t   childpid;

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
                scanf("%f%f",&a,&b);
                pro=a*b;
                qt=a/b;
                write(fd[1], &pro, sizeof(pro));
                write(fd[1], &qt, sizeof(qt));
                exit(0);
        }

        else

        {

                /* Parent process closes up output side of pipe */
                close(fd[1]);

                /* Read in a string from the pipe */
                read(fd[0], &pro, sizeof(pro));
                read(fd[0], &qt, sizeof(qt));
                printf("The product is = %f", pro);
                printf("The quotient is = %f", qt);
        }

        return(0);
}
