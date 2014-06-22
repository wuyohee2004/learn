#include "list.h"
int main()
{
	srandom(time(NULL));
	int i,x,j,a[]={0,1,2,3,4,5,6,7,8,9};
	struct node *first;

	first = list_create(10);
	list_operation(first,node_show);
	printf("\n");

	first = list_reverse(first);
	list_operation(first,node_show);
	printf("\n");

	printf("start_delete nodes ....\n");
	for(i=0;i < 10;i++ )
	{
//	    x = (int)((10-i)*1.0*random()/(RAND_MAX + 1.0));
		x = random()%(10-i);
		printf("x= %d\n",a[x]);
		first = node_delete(first,a[x]);
		list_operation(first,node_show);
		printf("\n");
		a[x] = a[10-i-1];
		sleep(1);
	}
	printf("end_delete nodes\n");
	
	list_operation(first,node_free);
	list_operation(first,node_show);
	printf("\n");

	return 0;
}
