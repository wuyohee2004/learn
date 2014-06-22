#include"sort.h"
void sort_shell(data_t arr[],int len)
{
	int gap,i,j;
	data_t tmp;
	gap = len/2;
	while(gap >= 1)
	{
		for(i=0;i<len-gap;i++)
		{
			tmp = arr[i+gap];
			for(j=i;j>=0 && arr[j] > tmp; j-= gap)
				arr[j+gap] = arr[j];
			arr[j+gap] = tmp;
		}
		gap /= 2;
	}
}
