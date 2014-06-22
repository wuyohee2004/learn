#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int i,x,j,a[]={0,1,2,3,4,5,6,7,8,9};
	srandom(time(NULL));
	for(i=0;i<10;i++)
	{
		x = random()%(10-i);
		printf("rand= %d,x=%d, time=%ld\n",a[x],x,time(NULL));
		a[x] = a[10-i-1];
		for(j=0;j<10;j++)
			printf("%d ",a[j]);
		printf("\n");
	}
}
