#include<pthread.h>
#include<stdio.h>

int a=10;

void *func(void *arg)
{
	printf("%d thread num:%lu\n",a++,(unsigned long)pthread_self());
}

int main()
{
	pthread_t p1,p2;
	pthread_create(&p1,NULL,func,NULL);
	pthread_create(&p2,NULL,func,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}

