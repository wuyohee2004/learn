#include<stdio.h>
#include<stdlib.h>

typedef char data_t;

typedef enum
	{
		False,True
	} BOOL;

struct stack
{
	int sp;
	int len;
	data_t *data;
};

struct stack *stack_create(int len);
void stack_destory(struct stack *s);
BOOL stack_is_full(struct stack *s);
BOOL stack_push(struct stack *s,data_t data);
BOOL stack_is_empty(struct stack *s);
BOOL stack_pop(struct stack *s,data_t *data);
