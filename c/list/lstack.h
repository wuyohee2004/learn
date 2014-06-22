#include<stdlib.h>
#include<stdio.h>

typedef char data_t;
typedef enum{False,True} BOOL;

struct node
{
	data_t data;
	struct node *next;
};

struct stack
{
	struct node *sp;
};


struct stack *stack_create();
BOOL stack_is_empty(struct stack *s);
BOOL stack_push(struct stack *s,data_t data);
BOOL stack_pop(struct stack*s,data_t *data);
void stack_destroy(struct stack *s);
