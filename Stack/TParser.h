#pragma once
#include "TStack.h"
#include "stdafx.h"
#include <iostream>
#define MaxSize 201
using namespace std;
class TParser   
{ 
  char inf[MaxSize];
  char post[MaxSize];
  TStack <char> st_c;
  TStack <double> st_d;
public:
TParser(char *s=NULL ) : st_d(100) , st_c(100) //конструктор
{
  if (s == NULL) inf[0] = '\0';
  else 
    strcpy(inf , s);
}
bool IsNumber(char elem); //проверка на цифру
bool IsOper(char elem); //проверка на операцию
int Priority (char elem); //приоритет операции
void IntToPost(); //перевод из инфиксной в постфиксную
double CalcPost(); //расчет постфиксной записи
double InfCalc(); //расчет без перевода в постфиксную
double ExNumber(char *s, int &len); //проверка на число
void PrintPost(); //печать
/*& operator<<(ostream &ostr,const TParser &s);*/
};



