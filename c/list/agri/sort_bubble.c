#include"sort.h"

void sort_bubble(data_t arr[],int len)
{
	int i=len,j;
	while(i>0)
	{
		for(j=0;j<=i-1;j++)
		{
			if(arr[j+1] < arr[j])
				SWAP(arr[j],arr[j+1]);
		}
		i--;
	}
}

