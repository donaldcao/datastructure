
#include <stdlib.h>
#include "common.h"

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;

}*Node, *Position;

typedef struct
{
	Node head, tail;
	int len;
}LinkedList;

Status MakeNode(Node &p, ElemType e);
void FreeNode(Node &p);
Status InitList(LinkedList &list);
Status DestoryList(LinkedList &list);
Status ClearList(LinkedList &list);
Status InsertFirst(Node head, Node s);
Status DeleteFirst(Node head, Node &q);
Status Append(LinkedList &list, Node node);
Status Remove(LinkedList &list, Node &q);
// Insert new node s before node p.
Status InsertBefore(LinkedList &list, Node &p, Node s);
// Insert new node s after node p
Status InsertAfter(LinkedList &list, Node &p, Node s);
Status SetCurElem(Node &node, ElemType e);
ElemType GetCurElem(Node &node);
bool ListIsEmpty(LinkedList &list);
int ListLength(const LinkedList &list);
Node GetHead(const LinkedList &list);
Node GetLast(LinkedList &list);
Node PriorPos(LinkedList &list, Node p);
Node NextPos(LinkedList &list , Node p);
// Locate the pointer for the ith element in this linkedlist.
Status LocatePos(LinkedList list, int i, Node &p);
Status LocateElem(LinkedList &list, ElemType e, Status (*compare)(ElemType, ElemType));
Status ListTraverse(LinkedList list, Status(*visit)());

Status MakeNode(Node &p, ElemType e)
{
	p = (Node)malloc(sizeof(ElemType));
	if (!p) return ERROR;
	p->data = e;

	return OK;
}

void FreeNode(Node &p)
{
	free(p);
}

Status InitList(LinkedList &list)
{
	list.head = NULL;
	list.tail = NULL;
	list.len = 0;

	return OK;
}

Status DestoryList(LinkedList &list)
{
	Node p;
	for (; list.head != list.tail; list.head = list.head->next)
	{
		p = list.head->next;
		list.head->next = p->next;
		free(p);
		list.len--;
	}

	return OK;
}

Status ClearList(LinkedList &list)
{
	DestoryList(list);

	return OK;
}

Status InsertFirst(LinkedList &list, Node s)
{
	Node head = list.head;
	if (head->next == NULL) head->next = s;
	else
	{
		Node p = head->next;
		head->next = s;
		s->next = p;
	}

	list.len++;

	return OK;
}

Status Append(LinkedList &list, Node node)
{
	list.tail->next = node;
	list.tail = node;
	list.len++;


	return OK;
}

// Remove the last element in the linkedlist .
Status Remove(LinkedList &list, Node &node)
{
	if (list.head == list.tail)return ERROR;

	node = list.tail;
	Node p = list.tail;
	while (p->next!=list.tail)
	{
		p = p->next;
	}
	list.tail = p;
	list.len--;

	return OK;
}

Status InsertBefore(LinkedList &list, Node &p, Node s)
{
	Node head = list.head;
	if (!p) return ERROR;
	while (head->next != p)
		head = head->next;
	head->next = s;
	s->next = p;
	p = s;
	list.len++;
	return OK;
}

Status InsertAfter(LinkedList &list, Node &p, Node s)
{
	Node tmp = p->next;
	p->next = s;
	s->next = tmp;

	list.len++;
	return OK;
}
Status SetCurElem(Node &node, ElemType e)
{
	if (!node)return ERROR;
	node->data = e;
	return OK;
}

ElemType GetCurElem(Node &node)
{
	if (!node)return ERROR;
	return node->data;
}

bool ListIsEmpty(const LinkedList &list)
{
	return list.len == 0;
}

int ListLength(const LinkedList &list)
{
	return list.len;
}

Node GetHead(const LinkedList &list)
{
	return list.head;
}

Node GetLast(LinkedList &list)
{
	return list.tail;
}

Node PriorPo(LinkedList &list, Node p)
{
	if (!p) return NULL;
	Node tmp = list.head;
	while (tmp->next != p && tmp)
		tmp = tmp->next;
	
	return tmp;
}

Node NextPos(LinkedList &list, Node p)
{
	if (!p) return NULL;
	return p->next;
}

Status LocatePos(LinkedList &list, int i,  Node &p)
{
	Node head = list.head;
	int j = 0;
	while (head && j < i)
	{
		head = head->next;
		j++;
	}
	if (!head) p = NULL;
	if (j == i) p = head;

	return OK;
}

Status LocateElem(LinkedList &list, ElemType e, Status(*compare)(ElemType, ElemType))
{
	for (Node p = list.head; p != list.tail; p = p->next)
	{
		if (OK == (*compare)(e, p->data))
			return OK;
	}

	return ERROR;
}

Status ListTraverse(LinkedList &list, Status(*visit)())
{
	for (Node p = list.head; p != list.tail; p = p->next)
	{
		visit();
	}
	return OK;
}
