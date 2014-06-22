#include"sort.h"

int main()
{
	data_t arr[N];
	int i;
	srandom(time(NULL));
	for(i=0;i<N;i++)
	{
		arr[i] = random()%100;
		printf("%d ",arr[i]);
	}
	printf("\n");
	//sort_insert(arr,N);
	//sort_binary(arr,N);
	//sort_shell(arr,N);
	//sort_bubble(arr,N);
	//sort_quick(arr,N);
	sort_select(arr,N);
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}

