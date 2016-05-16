#include "stdafx.h"
#include "TLink.h"
using namespace std;

void* TLink::operator new(size_t size)
{
	TLink *pTmp = TextMem.pFree;
	TextMem.pFree = TextMem.pFree->pNext;
	return (pTmp);
}

void TLink::operator delete(void*p)
{
	TLink *pTmp = (TLink*)p;
	pTmp->pNext = TextMem.pFree;
	TextMem.pFree = pTmp;
}

void TLink::InitMem(int size)
{
	TextMem.pFirst = (TLink*) new char[sizeof(TLink)*size];
	TextMem.pFree = TextMem.pFirst;
	TextMem.pLast = TextMem.pFirst + (size - 1);
	TLink *tmp = TextMem.pFirst;
	for (int i = 0; i < size - 1; i++)
	{
		tmp->pNext = (tmp + 1);
		tmp++;
	}
	tmp->pNext = NULL;
}

void TLink::ClearMem(TText &txt, int size)
{
	int j = 0, k = 0;

	for (txt.Reset(); !txt.IsEnd(); txt.GoNext())
	{
		string s = "+";
		s += txt.Getstr();
		txt.Setstr(s);
		j++;
	}

	string s = "+";
	s += txt.Getstr();
	txt.Setstr(s);
	j++;

	TLink *pTmp = TextMem.pFree;

	while (pTmp/*->pNext*/ != NULL)
	{
		pTmp->str[0] = '+';
		pTmp->str[1] = '\0';
		j++;
		pTmp = pTmp->pNext;
	}

	cout << "Мусор: " << endl;

	pTmp = txt.GetpFirst();

	for (int i = 0; i < size-1; i++)
	{
		if (pTmp->str[0] == '+')
			pTmp->str[0] = '\0';
		else
		{
			cout << pTmp->str << endl;
			delete pTmp;
		}/*
		cout << i << ") " << pTmp->str << endl;*/
		pTmp++;
	}
}