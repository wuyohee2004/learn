#include"sort.h"
int search(data_t arr[], int len,data_t data)
{
	int l=0,r=len-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(arr[mid] < data)
			l = mid+1;
		else
			r = mid-1;
	}

	return l;
}

void sort_binary(data_t arr[],int len)
{
	int i,j,tmp,index;
	for(i=1;i < len; i++)
	{
		tmp = arr[i];
		index = search(arr,i,tmp);
		for(j=i-1;j >= index;j--)
			arr[j+1] = arr[j];
		arr[index] = tmp;
	}
}
