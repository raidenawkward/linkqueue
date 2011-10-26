#ifndef _LINKQUEUE_BASE_H
#define _LINKQUEUE_BASE_H

#include <stdlib.h>
#include "linkqueue.h"

/// create new linkqueue, NULL returns if failed
struct LinkQueue* linkqueue_create ();
/// destory existed queue
void linkqueue_destory (struct LinkQueue** queue);
/// clear existed queue and returns node nums be cleared
Int32 linkqueue_clear (struct LinkQueue** queue);
/// create new link queue node, NULL returns if failed
struct linkqueue_node* linkqueue_create_node ();

/// if queue is empty
Boolean linkqueue_is_empty (struct LinkQueue *queue);
/// if count if nodes in queue reaches max_length
Boolean linkqueue_is_full (struct LinkQueue *queue);
/// length of queue
Int32 linkqueue_length (struct LinkQueue *queue);
/// max lengt of queue
Int32 linkqueue_max_length (struct LinkQueue *queue);
/// get front ptr of queue
struct linkqueue_node* linkqueue_front (struct LinkQueue *queue);
/// get rear ptr of queue
struct linkqueue_node* linkqueue_rear (struct LinkQueue *queue);

/// enqueue elem
Boolean linkqueue_enqueue (struct LinkQueue *queue, QueueElement elem);
/// enqueue node
Boolean linkqueue_enqueue_node (struct LinkQueue *queue, struct linkqueue_node *node);
/// dequeue elem
Boolean linkqueue_dequeue (struct LinkQueue *queue, QueueElement *ret);
/// dequeue node
struct linkqueue_node* linkqueue_dequeue_node (struct LinkQueue *queue);

#endif // _LINKQUEUE_BASE_H
