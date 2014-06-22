#include <stdio.h>
int max(int arr[],size_t s);
int main()
{
	int arr[] = {3,2,8,6,9,4,0};
	printf("max = %d\n",max(arr,sizeof(arr)/sizeof(arr[0])));
}


