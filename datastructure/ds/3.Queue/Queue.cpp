
#include <stdlib.h>

#include "queue.h"

Status InitQueue(LinkQueue &q)
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front) exit(ERROR);
	q.front->next = NULL;
	return OK;

}

Status DestroyQueue(LinkQueue &q)
{
	while (q.front)
	{
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}

	return OK;
}

Status ClearQueue(LinkQueue &q)
{
	DestroyQueue(q);
	q.front->next = NULL;
	q.rear = q.front;

	return OK;
}

bool IsEmpty(LinkQueue &q)
{
	return q.front == q.rear;
}

int QueueLength(LinkQueue &q)
{
	return q.rear - q.front;
}

Status GetHead(LinkQueue &q, QElemType &e)
{
	if (!q.front) exit(ERROR);
	e = q.front->data;
	return OK;
}

Status EnQueue(LinkQueue &q, QElemType e)
{
	QueuePtr node = (QueuePtr)malloc(sizeof(QNode));
	if (!node) exit(ERROR);

	node->data = e;
	node->next = NULL;
	q.rear->next = node;
	q.rear = node;

	return OK;
}

Status DeQueue(LinkQueue &q, QElemType &e)
{
	if (IsEmpty(q)) exit(ERROR);
	QueuePtr node = q.front->next;
	e = node->data;
	q.front = node->next;
	if (node == q.rear)q.rear = q.front;
	free(node);
	return OK;
}

Status QueueTraverse(LinkQueue &q, void(*visit)())
{
	QueuePtr node = q.front;
	while (node != q.rear)
	{
		visit();
		node = node->next;
	}

	return OK;
}






















