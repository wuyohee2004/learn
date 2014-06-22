#include<stdio.h>
int asph(int max)
{
	int i,sum,tmp;
	for (i=100;i<=max;i++)
	{	tmp = i;
		sum = 0;
		for (;tmp>0;tmp/=10)
		{	int a = tmp%10;
			sum += a*a*a;
		}
		if (sum ==i)
		{	printf("%d\n",i);
		}
	}
}

void main()
{
	int max=100;
	printf("please input a max seraching number,great than 100:");
	scanf("%d",&max);
	asph(max);
}
