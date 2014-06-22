#include "stack.h"

struct stack *stack_create(int len)
{
	struct stack *s;
	s = malloc(sizeof(*s));
	s->sp = 0;
	s->len = len;
	s->data = malloc(len*sizeof(*s->data));
	return s;
}

void stack_destory(struct stack *s)
{
	free(s->data);
	free(s);
}

BOOL stack_is_full(struct stack *s)
{
	return s->sp == s->len ? True : False;
}

BOOL stack_push(struct stack *s,data_t data)
{
	if(stack_is_full(s))
		return False;
	s->data[s->sp] = data;
	s->sp++;
	return True;
}

BOOL stack_is_empty(struct stack *s)
{
	return s->sp == 0 ? True : False;
}

BOOL stack_pop(struct stack *s,data_t *data)
{
	if(stack_is_empty(s))
		return False;
	s->sp--;
	*data = s->data[s->sp];
	return True;
}


