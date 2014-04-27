
#include <stdio.h>
#include <stdlib.h>
#include "..\common.h"

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;


}LNode, *LinkedList;

Status getElement(LinkedList list, int i, ElemType &e)
{
	LinkedList p;
	int j;

	p = list->next; j = 1;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}

	if (!p || j>i) return ERROR;
	e = p->data;

	return OK;
}

Status insert(LinkedList &list, int i, ElemType e)
{
	LinkedList s;
	LinkedList p = list;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i) return ERROR;
	s = (LinkedList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}

Status deleteNode(LinkedList &list, int i, ElemType &e)
{
	LinkedList p = list;
	int j = 0;
	
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}

	if (!p->next || j>i - 1) return ERROR;
	LinkedList q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);

	return OK;
}

// Create a list with totally n elements.
void CreateLinkedList(LinkedList &list, int n)
{
	list = (LinkedList)malloc(sizeof(LNode));
	list->next = NULL;

	LinkedList p = NULL;
	for (int i = n; i > 0; i--)
	{
		p = (LinkedList)malloc(sizeof(LNode));
		if (!p)exit(ERROR);

		//get the input data.
		scanf_s("%d",&p->data);
		p->next = list->next;
		list->next = p;
	}

}

Status mergeLinkedList(LinkedList la, LinkedList lb, LinkedList lc)
{
	LinkedList pa = la->next;
	LinkedList pb = lb->next;
	LinkedList pc = lc;

	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;

		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa ? pa : pb;

	return OK;
}
