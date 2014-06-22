#include "lq.h"

int main()
{
	char a,c,d,e,*p = "HELLO";
	char *o="testing in the middle",*n="hello,world",*m=p;
	struct queue *q;
	q = queue_create();
	printf("first:q->front = %p, q->rear = %p\n",q->front,q->rear);
	while(*p)
	{
		enqueue(q,*p);
		printf("enq:q->front = %p, q->rear = %p\n",q->front,q->rear);
		p++;
	}
	while(!queue_is_empty(q))
	{
		dequeue(q,&a);
		printf("deq:q->front = %p, q->rear = %p\n",q->front,q->rear);
		printf("%c ",a);
	}
	printf("************************************************\n");
	while(*o)
	{
		enqueue(q,*o);
		printf("enq:q->front = %p, q->rear = %p\n",q->front,q->rear);
		o++;
	}
	while(!queue_is_empty(q))
	{
		dequeue(q,&c);
		printf("enq:q->front = %p, q->rear = %p\n",q->front,q->rear);
		printf("%c ",c);
	}
	printf("\n");
	while(*n)
	{
		enqueue(q,*n);
		printf("enq:q->front = %p, q->rear = %p\n",q->front,q->rear);
		n++;
	}
	while(!queue_is_empty(q))
	{
		dequeue(q,&d);
		printf("enq:q->front = %p, q->rear = %p\n",q->front,q->rear);
		printf("%c ",d);
	}
	printf("\n");
	return 0;
}

