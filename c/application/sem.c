#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<string.h>
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

void sem_init(int semid,int val)
{
	union semun semunion;
	semunion.val = val;
	semctl(semid,0,SETVAL,semunion);
}

void sem_p(int semid)
{
	struct sembuf sops;
	sops.sem_num = 0;
	sops.sem_op = -1;
	sops.sem_flg = SEM_UNDO;
	semop(semid,&sops,1);
}

void sem_v(int semid)
{
	struct sembuf sops;
	sops.sem_num = 0;
	sops.sem_op = 1;
	sops.sem_flg = SEM_UNDO;
	semop(semid,&sops,1);
}

#define KEY 250
int main()
{
	int semid = semget(KEY,1,IPC_CREAT);
	sem_init(semid,1);
	int pid = fork();
	
	if(pid == 0)
	{
		while(1)
		{
			sem_p(semid);
			printf("child\n");
			sleep(1);
			sem_v(semid);
		}
	}else if(pid > 0)
	{
		while(1)
		{
			sem_p(semid);
			printf("father\n");
			sleep(1);
			sem_v(semid);
		}
	}
}


