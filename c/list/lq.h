#include<stdlib.h>
#include<stdio.h>

typedef char data_t;
typedef enum{False,True} BOOL;

struct node
{
	data_t data;
	struct node *next;
};

struct queue
{
	struct node *front;
	struct node *rear;
};


struct queue *queue_create();
BOOL queue_is_empty(struct queue *q);
BOOL enqueue(struct queue *q,data_t data);
BOOL dequeue(struct queue *q,data_t *data);
void queue_destory(struct queue *q);
