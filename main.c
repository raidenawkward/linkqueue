#include <stdio.h>
#include "linkqueue.h"
#include "linkqueue_operation.h"

int main() {
	struct linkqueue_operations *op = linkqueue_get_operation();
	if (!op)
		return 1;

	struct LinkQueue *queue = op->create();
	if (!queue)
		goto done;

	queue->max_length = 3;
	op->enqueue(queue,1);
	op->enqueue(queue,2);
	op->enqueue(queue,3);
	op->enqueue(queue,4);
	printf("length : %d\n",op->length(queue));

	Int32 num;
	op->dequeue(queue,&num);
	printf("dequeueing : %d\n",num);
	printf("length : %d\n",op->length(queue));
	op->dequeue(queue,&num);
	printf("dequeueing : %d\n",num);
	printf("length : %d\n",op->length(queue));
	op->dequeue(queue,&num);
	printf("dequeueing : %d\n",num);
	printf("length : %d\n",op->length(queue));
	op->dequeue(queue,&num);
	printf("dequeueing : %d\n",num);
	printf("length : %d\n",op->length(queue));

done:
	op->destory(&queue);
	free(op);
	return 0;
}
