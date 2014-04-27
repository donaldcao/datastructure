#ifndef _HSTRING_H_
#define _HSTRING_H_

#include "..\common.h"

typedef struct
{
	char *ch;
	int length;
}HString;

Status StrAssign(HString &s, char *str);
int StrLength(HString &s);
int StrCompare(HString &s, HString &t);
Status ClearString(HString &s);
Status  Concat(HString &s, HString &s1, HString &s2);
Status SubString(HString &sub, HString &s, int pos, int len);

int KMP(HString &s, HString &t, int pos);

#endif

