
#include <stdlib.h>
#include <stdio.h>

#include "common.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10



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
	s.size = STACK_INIT_SIZE;

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
	//s.size=0;

	return OK;
}

bool StackIsEmpty(Stack &s)
{
	return s.head == s.top;
}

int StackLength(Stack &s)
{
	return s.top - s.head;
}

Status GetTop(Stack &s, ElemType &e)
{
	if (s.head==s.top) return ERROR;
	e = *(s.top-1);
	return OK;
}

Status Push(Stack &s, ElemType e)
{
	if (s.size == 0)initStack(s);
	if ((s.top-s.head)>=s.size)
	{
		ElemType *newbase = (ElemType*)realloc(s.head, sizeof(ElemType)*(s.size + STACKINCREMENT));
		if (!newbase)return ERROR;
		s.head = newbase;
		s.top = s.head + s.size;
		s.size += STACKINCREMENT;
	}
	*(s.top++) = e;

	return OK;
}

Status Pop(Stack &s, ElemType &e)
{
	if (s.top==s.head) return ERROR;
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

Stack s;
int n;
int e;
void convert()
{
	initStack(s);
	printf("Please enter the decimal number n: ");
	//char a;
	scanf_s("%d", &n);
	printf("n= %d\n", n);
	while (n)
	{
		Push(s, n % 8);
		n = n / 8;
	}

	while (!StackIsEmpty(s))
	{
		Pop(s, e);
		printf("%d\n", e);
	}

}



