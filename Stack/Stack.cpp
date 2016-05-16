// Stack.cpp: главный файл проекта.
#include "stdafx.h"
#include "stdio.h"
#include "TStack.h"
#include "TParser.h"
#include <iostream>
#include <conio.h>
#include <cstdio>
using namespace System; 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int op = -1;
	int pt, i=0;
	double rez;
	char polinom[100];
	cout<<"1.Вычисление выражений с целыми коэффициентами."<<endl;
	cout<<"2.Вычисление выражений с вещественными коэффициентами."<<endl;
	cout<<"3.Завершение программы"<<endl;
	while (op!=0)
	{
		scanf("%d",&pt);
		switch (pt)
		{
		  case 1:{
			     cout<<"Введите выражение"<<endl;

				 /*char *t = new char[255];
				 cin.getline(t, 255);
				 char *polinom = new char[strlen(t) + 1]; // выделяется новая память под размер введённой строки
				 strcpy(polinom, t); // копируется строка в новую память
				 delete[] t;*/
				 fflush(stdin);
				 gets(polinom);
				 TParser Str(polinom);
	             Str.IntToPost();
				 cout<<"Выражение в постфиксной записи"<<endl<<endl;
	             Str.PrintPost();
                 rez =Str.CalcPost();
                 cout<<endl<<"Результат"<<endl<<rez<<endl;
				 rez=0;
				 break;		 	
				 }
		case 2:  {
			     cout<<"Введите выражение"<<endl;
				 fflush(stdin);
				 gets(polinom);
				/* char *t = new char[255];
				 cin.getline(t, 255);
				 char *polinom = new char[strlen(t) + 1]; // выделяется новая память под размер введённой строки
				 strcpy(polinom, t); // копируется строка в новую память*/
				 TParser Str1(polinom);
	             rez = Str1.InfCalc();
				 cout<<endl<<"Результат"<<endl<<rez<<endl;
				 rez=0;
				 break;
				 }
		case 3: op = 0; break;
		}
	}
	return 0;
}
