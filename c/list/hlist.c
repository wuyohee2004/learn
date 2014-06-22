#include "list.h"

struct node *node_create(data_t data)
{
	struct node *node;
	node = malloc(sizeof(*node));
	node->data = data;
	node->next = NULL;
	return node;
	
}

void node_insert(struct node *head,data_t data)
{
	struct node *node;
	node = node_create(data);
	node->next = head->next;
	head->next = node;
}

void list_create(struct node *head,int n)
{
	int i;
	for(i=0;i<n;i++)
		node_insert(head,i);
}

void list_operation(struct node *head,void (*func)(struct node *))
{
	struct node *node,*next;
	node = head->next;
	while(node)
	{
		next = node->next;
		func(node);
		node = next;
	}
}

void node_show(struct node *node)
{
	printf("%d ",node->data);
}

void node_free(struct node *node)
{
	free(node);
}

void node_delete(struct node *head,data_t data)
{
	struct node *node,*tmp;
	node = head;
	while(node->next)
	{
		if(node->next->data == data)
		{
			tmp = node->next;
			node->next = tmp->next;
			free(tmp);
			break;
		}

		node = node->next;
	}
}

void list_reverse(struct node *head)
{
	struct node *cur=head->next,*next,*pre=NULL;
	while(cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	head->next = pre;
}






