#include "sort.h"

void sort_insert(data_t arr[],int len)
{
	int i,j;
	data_t tmp;
	for(i=1;i<len;i++)
	{
		tmp = arr[i];
		for(j = i-1;j>=0; j--)
		{
			if(arr[j] < tmp)
				break;
			arr[j+1] = arr[j];
		}
		arr[j+1] = tmp;
	}
}
