
#include <stdlib.h>
#include "..\common.h"

typedef int ElemType;
typedef struct DoubleNode
{
	ElemType data;
	struct DoubleNode *prior;
	struct DoubleNode *next;
}DNode, *DLinkedList;


DNode * getElemPosition(DLinkedList &head, int i)
{
	int j = 0;

	// Issue: circulate double linked list.
	while (!head && j < i)
	{
		head = head->next;
	}

	return head;
}

Status insert(DLinkedList &list, int i, ElemType e)
{
	DLinkedList p;
	if (!(p = getElemPosition(list, i))) return ERROR;

	DLinkedList s = (DLinkedList)malloc(sizeof(DNode)); 
	if (!s)return ERROR;

	s->data = e;
	p->prior->next = s;
	s->prior = p->prior;
	s->next = p;
	p->prior = s;	

	return OK;
}

Status deleteElem(DLinkedList &list, int i, ElemType &e)
{
	DLinkedList p;
	p = getElemPosition(list, i);
	if (!p) return ERROR;

	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;

	free(p);
	return OK;
}

