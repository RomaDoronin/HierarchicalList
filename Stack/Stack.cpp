// Stack.cpp: ������� ���� �������.
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
	cout<<"1.���������� ��������� � ������ ��������������."<<endl;
	cout<<"2.���������� ��������� � ������������� ��������������."<<endl;
	cout<<"3.���������� ���������"<<endl;
	while (op!=0)
	{
		scanf("%d",&pt);
		switch (pt)
		{
		  case 1:{
			     cout<<"������� ���������"<<endl;

				 /*char *t = new char[255];
				 cin.getline(t, 255);
				 char *polinom = new char[strlen(t) + 1]; // ���������� ����� ������ ��� ������ �������� ������
				 strcpy(polinom, t); // ���������� ������ � ����� ������
				 delete[] t;*/
				 fflush(stdin);
				 gets(polinom);
				 TParser Str(polinom);
	             Str.IntToPost();
				 cout<<"��������� � ����������� ������"<<endl<<endl;
	             Str.PrintPost();
                 rez =Str.CalcPost();
                 cout<<endl<<"���������"<<endl<<rez<<endl;
				 rez=0;
				 break;		 	
				 }
		case 2:  {
			     cout<<"������� ���������"<<endl;
				 fflush(stdin);
				 gets(polinom);
				/* char *t = new char[255];
				 cin.getline(t, 255);
				 char *polinom = new char[strlen(t) + 1]; // ���������� ����� ������ ��� ������ �������� ������
				 strcpy(polinom, t); // ���������� ������ � ����� ������*/
				 TParser Str1(polinom);
	             rez = Str1.InfCalc();
				 cout<<endl<<"���������"<<endl<<rez<<endl;
				 rez=0;
				 break;
				 }
		case 3: op = 0; break;
		}
	}
	return 0;
}
