#include<stdio.h>
int num(int val)
{
	int n=0;
	while (val > 0)
	{	n = n*10+val%10;
		val /= 10;
	}
	printf ("%d\n",n);
}

void main()
{
	int n=0;
	printf("please input a interge:");
	scanf("%d",&n);
	num(n);
}
