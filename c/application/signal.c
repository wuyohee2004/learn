#include<signal.h>
#include<stdio.h>

void handler(int a)
{
	printf("hello %d\n",a);
}

int main()
{
	signal(2,handler);
	while(1);
}


