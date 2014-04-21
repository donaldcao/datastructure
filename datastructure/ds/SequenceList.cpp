#include <stdlib.h>
#include <stdio.h>

#include "common.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

///////////////////////////////////////////////////
///////        Ëæ»ú´æÈ¡ O(n)Ìí¼ÓÉ¾³ý
//////////////////////////////////////////////////

typedef struct List
{
	ElemType *Elem;
	int count;
	int capacity;
}SequenceList;

Status init(SequenceList &list);
Status insertElem(SequenceList & list, int i, ElemType e);
Status deleteElem(SequenceList & list, int i, ElemType &e);
int findElem(SequenceList & list, ElemType e);

int main()
{
	return 0;
}


Status init(SequenceList &list)
{
	list.Elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!list.Elem) exit(ERROR);

	return OK;
}

// i is the location to insert the element e, from 1.
Status insertElem(SequenceList &list, int i, ElemType e)
{
	if (list.Elem == NULL) exit(ERROR);

	ElemType *p;
	ElemType *q;
	ElemType *newbase=NULL;

	if (i<1 || i>list.capacity + 1)
	{
		printf("%s\n", "location out of range");
		exit(ERROR);
	}


	if (list.count >= list.capacity) 
		newbase = (ElemType *)realloc(list.Elem, (list.capacity + LISTINCREMENT)*sizeof(ElemType));
	if (!newbase)
	{
		printf("%s\n", "overflow when try to get new memory for list.Elem");
		exit(ERROR);
	}
	else
	{
		list.Elem = newbase;
	}

	q = list.Elem + list.count - 1;
	p = list.Elem + i - 1;
	for (; q >= p; q--)
	{
		*(q + 1) = *q;
	}

	*p = e;
	list.count++;

	return OK;
}

Status deleteElem(SequenceList &list, int i, ElemType &e)
{
	if (list.Elem == NULL) exit(ERROR);

	if (i<1 || i>list.count) exit(ERROR);
	e = list.Elem[i - 1];
	for (ElemType *p = list.Elem + i; p <= list.Elem + list.count - 1; p++)
	{
		*(p - 1) = *p;
	}

	list.count--;

	return OK;
}

// return the element index in the array.
int findElem(SequenceList & list, ElemType e)
{
	if (list.Elem == NULL)exit(ERROR);
	ElemType *index = list.Elem;
	while (*index!=e && index<=list.Elem+list.count-1) index++;
	if (index > list.Elem + list.count - 1)
		return -1;
	return index - list.Elem;
}

