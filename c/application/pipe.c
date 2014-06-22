#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd[2];
	pipe(fd);
	int pid = fork();
	if(pid == 0)
	{
		char buff[20];
		int index = 1;
		while(1)
		{
			sprintf(buff,"hello world%d",index++);
			write(fd[1],buff,sizeof(buff));
			sleep(1);
		}
	}
	else if(pid > 0)
	{
		char buff[20];
		while(1)
		{
			read(fd[0],buff,sizeof(buff));
			printf("%s\n",buff);
			sleep(2);
		}
	}
	return 0;
}
