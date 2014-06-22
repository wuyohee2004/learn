#include "q.h"

struct queue *queue_create(int len)
{
	struct queue *q;
	q = malloc(sizeof(*q));
	q->front = 0;
	q->rear = 0;
	q->len = len;
	q->data = malloc(len*sizeof(*q->data));
}

BOOL queue_is_empty(struct queue *q)
{
	return q->front == q->rear ? True:False;
}

BOOL queue_is_full(struct queue *q)
{
	return ((q->rear)+1)%(q->len) == q->front ? True:False;
}

BOOL enqueue(struct queue *q,data_t data)
{
	if(queue_is_full(q))
		return False;
	q->data[q->rear] = data;
	q->rear++;
	q->rear%=q->len;
	return True;
}

BOOL dequeue(struct queue *q,data_t *data)
{
	if(queue_is_empty(q))
		return False;
	*data = q->data[q->front++];
	q->front %= q->len;
	return True;
}

void queue_destroy(struct queue *q)
{
	free(q->data);
	free(q);
}


