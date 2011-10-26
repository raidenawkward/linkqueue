#ifndef _LINKQUEUE_BASE_H
#define _LINKQUEUE_BASE_H

#include <stdlib.h>
#include "linkqueue.h"

/// create new linkqueue, NULL returns if failed
struct LinkQueue* linkqueue_create ();
/// destory existed stack
void linkqueue_destory (struct LinkQueue** stack);
/// clear existed stack and returns node nums be cleared
Int32 linkqueue_clear (struct LinkQueue** stack);
/// create new link stack node, NULL returns if failed
struct linkqueue_node* linkqueue_create_node ();

/// if stack is empty
Boolean linkqueue_is_empty (struct LinkQueue *stack);
/// if count if nodes in stack reaches max_length
Boolean linkqueue_is_full (struct LinkQueue *stack);
/// length of stack
Int32 linkqueue_length (struct LinkQueue *stack);
/// max lengt of stack
Int32 linkqueue_max_length (struct LinkQueue *stack);
/// get front ptr of stack
struct linkqueue_node* linkqueue_front (struct LinkQueue *stack);
/// get rear ptr of stack
struct linkqueue_node* linkqueue_rear (struct LinkQueue *stack);

/// enqueue elem
Boolean linkqueue_enqueue (struct LinkQueue *stack, QueueElement elem);
/// enqueue node
Boolean linkqueue_enqueue_node (struct LinkQueue *stack, struct linkqueue_node *node);
/// dequeue elem
Boolean linkqueue_dequeue (struct LinkQueue *stack, QueueElement *ret);
/// dequeue node
struct linkqueue_node* linkqueue_dequeue_node (struct LinkQueue *stack);

#endif // _LINKQUEUE_BASE_H
