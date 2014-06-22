#include<stdio.h>

typedef int (*FUNC)(int a[]);
void main()
{	void *p;
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int x =0 ;
	int (*pr)[10] = &a;
//	int (*pn)[2] = &a;
	int *ptr1 = (int *)(&a+1);
	int *ptr2 = (int *)((int *)a+1);
	printf("%d,%d\n",ptr1[-1],*ptr2);
//	printf("%d %d\n",*pn[0],*(pn+1)[0]);
	printf("%d\n",sizeof(char *));

	printf("%d\n",sizeof(int *));

	printf("%d\n",sizeof(short *));

	printf("%d\n",sizeof(long *));

	printf("%x\n",(char*)p);

	printf("%x\n",(int*)p);  

	printf("%x\n",(short*)p+2);

	printf("%x\n",(long*)p+2);

	printf("%d\n",((long*)p+2)-(long*)p);

	printf("%p\n%d\n",pr,(*pr)[0]);
	
	pr++;

	printf("%p\n",pr);

	
//	printf("%d\n",*(pr+3));

//	printf("%p\n%p",a,&a);

int show(int a[]);
show(a);
printf("outta func %d\n",sizeof(a));



FUNC fp=show;
x = (*fp)(a);
printf("x is %d\n",x);


}

int show(int a[])	
{	
	printf("inner func %d\n",sizeof(a));
}

