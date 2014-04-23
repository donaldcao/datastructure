
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int ElemType;
typedef enum { OK, ERROR }Status;

typedef struct SqStack
{
	ElemType *head;
	ElemType *top;
	int size;
	int capacity;
}Stack, PStack;

Status initStack(Stack&);
Status DestroyStack(Stack&);
Status ClearStack(Stack&);
bool StackIsEmpty(Stack&);
int StackLength(Stack&);
Status GetTop(Stack&, ElemType&);
Status Push(Stack&, ElemType e);
Status Pop(Stack&, ElemType &e);
Status StackTraverse(Stack&, bool(*visit)());

Status initStack(Stack & s)
{
	ElemType *newbase = (ElemType *)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
	if (!newbase)
		exit(ERROR);
	s.head = s.top = newbase;
	s.size = 0;
	s.capacity = STACK_INIT_SIZE;

	return OK;
}

Status DestroyStack(Stack &s)
{
	if (s.size > 0)
	{
		ElemType *p;
		while (s.top != s.head)
		{
			p = --s.top;
			free(p);
		}
		s.head = s.top = NULL;
		s.size = 0;
		return OK;
	}
	else
	{
		exit(ERROR);
	}
}

Status ClearStack(Stack &s)
{
	s.top = s.head;
	s.size=0;

	return OK;
}

bool StackIsEmpty(Stack &s)
{
	return s.head == s.top;
}

int StackLength(Stack &s)
{
	return s.size;
}

Status GetTop(Stack &s, ElemType &e)
{
	if (s.size == 0) return ERROR;
	e = *(s.top-1);
	return OK;
}

Status Push(Stack &s, ElemType e)
{
	if (s.head == s.top) return initStack(s);
	if (s.size >= s.capacity)
	{
		ElemType *newbase = (ElemType*)realloc(s.head, sizeof(ElemType)*(s.capacity + STACKINCREMENT));
		if (!newbase)return ERROR;
		s.head = newbase;
		s.capacity = s.capacity + STACKINCREMENT;
		*(s.top++) = e;
	}
	return OK;
}

Status Pop(Stack &s, ElemType &e)
{
	if (!s.top) return ERROR;
	e = *(--s.top);
	return OK;
}

Status StackTraverse(Stack &s, bool(*visit)())
{
	if (s.head == NULL) return ERROR;
	ElemType *p = s.head;
	while (p++ != s.top)
	{
		(*visit)();
	}
	return OK;
}






