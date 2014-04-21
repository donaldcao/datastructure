
#include "common.h"

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;


}LNode, *LinkedList;

Status GetElement(LinkedList list, int i, ElemType &e)
{
	LinkedList p;
	int j;

	p = list->next; j = 1;
	while (p&&j < i)
	{
		p = p->next; ++j;
	}

	if (!p || j>i) return ERROR;
	e = p->data;

	return OK;
}