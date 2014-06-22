#include "sort.h"
void sort_select(data_t arr[],int len)
{
	int i,j;
	int max;
	for(i = 0;i<len-1;i++)
	{
		max = 0;
		for(j=1;j<len-i;i++)
		{
			if(arr[max] < arr[i])
					max = j;
		}
		if(max != len-i-1)
			SWAP(arr[max],arr[len-i]);
	}
}

