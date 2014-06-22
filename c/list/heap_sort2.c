#include "sort.h"

void adjust_heap(data_t arr[],int len, int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int top = i;
	if (l < len && arr[l] > arr[top])
		top = l;
	if (r < len && arr[r] > arr[top])
		top = r;
	if (top != i)
	{
		SWAP(arr[top],arr[i]);
		adjust_heap(arr,len,top);
	}
}

void sort_heap(data_t arr[],int len)
{
	int i = len/2;
	for(;i >= 0;i--)
		adjust_heap(arr,len,i);
	for(i = len -1;i>0;i--)
	{
		SWAP(arr[0],arr[i]);
		adjust_heap(arr,i,0);
	}
}




