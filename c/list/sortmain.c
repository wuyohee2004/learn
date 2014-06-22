#include "sort.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	data_t arr[N];
	int i;
	srandom(time(NULL));
	for(i=0;i<N;i++)
		arr[i] = random()%100;

	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");


//	sort_heap(arr,sizeof(arr)/sizeof(arr[0]));	
	merge_it(arr,sizeof(arr)/sizeof(arr[0]));

	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
