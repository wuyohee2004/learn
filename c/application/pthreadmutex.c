#include<pthread.h>
#include<stdio.h>


void *func1(void *arg)
{
//	printf("thread num:%lu\n",(unsigned long)pthread_self());
	pthread_mutex_t *lock = arg;
	while(1)
	{
		pthread_mutex_lock(lock);
		printf("%s\n",__func__);
		sleep(1);
		printf("%s\n",__func__);
		pthread_mutex_unlock(lock);
	}
}


void *func2(void *arg)
{
//	printf("thread num:%lu\n",(unsigned long)pthread_self());
	pthread_mutex_t *lock = arg;
	while(1)
	{
		pthread_mutex_lock(lock);
		printf("%s\n",__func__);
		sleep(1);
		printf("%s\n",__func__);
		pthread_mutex_unlock(lock);
	}
}


int main()
{
	pthread_t p1,p2;
	pthread_mutex_t lock;
	pthread_mutex_init(&lock,NULL);

	pthread_create(&p1,NULL,func1,&lock);
	pthread_create(&p2,NULL,func2,&lock);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}

