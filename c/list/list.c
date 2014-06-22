#include "list.h"
struct node *node_create(data_t data)
{
	struct node *node;
	node = malloc(sizeof(*node));
	if(node == NULL)
	{
		perror("malloc failure");
		return node;
	}

	node->data = data;
	node->next = NULL;
	return node;
}

struct node *node_insert(struct node *first,data_t data)
{
	struct node *node;
	node = node_create(data);
	node->next = first;
	return node;
}

struct node *tail(struct node *first,data_t data)
{
	struct node *node,*tmp;
	node = node_create(data);
	if(!first)
		return node;
	tmp = first;
	while(tmp->next);
		tmp = tmp->next;
	tmp->next = node;
	return first;
}

struct node *list_create(int n)
{
	int i;
	struct node *first = NULL;
	for(i=0;i<n;i++)
		first = node_insert(first,i);
	return first;
}

struct node *list_operation(struct node *first,void (*func)(struct node *))
{
	struct node *next,*tmp = first;
	while(first)
	{
		func(first);
		first = first->next;
	}

	return tmp;
}

void node_show(struct node *node)
{
	printf("%d ",node->data);
}

void node_free(struct node *node)
{
	free(node);
}

struct node *node_delete(struct node *first,data_t data)
{
	struct node *node=first, *tmp;
	if(data == node->data)
	{
		first = first->next;
		free(node);
		return first;
	}

	while (node->next)
	{
		if(data == node->next->data)
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
	struct node *pre,*cur,*next;
	pre = NULL;
	cur = first;
	while (cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
















