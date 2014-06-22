#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int test(int *arr,int len)
{
	int max=arr[0],i;
	
	for (i=1;i < len;i++)
	{if(max<arr[i])
		{max=arr[i];};
	}
	return max;
}


void main(void)
{
	int arr[100],max=0,i=0,n;
	memset(arr,0,sizeof(arr));
	while (1)
	{	printf("please input the number(input 0 to quite):");
		scanf("%d",&n);
		if (n==0)
		{break;}
		arr[i] = n;
		i++;
	}
	printf("arr = %d\n",sizeof(arr));
	max = test(arr,sizeof(arr)/sizeof(arr[0]));
	printf("the maxium number is %d\n",max);
}
	
