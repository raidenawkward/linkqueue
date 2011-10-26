#include "linkqueue_operation.h"
#include "linkqueue_base.h"

struct linkqueue_operations* linkqueue_get_operation() {
	struct linkqueue_operations *op = (struct linkqueue_operations*)malloc(sizeof(struct linkqueue_operations));
	if (!op)
		return NULL;

	op->create = linkqueue_create;
	op->destory = linkqueue_destory;
	op->clear = linkqueue_clear;
	op->create_node = linkqueue_create_node;
	op->is_empty = linkqueue_is_empty;
	op->is_full = linkqueue_is_full;
	op->length = linkqueue_length;
	op->max_length = linkqueue_max_length;
	op->front = linkqueue_front;
	op->rear = linkqueue_rear;
	op->enqueue = linkqueue_enqueue;
	op->enqueue_node = linkqueue_enqueue_node;
	op->dequeue = linkqueue_dequeue;
	op->dequeue_node = linkqueue_dequeue_node;

	return op;
}
