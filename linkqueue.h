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
	void (*destory) (struct LinkQueue** stack);
	Int32 (*clear) (struct LinkQueue** stack);
	struct linkqueue_node* (*create_node) (void);

	Boolean (*is_empty) (struct LinkQueue *stack);
	Boolean (*is_full) (struct LinkQueue *stack);
	Int32 (*length) (struct LinkQueue *stack);
	Int32 (*max_length) (struct LinkQueue *stack);
	struct linkqueue_node* (*front) (struct LinkQueue *stack);
	struct linkqueue_node* (*rear) (struct LinkQueue *stack);

	Boolean (*enqueue) (struct LinkQueue *stack, QueueElement elem);
	Boolean (*enqueue_node) (struct LinkQueue *stack, struct linkqueue_node *node);
	Boolean (*dequeue) (struct LinkQueue *stack, QueueElement *ret);
	struct linkqueue_node* (*dequeue_node) (struct LinkQueue *stack);
};

#endif // _LINKQUEUE_H
