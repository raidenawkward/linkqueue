#include "linkqueue_base.h"

struct LinkQueue* linkqueue_create () {
	struct LinkQueue *stack = (struct LinkQueue*)malloc(sizeof(struct LinkQueue));
	if (!stack)
		return NULL;

	stack->length = 0;
	stack->max_length = 0;
	stack->front = NULL;
	stack->rear = stack->front;

	return stack;
}

void linkqueue_destory (struct LinkQueue** stack) {
	if (!stack || !*stack)
		return;

	if (!(*stack)->front || !(*stack)->rear)
		goto done;

	struct linkqueue_node *p = (*stack)->front;
	while(p) {
		struct linkqueue_node *node = p;
		p = p->next;
		free(node);
	}
done:
	free(*stack);
}

Int32 linkqueue_clear (struct LinkQueue** stack) {
	if (!stack || !!*stack)
		return;

	if (!(*stack)->front || !(*stack)->rear)
		return;
	Int32 ret = 0;
	struct linkqueue_node *p = (*stack)->front;
	while(p) {
		struct linkqueue_node *node = p;
		p = p->next;
		free(node);
		++ret;
	}

	(*stack)->length = 0;
	(*stack)->front = NULL;
	(*stack)->rear = NULL;

	return ret;
}

struct linkqueue_node* linkqueue_create_node () {
	struct linkqueue_node *node = (struct linkqueue_node*)malloc(sizeof(struct linkqueue_node));
	if (!node)
		return NULL;

	node->next = NULL;

	return node;
}


Boolean linkqueue_is_empty (struct LinkQueue *stack) {
	Boolean ret = true;
	if (!stack)
		return ret;

	if (stack->front != stack->rear || stack->length > 0)
		ret = false;

	return ret;
}

Boolean linkqueue_is_full (struct LinkQueue *stack) {
	Boolean ret = false;
	if (!stack)
		return ret;

	if (stack->length >= stack->max_length)
		ret = true;

	return ret;
}

Int32 linkqueue_length (struct LinkQueue *stack) {
	if (!stack)
		return 0;
	return stack->length;
}

Int32 linkqueue_max_length (struct LinkQueue *stack) {
	if (!stack)
		return 0;
	return stack->max_length;
}

struct linkqueue_node* linkqueue_front (struct LinkQueue *stack) {
	if (!stack)
		return NULL;
	return stack->front;
}

struct linkqueue_node* linkqueue_rear (struct LinkQueue *stack) {
	if (!stack)
		return NULL;
	return stack->rear;
}


Boolean linkqueue_enqueue (struct LinkQueue *stack, QueueElement elem) {
	if (!stack)
		return false;
	struct linkqueue_node *node = linkqueue_create_node();
	if (!node)
		return false;
	node->data = elem;

	Boolean ret = linkqueue_enqueue_node(stack,node);
	if (!ret)
		free(node);

	return ret;
}

Boolean linkqueue_enqueue_node (struct LinkQueue *stack, struct linkqueue_node *node) {
	if (!node || !stack)
		return false;
	if (stack->length >= stack->max_length)
		return false;

	if (!stack->rear)
		stack->rear = node;
	else
		node->next = stack->front;
	stack->front = node;
	++stack->length;

	return true;
}

Boolean linkqueue_dequeue (struct LinkQueue *stack, QueueElement *ret) {
	if (!stack)
		return false;
	struct linkqueue_node* front = linkqueue_dequeue_node(stack);
	if (!front)
		return false;
	else {
		*ret = front->data;
		free(front);
	}
	return true;
}

struct linkqueue_node* linkqueue_dequeue_node (struct LinkQueue *stack) {
	if (!stack)
		return NULL;
	if (stack->length <= 0 || !stack->front || !stack->rear)
		return NULL;

	struct linkqueue_node* ret = stack->front;
	stack->front = stack->front->next;
	--stack->length;
	if (stack->length <= 0) {
		stack->length = 0;
		stack->front = NULL;
		stack->rear = NULL;
	}

	return ret;
}
