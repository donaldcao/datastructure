#ifndef _QUEUE_H
#define _QUEUE_H

#include "..\common.h"

typedef struct Node
{
	QElemType data;
	struct Node *next;
}QNode, *QueuePtr;

// Linked queue.
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &queue);
Status DestroyQueue(LinkQueue &queue);
Status ClearQueue(LinkQueue &queue);
bool IsEmpty(LinkQueue &queue);
int QueueLength(LinkQueue &queue);
Status GetHead(LinkQueue &queue, QElemType &e);
Status EnQueue(LinkQueue &queue, QElemType e);
Status DeQueue(LinkQueue &queue, QElemType &e);

Status QueueTraverse(LinkQueue &queue, void (*visit)());


#endif