#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

#define PATH "/tmp/fifo"

int main()
{
	mkfifo(PATH,0664);

	int pid = fork();
	if(pid > 0)
	{
		int fd = open(PATH,O_RDWR);
		char buff[20];
		int index = 1;
		while(1)
		{
			sprintf(buff,"hello world!%d",index++);
			write(fd,buff,sizeof(buff));
			sleep(1);
		}
	}
	else if(pid == 0)
	{
		int fd = open(PATH,O_RDWR);
		char buff[20];
		while(1)
		{
			read(fd,buff,sizeof(buff));
			printf("%s\n",buff);
			sleep(2);
		}
	}
}

