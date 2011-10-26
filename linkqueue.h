#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

#include "linkqueue_define.h"

struct linkqueue_node {
	QueueElement data;
	struct linkqueue_node *next;
};

struct LinkQueue {
	Int32 length;
	Int32 max_length;
	struct linkqueue_node *front;
	struct linkqueue_node *rear;
};

struct linkqueue_operations {
	struct LinkQueue* (*create) (void);
	void (*destory) (struct LinkQueue** queue);
	Int32 (*clear) (struct LinkQueue** queue);
	struct linkqueue_node* (*create_node) (void);

	Boolean (*is_empty) (struct LinkQueue *queue);
	Boolean (*is_full) (struct LinkQueue *queue);
	Int32 (*length) (struct LinkQueue *queue);
	Int32 (*max_length) (struct LinkQueue *queue);
	struct linkqueue_node* (*front) (struct LinkQueue *queue);
	struct linkqueue_node* (*rear) (struct LinkQueue *queue);

	Boolean (*enqueue) (struct LinkQueue *queue, QueueElement elem);
	Boolean (*enqueue_node) (struct LinkQueue *queue, struct linkqueue_node *node);
	Boolean (*dequeue) (struct LinkQueue *queue, QueueElement *ret);
	struct linkqueue_node* (*dequeue_node) (struct LinkQueue *queue);
};

#endif // _LINKQUEUE_H
