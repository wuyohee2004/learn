#include <stdlib.h>
#include <stdio.h>

typedef char data_t;
typedef enum{False,True} BOOL;

struct queue
{
	int front;
	int rear;
	int len;
	data_t *data;
};


struct queue *queue_create(int len);
BOOL queue_is_empty(struct queue *q);
BOOL queue_is_full(struct queue *q);
BOOL enqueue(struct queue *q,data_t data);
BOOL dequeue(struct queue *q,data_t *data);
void queue_destroy(struct queue *q);
