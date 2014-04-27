
#include <stdlib.h>
#include "HString.h"

Status StrAssign(HString &s, char *str)
{
	if (s.ch) free(s.ch);
	int i = 0;
	char *c;
	for (c = str; c; ++i, ++c); // get str length;
	if (!i)
	{
		s.ch = NULL;
		s.length = 0;
	}
	else
	{
		if (!(s.ch = (char*)malloc(i*sizeof(char))))
			exit(ERROR);
		int j = 0;
		while((s.ch[j++] = str[j++]) != '\0');
		s.length = i;
	}
	return OK;
}

int StrLength(HString &s)
{
	return s.length;
}

int StrCompare(HString &s, HString &t)
{
	int i = 0;
	for (; i < s.length && i < t.length; ++i)
		if (s.ch[i] != t.ch[i]) return s.ch[i] - t.ch[i];
	return s.length - t.length;
}

Status ClearString(HString &s)
{
	if (s.ch)
	{
		free(s.ch);
		s.ch = NULL;
		s.length = 0;
	}
	return OK;
}

Status Concat(HString &s, HString &s1, HString &s2)
{
	if (s.ch) free(s.ch);
	if (!(s.ch = (char*)malloc((s1.length + s2.length)*sizeof(char))))
		exit(ERROR);
	int i = 0;
	for (; i < s1.length; i++)
	{
		*(s.ch + i) = *(s1.ch + i);
	}
	int j = 0;
	for (; j < s2.length; j++)
	{
		*(s.ch + i + j) = *(s2.ch + j);
	}
	s.length = s1.length + s2.length;

	return OK;
}

Status SubString(HString &sub,HString &s, int pos, int len)
{
	if (pos<1 || pos >s.length || len<0 || len>s.length - pos + 1)
		return ERROR;
	if (sub.ch) free(sub.ch);
	if (!len)
	{
		sub.ch = NULL;
		sub.length = 0;
	}
	else
	{
		sub.ch = (char*)malloc(len*sizeof(char));
		int i = 0;
		while (i < len)
		{
			*(sub.ch + i) = *(s.ch + pos + i);
		}
		sub.length = len;
	}
	return OK;
}

int KMP(HString &s, HString &t, int pos)
{
	int i = pos, j = 1;
	while (i <= s.ch[0] && j <= t.ch[0])
	{
		if (j == 0 || s.ch[i] == t.ch[j]){ ++i; ++j; }
		else j = next[j];
	}

	if(j > t.ch[0]) return i - t.ch[0];
	else return 0;
}

