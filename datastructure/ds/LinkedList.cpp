
#include "common.h"

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;


}LNode, *LinkedList;

Status GetElement(LinkedList list, int i, ElemType *e);