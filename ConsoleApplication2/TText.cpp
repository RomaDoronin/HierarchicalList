#include "stdafx.h"
#include "TText.h"
using namespace std;
//-------------------------
//Функции для сборки мусора

char* TText::Getstr()
{
	return(pCurr->str);
}

void TText::Setstr(string st)
{
	strcpy_s(pCurr->str, st.c_str());
	/*
	int i;
	for (i = 0; i<st.size(); i++)
	{
		pCurr->str[i] = st[i];
	}
	pCurr->str[i] = '\0';*/
}

//------------------
// ФУНКЦИИ НАВИГАЦИИ

void TText::GoNextLink()
{
	if (pCurr != NULL)
		if (pCurr->pNext != NULL)
		{
			path.Push(pCurr);
			pCurr = pCurr->pNext;
		}
}

void TText::GoDownLink()
{
	if (pCurr != NULL)
		if (pCurr->pDown != NULL)
		{
			path.Push(pCurr);
			pCurr = pCurr->pDown;
		}
}

void TText::GoPrevLink()
{
	if (!path.IsEmpty())
	{
		pCurr = path.Pop();
	}
}

void TText::GoFirstLink()
{
	while (!path.IsEmpty())
	{
		path.Pop();
	}
	pCurr = pFirst;
}

void TText::IncNextLine(char *_str)
{
	if (pCurr != NULL)
	{
		TLink *tmp = new TLink(_str);
		tmp->pNext = pCurr->pNext;
		pCurr->pNext = tmp;
	}
}

void TText::IncNextSection(char *_str)
{
	if (pCurr != NULL)
	{
		TLink *tmp = new TLink(_str);
		tmp->pDown = pCurr->pNext;
		pCurr->pNext = tmp;
	}
}

void TText::IncDownLine(char *_str)
{
	if (pCurr != NULL)
	{
		TLink *tmp = new TLink(_str);
		tmp->pNext = pCurr->pDown;
		pCurr->pDown = tmp;
	}
}

void TText::IncDownSection(char *_str)
{
	if (pCurr != NULL)
	{
		TLink *tmp = new TLink(_str);
		tmp->pDown = pCurr->pDown;
		pCurr->pDown = tmp;
	}
}

void TText::DelNextLine()
{
	if ((pCurr != NULL) && (pCurr->pNext != NULL))
	{
		TLink *tmp = pCurr->pNext;
		pCurr->pNext = pCurr->pNext->pNext;
		delete tmp;
	}
}

void TText::DelDownLine()
{
	if ((pCurr != NULL) && (pCurr->pDown != NULL))
	{
		TLink *tmp = pCurr->pDown;
		pCurr->pDown = pCurr->pDown->pNext;
		delete tmp;
	}
}

void TText::Reset()
{
	pCurr = pFirst;
	path.Clear();

	if (pCurr->pNext != NULL)
		path.Push(pCurr->pNext);
	if (pCurr->pDown != NULL)
		path.Push(pCurr->pDown);
}
 
void TText::GoNext()
{
	if (!path.IsEmpty())
	{
		pCurr = path.Pop();

		if (pCurr->pNext != NULL)
			path.Push(pCurr->pNext);
		if (pCurr->pDown != NULL)
			path.Push(pCurr->pDown);
	}
}

bool TText::IsEnd()
{
	return (path.IsEmpty());
}

//-------------------------------------
// Цикл прогоняющийся по всему списку -
// for( Reset(); !IsEnd(); GoNext()) {}

//-----------------------------
// Функции для работы с файлами

TLink* TText::ReadSection(ifstream &ifs)
{
	TLink* pHead = new TLink; //"!"
	TLink* pTmp = pHead;
	string str;
	bool flag = true;

	while (!ifs.eof())
	{
		getline(ifs, str);
		if (str == "}")
			break;
		else
			if (str == "{")
				pTmp->pDown = ReadSection(ifs);
			else
			{
				TLink* q = new TLink(str.c_str());
				pTmp->pNext = q;
				pTmp = q;

				if (flag/*(pHead->pDown == NULL) && (pHead->pNext == NULL)*/)
				{
					//pTmp = pHead->pNext;
					delete pHead;
					pHead = pTmp;
					flag = false;
				}
			}

	}

	return(pHead);
}

void TText::ReadFile(char* fname)
{
	ifstream ifs(fname);
	pCurr = pFirst = ReadSection(ifs);
}

void TText::PrintSection(TLink* p, int MaxO)
{
	if (p != NULL)
	{
		for (int j = 0; j < MaxO; j++)
			cout << "  ";
		if (p != pCurr)
			cout << p->str << endl;
		else
			cout << '[' << p->str << ']' << endl;
		PrintSection(p->pDown, (MaxO + 1));
		PrintSection(p->pNext, MaxO);
	}
}

void TText::PrintText()
{
	PrintSection(pFirst, 0);
}

void TText::SaveSection(TLink*p, ofstream& ofs)
{
	if (p != NULL)
	{
		int flag = 0;
		ofs << p->str << endl;
		if (p->pDown != 0)
		{
			ofs << "{" << endl;
			flag = 1;
		}
		SaveSection(p->pDown, ofs);
		if (flag == 1) ofs << "}" << endl;
		SaveSection(p->pNext, ofs);
	}
}

void TText::SaveText(char* fname)
{
	ofstream ofs(fname);
	SaveSection(pFirst, ofs);
}
