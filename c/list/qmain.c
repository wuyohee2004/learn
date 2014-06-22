#include "q.h"

int main()
{
	char a,*p = "hello";
	struct queue *q;
	q = queue_create(20);
	while(*p)
	{
		enqueue(q,*p);
		p++;
	}
	while(!queue_is_empty(q))
	{
		dequeue(q,&a);
		printf("%c ",a);
	}
	printf("\n");
	return 0;
}

