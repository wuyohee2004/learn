#include "stack.h"

int main()
{
	struct stack *s;
	char *p = "hello";
	char a;
	s = stack_create(20);
	while(*p)
	{
		stack_push(s,*p);
		p++;
	}
	while(!stack_is_empty(s))
	{
		stack_pop(s,&a);
		printf("%c",a);
	}
	printf("\n");
}

