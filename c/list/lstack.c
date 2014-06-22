#include "lstack.h"

struct stack *stack_create()
{
	struct stack *s;
	s = malloc(sizeof(*s));
	s->sp = NULL;
	return s;
}

BOOL stack_is_empty(struct stack *s)
{
	return s->sp ==NULL ? True:False;
}

BOOL stack_push(struct stack *s,data_t data)
{
	struct node *node;
	node = malloc(sizeof(*node));
	node->data = data;
	node->next = s->sp;
	s->sp = node;
}

BOOL stack_pop(struct stack*s,data_t *data)
{
	struct node *node;
	if(stack_is_empty(s))
		return False;
	node = s->sp;
	*data = s->sp->data;
	s->sp = node->next;
	free(node);
	return True;
}

void stack_destroy(struct stack *s)
{
	struct node *node = s->sp;
	struct node *next;
	while(node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(s);
}
