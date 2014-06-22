#include<stdio.h>
#include<stdlib.h>

typedef int data_t;

struct node
{
	data_t data;
	struct node *pre;
	struct node *next;
};


struct node *node_create(data_t data); 
struct node *list_create(struct node *node, int n);       
                                                         
void list_operation(struct node *head,void (*func)(struct node *));
void node_free(struct node *node);                        
void node_delete(struct node *head,data_t data);          
struct node *node_insert1(struct node *head,data_t data); 
struct node *node_insert2(struct node *head,data_t data); 
void node_show(struct node *node);
void list_reverse(struct node *head);
