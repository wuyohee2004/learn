#include "list.h"
int main()
{
	struct node head;
	head.next=NULL;
	list_create(&head,10);
	printf("list created\n");
	list_operation(&head,node_show);
	printf("\n");

	list_reverse(&head);
	list_operation(&head,node_show);
	printf("\n");

	node_delete(&head,0);
	list_operation(&head,node_show);
	printf("\n");

	list_operation(&head,node_free);
	list_operation(&head,node_show);

	return 0;
}
