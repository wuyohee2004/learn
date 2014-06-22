#include<unistd.h>
#include<stdio.h>
int main()
{
	int pid = fork();
	if(pid>0)
		printf("parent \n");
	else if(pid == 0)
		execl("hello","killme",NULL);
	else
		perror("fork error");

	return 0;
}

