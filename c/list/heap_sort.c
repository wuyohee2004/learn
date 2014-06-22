#include "sort.h"
void adjust_heap(data_t arr[],int len,int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int max = i;
	if(l < len && arr[l] > arr[max])
		max = l;
	if(r < len && arr[r] > arr[max])
		max = r;
	if(max != i)
	{
		SWAP(arr[max],arr[i]);
		adjust_heap(arr,len,max);
	}
}

void sort_heap(data_t arr[],int len)
{
	int i = len/2;
	for(;i >= 0; i--)
		adjust_heap(arr,len,i);
	for(i = len - 1; i > 0;i--)
	{
		SWAP(arr[0],arr[i]);
		adjust_heap(arr,i,0);
	}
}

