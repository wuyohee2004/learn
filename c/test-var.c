#include<stdio.h>

enum BOOL{
	true,
	false
} bool;

union A{
	long a;
	char b;
} u;

struct student{
	int age;
	char *name;
	struct {
		char *course;
		int p;
		};
} s;

void main()
{
printf("%d\n",true);
printf("%d\n",sizeof(long));
printf("int size %d\n",sizeof(int));
printf("short size %d\n",sizeof(short));
printf("char size %d\n",sizeof(char));
printf("bool %d\n",sizeof(bool));

printf("long %d\n",sizeof(long));
printf("union %d\n",sizeof(u));

u.a = 0x12345678;
u.b = 0x33;
printf("%x%x\n",u.a,u.b);
s.age = 15;
s.course = "math";
s.p = 99;
printf("struct %d\n %s\n %d\n",s.age,s.course,s.p);

unsigned int h;
h = 0xff;
h = h & (~(1<<3));
printf("%x \n",h);
h = 0x00;
h = h | (1<<3);
printf("%x \n",h);







}
