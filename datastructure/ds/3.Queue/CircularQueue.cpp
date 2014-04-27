
#include <stdlib.h>

#include "CircularQueue.h"

Status InitQueue(CirQueue &q)
{
	q.base = (QElemType *)malloc(MAXQUEUE*sizeof(QElemType));
	if (!q.base) exit(ERROR);
	q.front = q.rear= 0;
	return OK;
}

int QueueLength(CirQueue &q)
{
	return (q.rear - q.front + MAXQUEUE) % MAXQUEUE;
}

Status EnQueue(CirQueue &q, QElemType e)
{
	if ((q.rear + 1) % MAXQUEUE == q.front) return ERROR;
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % MAXQUEUE;
	return OK;
}

Status DeQueue(CirQueue &q, QElemType &e)
{
	if (q.front == q.rear) return ERROR;
	e = q.base[q.front];
	q.front = (q.front + 1) % MAXQUEUE;
	return OK;
}

