#include<stdio.h>
void main()
{
	struct A
	{	int a;
		char b;
	};
struct A a;
printf("%d\n",sizeof(struct A));

	struct A1
	{	int a;
		struct B
		{	int b;
			int c;
		}b;
	}a1;
printf("%d\n",a1.b.c);






}
