#include "list.h"

struct node *node_create(data_t data)
{
	struct node *node;
	node = malloc(sizeof(*node));
	if ( node == NULL)
	{
		perror("malloc fail");
		return node;
	}
	node->data = data;
	node->next = NULL;
	
	return node;
}

struct node *node_insert(struct node *first,data_t data)
{
	struct node *node,*tmp;
	node = node_create(data);
	if(!first)
		return node;
	tmp = first;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = node;

	return first;
}

struct node *list_create(int n)
{
	data_t i;
	struct node *first=NULL;
	for(i=0;i<n;i++)
		first = node_insert(first,i);
	return first;
}

struct node *node_delete(struct node *first,data_t data)
{
	struct node *tmp,*node=first;
	if(node->data == data)
	{
		first = first->next;
		free(node);
		return first;
	}
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

	return first;
}


struct node *list_reverse(struct node *first)
{
	struct node *cur=first,*next,*pre=NULL;
	while(cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

void list_operation(struct node *first,void (*func)(struct node *))
{
	struct node *tmp=first;
	while(tmp)
	{
		func(tmp);
		tmp = tmp->next;
	}
}

void node_show(struct node *node)
{
	printf("%x ",node->data);
}

void node_free(struct node *node)
{
	free(node);
}

