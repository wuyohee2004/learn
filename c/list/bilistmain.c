#include "bilist.h"

int main()
{
	struct node head;
	list_create(&head,10);
	list_operation(&head,node_show);
	printf("\n");
	node_insert1(&head,20);
	list_operation(&head,node_show);
	printf("\n");
	list_reverse(&head);
	list_operation(&head,node_show);
	printf("\n");
	list_operation(&head,node_free);
	list_operation(&head,node_show);
	printf("\n");
	return 0;
}

