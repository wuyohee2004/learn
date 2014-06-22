#include "lq.h"

struct queue *queue_create()
{
	struct queue *q;
	q = malloc(sizeof(*q));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

BOOL queue_is_empty(struct queue *q)
{
	return q->front == NULL ? True:False;
}

BOOL enqueue(struct queue *q,data_t data)
{
	struct node *node;
	node = malloc(sizeof(*node));
	node->data = data;
	if(queue_is_empty(q))
	{
		q->front = node;
	}
	else
	{
		q->rear->next = node;
	}
	q->rear = node;
	return True;
}

BOOL dequeue(struct queue *q,data_t *data)
{
	struct node *node;
	if(queue_is_empty(q))
		return False;
	node = q->front;
	*data = node->data;
	if(q->front == q->rear)
	{
		q->front = NULL;
		return True;
	}
	else
		q->front = node->next;
	free(node);

	return True;
}

void queue_destory(struct queue *q)
{
	struct node *node,*next;
	node = q->front;
	while(node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(q);
}


