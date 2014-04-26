
#ifndef _common_h
#define _common_h

typedef int ElemType;
typedef enum Status { OK, ERROR }Status;

typedef struct SqStack
{
	ElemType *head;
	ElemType *top;
	int size; // the memory allocated.
}Stack, PStack;

#endif