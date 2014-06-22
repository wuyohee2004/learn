#include<stdio.h>
void main(void)
{
int a = 10,b =5;

int i,sum;

if (a > b){
	printf("if loop %d\n",a);
	}else{
		printf("if loop %d\n",b);
	}
switch(a)
{
	case 1:
		printf("case loop a=1\n");
		break;
	case 2:
		printf("case loop a=2\n");
		break;
	case 3 ... 100:
		printf("case loop a is bigger number\n");
		break;
	default:
		printf("case loop no input\n");
		break;
}
i=1;
sum=0;
for (i=1;i<=100;i++){
	sum += i;
}
printf ("for loop sum= %d\n",sum);
sum = 0;
i = 1;
while(i<=100){
	sum += i;
	i++;
	}
printf ("while loop sum= %d\n",sum);

sum = 0;
i =1;

do {
	sum += i;
	i++;
}while(i<=100);
printf ("do while loop sum=%d\n",sum);

sum = 0;
i = 1;
L1:
sum += i;
i++;
if (i<=100){
	goto L1;
}


printf ("goto loop sum=%d\n",sum);

}


