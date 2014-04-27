
#ifndef _common_h
#define _common_h

typedef int ElemType;
typedef int QElemType;

typedef enum eStatus { OK, ERROR }Status;

typedef struct SqStack
{
	ElemType *head;
	ElemType *top;
	int size; // the memory allocated.
}Stack, PStack;

#endif