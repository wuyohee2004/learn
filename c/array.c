#include<stdio.h>
#include<string.h>
void main()
{
char a[]={"abcde"};
int i;
//printf("%x",a);


//printf("%x \ %x \ %x\n",a,&a,&a[0]);
//
//printf("%p\ %p \ %p\n",a,&a,&a[0]);
//printf("%d\n",sizeof(a));
//printf("%d\n",strlen(a));
for(i=0;i<=sizeof(a);i++)
{printf("%x\n",a[i]);
}
}
