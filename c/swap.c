#include<stdio.h>
void swap(int *a,int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void main()
{
	int x=10,y=5;
	printf("x=%d\ny=%d\n",x,y);
	swap(&x,&y);
	printf("x=%d\ny=%d\n",x,y);
}
