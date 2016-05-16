#pragma once
#include "TLink.h"
using namespace std;
class TLink;

class TText
{
	TLink *pFirst;
	TLink *pCurr;
	TStack <TLink*> path;

public:

	TText(TLink *_pFirst = NULL) : path(100)
	{
		if (_pFirst != 0)
			pFirst = pCurr = _pFirst;
		else
		{
//			pFirst = new TLink();
			pCurr = pFirst;
		}
	}

	~TText(){}

	//-------------------------
	//Функции для сборки мусора

	char* Getstr();

	void Setstr(string st);

	//------------------
	// ФУНКЦИИ НАВИГАЦИИ

	void GoNextLink();

	void GoDownLink();

	void GoPrevLink();

	void GoFirstLink();

	void IncNextLine(char *_str);

	void IncNextSection(char *_str);

	void IncDownLine(char *_str);

	void IncDownSection(char *_str);

	void DelNextLine();

	void DelDownLine();

	void Reset();

	void GoNext();

	bool IsEnd();

	//-------------------------------------
	// Цикл прогоняющийся по всему списку -
	// for( Reset(); !IsEnd(); GoNext()) {}

	//-----------------------------
	// Функции для работы с файлами

	TLink* ReadSection(ifstream &ifs);

	void ReadFile(char* fname);

	void PrintSection(TLink* p, int MaxO);

	void PrintText();

	void SaveSection(TLink*p, ofstream &ofs);

	void SaveText(char* fname);

	TLink* GetpFirst()
	{
		return(pFirst);
	}
};


