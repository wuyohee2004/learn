#include "bilist.h"

struct node *node_create(data_t data)
{
	struct node *node;
	node = malloc(sizeof(*node));
	node->data = data;
	node->pre = NULL;
	node->next = NULL;
	
	return node;
}

struct node *node_insert1(struct node *head,data_t data)
{
	struct node *node;
	node = node_create(data);
	node->next = head->next;
	node->pre = head;
	head->next->pre = node;
	head->next = node;
	return head;
}

struct node *node_insert2(struct node *head,data_t data)
{
	struct node *node,*last;
	node = node_create(data);
	last = head->pre;
	node->next = head;
	node->pre=last;
	last->next = node;
	head->pre = node;
	return head;
}

struct node *list_create(struct node *head, int n)
{
	int i;
	head->next=head;
	head->pre=head;
	for(i=0;i<10;i++)
		node_insert1(head,i);
}

void list_operation(struct node *head,void (*func)(struct node *))
{
	struct node *node,*next;
	node = head->next;
	while(node!=head)
	{
		next=node->next;
		func(node);
		node=next;
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
	struct node *node;
	node = head->next;
	while(node != head)
	{
		if(node->data == data)
		{
			node->pre->next = node->next;
			node->next->pre = node->pre;
			free(node);
		}
		node = node->next;
	}
}

void list_reverse(struct node *head)
{
	struct node *pre=head,*cur=head->next,*next,*tmp;
	tmp = head->next;
	while(cur != head)
	{
		next = cur->next;
		cur->next = pre;
		cur->pre = next;
		pre = cur;
		cur = next;
	}
	head->next = pre;
	head->pre = tmp;
}




