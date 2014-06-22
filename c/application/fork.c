#include<unistd.h>
#include<stdio.h>

int a = 10;
int main()
{
	int pid = fork();
	if(pid > 0)
		printf("parent %d \n",++a);
	else if(pid == 0)
		printf("child %d \n",++a);
	else
		perror("fork error");
	return 0;
}
// fork once,return twice, first return sub-process,second return process

