
#ifndef _LIST_H_
#define _LIST_H_

#include "..\common.h"

typedef int AtomType;
typedef enum{ ATOM, LIST }ElemTag;

/*
typedef struct GLNode
{
	ElemTag tag;
	union
	{
		AtomType atom;
		struct{
			struct GLNode *head, *tail;
		}ptr;
	};

}*GList;
*/

typedef struct GLNode
{
	ElemTag tag;
	union
	{
		AtomType atom;
		struct GLNode *head;
	};
	struct GLNode *next;
}*GList;

Status Init(GList &);

#endif