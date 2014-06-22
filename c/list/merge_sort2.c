#include "sort.h"
void merge(data_t a1[],int len1,data_t a2[],int len2,data_t arr[])
{
	int i,j,k;
	i = j = k =0;
	data_t tmp[len1+len2];
	while (i < len1 && j < len2)
	{
		if(a1[i] < a2[j])
			tmp[k++] = a1[i++];
		else
			tmp[k++] = a2[j++];
	}
	
	while(i < len1)
		tmp[k++] = a1[i++];
	while(j < len2)
		tmp[k++] = a2[j++];
	for(k--;k>=0;k--)
		arr[k] = tmp[k];
}

void merge_re(data_t arr[],int len)
{
	if(len <=1)
		return;
	int l = len/2;
	merge_re(arr,l);
	merge_re(arr+l,len-l);
	merge(arr,l,arr+l,len-l,arr);
}

void merge_it(data_t arr[],int len)
{
	int gap,i;
	gap = 1;
	
	while(gap < len)
	{
		for(i=0;i < len - 2*gap;i+=2*gap)
			merge(arr+i,gap,arr+i+gap,gap,arr+i);
		if(len-i > gap)
			merge(arr+i,gap,arr+i+gap,len-i-gap,arr+i);
		
		gap *=2;
	}
}







