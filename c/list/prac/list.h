#include<stdio.h>
#include<stdlib.h>
typedef int data_t;

struct node
{
	data_t data;
	struct node *next;
};

struct node *node_create(data_t data);
struct node *node_insert(struct node *first,data_t data);
struct node *tail(struct node *first,data_t data);
struct node *list_create(int n);
void list_operation(struct node *first,void (*func)(struct node *));
void node_show(struct node *node);
void node_free(struct node *node);
struct node *node_delete(struct node *first,data_t data);
struct node *list_reverse(struct node *frist);
