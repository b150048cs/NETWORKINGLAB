#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include<math.h>
int main(void){
	int fd[2],i =0,j=0,val,len;
	char hex[17];
	long long decimal,place;
	pid_t childpid;
	pipe(fd);
	decimal = 0;
	if((childpid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Enter any Hexadecimal number: ");
		gets(hex);
		len = strlen(hex);
		len--;
		for (i=0;hex[i]!='\0';i++){
			if(hex[i]>='0' && hex[i]<='9'){
				val = hex[i] - 48;
			}
			else if(hex[i]>='a' && hex[i]<='f'){
				val = hex[i] - 97 + 10;
			}
			else if(hex[i]>='A' && hex[i]<='F'){
				val = hex[i] - 65 + 10;
			}
			decimal += val*pow(16,len);
			len--;
		}
		write(fd[1],&decimal,sizeof(decimal));
		write(fd[1],&hex,sizeof(hex));
		exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&decimal,sizeof(decimal));
		read(fd[0],&hex,sizeof(hex));
		printf("The Decimal of that number is:%lld",decimal);
		printf("Equivalent Binary is:");
				while(hex[j])
	{
		switch(hex[j])
		{
			case '0' : printf("0000");
				break;
			case '1' : printf("0001");
				break;
			case '2' : printf("0010");
				break;
			case '3' : printf("0011");
				break;
			case '4' : printf("0100");
				break;
			case '5' : printf("0101");
				break;
			case '6' : printf("0110");
				break;
			case '7' : printf("0111");
				break;
			case '8' : printf("1000");
				break;
			case '9' : printf("1001");
				break;
			case 'A' : printf("1010");
				break;
			case 'B' : printf("1011");
				break;
			case 'C' : printf("1100");
				break;
			case 'D' : printf("1101");
				break;
			case 'E' : printf("1110");
				break;
			case 'F' : printf("1111");
				break;
			case 'a' : printf("1010");
				break;
			case 'b' : printf("1011");
				break;
			case 'c' : printf("1100");
				break;
			case 'd' : printf("1101");
				break;
			case 'e' : printf("1110");
				break;
			case 'f' : printf("1111");
				break;
			default : printf("\nInvalid hexadecimal digit %c",hex[j]);
		}
		j++;
	}
	}
	return (0);
}
