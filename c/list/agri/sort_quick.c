#include "sort.h"

int quick(data_t arr[],int len)
{
	int i,j;
	data_t data;
	i=-1;
	j=0;
	data = arr[len-1];
	while(j<len)
	{
		if(arr[j] <= data)
		{
			i++;
			SWAP(arr[i],arr[j])
		}
		j++;
	}
	return i;
}

void sort_quick(data_t arr[],int len)
{
	if(len < 1)
		return;
	int i = quick(arr,len);
	sort_quick(arr,i);
	sort_quick(arr+i+1,len-i-1);
}

