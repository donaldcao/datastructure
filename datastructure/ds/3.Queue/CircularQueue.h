#ifndef _CIRCULARQUEUE_H
#define _CIRCULARQUEUE_H

#include "..\common.h"

#define MAXQUEUE 100

typedef struct
{
	QElemType *base;
	int front;
	int rear;
}CirQueue;




#endif