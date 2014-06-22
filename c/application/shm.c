#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>

#define KEY 250

int main()
{
	int id = shmget(KEY,512,IPC_CREAT);
	printf("SHM ID:%d\n",id);
	int pid = fork();
	if(pid == 0)
	{
		int *p = shmat(id,NULL,SHM_RND);
		int index = 0;
		while(1)
		{
			*p = index++;
			p++;
			sleep(1);
		}
		shmdt(p);
	}
	else if(pid > 0)
	{
		int *p = shmat(id,NULL,SHM_RND);
		while(1)
		{
			printf("%d\n",*p);
			p++;
			sleep(2);
		}
		shmdt(p);
	}

	return 0;
}


