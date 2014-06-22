#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

struct sem
{
	sem_t sem1;
	sem_t sem2;
};

int a=10;

void *func1(void *arg)
{
	struct sem *sem = arg;
	while(1)
	{
		sem_wait(&sem->sem1);//P()operation
		printf("%s\n",__func__);
		sleep(1);
		printf("%s\n",__func__);//V()operation
		sem_post(&sem->sem2);
	}
}


void *func2(void *arg)
{
	struct sem *sem = arg;
	while(1)
	{
		sem_wait(&sem->sem2);
		printf("%s\n",__func__);
		sleep(1);
		printf("%s\n",__func__);
		sem_post(&sem->sem1);
	}
}

int main()
{
	pthread_t p1,p2;
	struct sem sem;
	sem_init(&sem.sem1,0,1);
	sem_init(&sem.sem2,0,0);
	pthread_create(&p1,NULL,func1,&sem);
	pthread_create(&p2,NULL,func2,&sem);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}


