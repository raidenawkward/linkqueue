#include "linkqueue_base.h"

struct LinkQueue* linkqueue_create () {
	struct LinkQueue *queue = (struct LinkQueue*)malloc(sizeof(struct LinkQueue));
	if (!queue)
		return NULL;

	queue->length = 0;
	queue->max_length = 0;
	queue->front = NULL;
	queue->rear = queue->front;

	return queue;
}

void linkqueue_destory (struct LinkQueue** queue) {
	if (!queue || !*queue)
		return;

	if (!(*queue)->front || !(*queue)->rear)
		goto done;

	struct linkqueue_node *p = (*queue)->front;
	while(p) {
		struct linkqueue_node *node = p;
		p = p->next;
		free(node);
	}
done:
	free(*queue);
}

Int32 linkqueue_clear (struct LinkQueue** queue) {
	if (!queue || !!*queue)
		return;

	if (!(*queue)->front || !(*queue)->rear)
		return;
	Int32 ret = 0;
	struct linkqueue_node *p = (*queue)->front;
	while(p) {
		struct linkqueue_node *node = p;
		p = p->next;
		free(node);
		++ret;
	}

	(*queue)->length = 0;
	(*queue)->front = NULL;
	(*queue)->rear = NULL;

	return ret;
}

struct linkqueue_node* linkqueue_create_node () {
	struct linkqueue_node *node = (struct linkqueue_node*)malloc(sizeof(struct linkqueue_node));
	if (!node)
		return NULL;

	node->next = NULL;

	return node;
}


Boolean linkqueue_is_empty (struct LinkQueue *queue) {
	Boolean ret = true;
	if (!queue)
		return ret;

	if (queue->front != queue->rear || queue->length > 0)
		ret = false;

	return ret;
}

Boolean linkqueue_is_full (struct LinkQueue *queue) {
	Boolean ret = false;
	if (!queue)
		return ret;

	if (queue->length >= queue->max_length)
		ret = true;

	return ret;
}

Int32 linkqueue_length (struct LinkQueue *queue) {
	if (!queue)
		return 0;
	return queue->length;
}

Int32 linkqueue_max_length (struct LinkQueue *queue) {
	if (!queue)
		return 0;
	return queue->max_length;
}

struct linkqueue_node* linkqueue_front (struct LinkQueue *queue) {
	if (!queue)
		return NULL;
	return queue->front;
}

struct linkqueue_node* linkqueue_rear (struct LinkQueue *queue) {
	if (!queue)
		return NULL;
	return queue->rear;
}


Boolean linkqueue_enqueue (struct LinkQueue *queue, QueueElement elem) {
	if (!queue)
		return false;
	struct linkqueue_node *node = linkqueue_create_node();
	if (!node)
		return false;
	node->data = elem;

	Boolean ret = linkqueue_enqueue_node(queue,node);
	if (!ret)
		free(node);

	return ret;
}

Boolean linkqueue_enqueue_node (struct LinkQueue *queue, struct linkqueue_node *node) {
	if (!node || !queue)
		return false;
	if (queue->length >= queue->max_length)
		return false;

	if (queue->length < 0)
		queue->length = 0;

	if (!queue->rear || !queue->length) {
		queue->front = node;
		queue->rear = node;
	}
	else
		node->next = NULL;
	queue->rear->next = node;
	queue->rear = node;
	++queue->length;

	return true;
}

Boolean linkqueue_dequeue (struct LinkQueue *queue, QueueElement *ret) {
	if (!queue)
		return false;
	struct linkqueue_node* front = linkqueue_dequeue_node(queue);
	if (!front)
		return false;
	else {
		*ret = front->data;
		free(front);
	}
	return true;
}

struct linkqueue_node* linkqueue_dequeue_node (struct LinkQueue *queue) {
	if (!queue)
		return NULL;
	if (queue->length <= 0 || !queue->front || !queue->rear)
		return NULL;

	struct linkqueue_node* ret = queue->front;
	queue->front = queue->front->next;
	--queue->length;
	if (queue->length <= 0) {
		queue->length = 0;
		queue->front = NULL;
		queue->rear = NULL;
	}

	return ret;
}
