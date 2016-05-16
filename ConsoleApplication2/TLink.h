#pragma once
#include <C:\Users\Roma\Desktop\Labs_2015\Lab3_Stack_Parser\TStack-master\Stack (m)\Stack.h>
#include <fstream>
#include <string>
#include <iostream>
#include "TText.h"

using namespace std;

const int MaxLen = 81;

class TLink;

struct TTextMem
{
	TLink *pFirst, *pFree, *pLast;
};

class TText;

class TLink
{
public:

	char str[MaxLen];
	TLink *pNext;
	TLink *pDown;

	static TTextMem TextMem;

	TLink()
	{
		pNext = NULL;
		pDown = NULL;
		str[0] = '\0';
	}

	TLink(const char *_str, TLink *_pNext = NULL, TLink *_pDown = NULL)
	{
		pNext = _pNext;
		pDown = _pDown;
		int i;
		for (i = 0; _str[i] != '\0'; i++)
			str[i] = _str[i];
		str[i] = '\0';
	}

	~TLink(){}

	void* operator new(size_t size);

	void operator delete(void*p);

	static void InitMem(int size);

	static void ClearMem(TText &txt, int size);
};
