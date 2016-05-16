#include "StdAfx.h"
#include "TParser.h"
#include "stdlib.h"
#include <math.h>
bool TParser::IsNumber(char elem)
{
    if ( (elem == '0' ) || (elem == '1') || (elem == '2') || (elem == '3') || (elem == '4') || (elem == '5') || (elem == '6') || (elem == '7') || (elem == '8') || (elem == '9')||(elem==','))
		return true;
	else 
		return false;
}
bool TParser::IsOper (char elem)
{
    if ( (elem == '+') || (elem == '-') || (elem == '*') || (elem == '/') || (elem == '^') || (elem == '=') )
		return true;
	else 
		return false;
}
int TParser::Priority (char elem)
{ int i;
     switch (elem) {
		 /*case ')' : i = 1; break;*/
		 case '(' : i = 1; break;
		 case '+' : i = 2; break;
		 case '-' : i = 2; break;
		 case '*' : i = 3; break;
		 case '/' : i = 3; break;
		 case '^' : i = 4; break;
		 case '=' : i = -1; break;
	 }
	 return i;
}
void TParser:: IntToPost() {
	int i =0; int j = 0;
    st_c.Push('=');
	while (inf[i] != '\0')
	{
		if (IsNumber(inf[i]))
		{
			post[j] = inf[i];
			j++;
		}
		else
			if (inf[i] == '(')
				st_c.Push(inf[i]);
			else 
				if (inf[i] == ')')
				{
					char tmp = st_c.Pop();
					while (tmp!='(')
					{
						post[j] = tmp;
						j++;
						tmp = st_c.Pop();
					}
				}
				else
					if(IsOper(inf[i]))
					{
						char tmp = st_c.Pop();
						while (Priority(tmp)>=Priority(inf[i]))
						{
							post[j] = tmp;
							j++;
							tmp = st_c.Pop();
						}
						st_c.Push(tmp);
						st_c.Push(inf[i]);
					}
					i++;
	}
	post[j] = '\0';
}
double TParser:: CalcPost()
{
	int i=0;
	st_d.Clear();
	while ((post[i]!='\0') && (post[i]!='='))
	{
		if (IsNumber(post[i])) 
		{
			st_d.Push(post[i] - '0');
		}
		if (IsOper(post[i]))
		{
			double oper2 = st_d.Pop();
			double oper1 = st_d.Pop();
			switch (post[i])
	{
	    case '+': st_d.Push(oper1 + oper2);break;
	    case '-': st_d.Push(oper1 - oper2);break;
		case '*': st_d.Push(oper1*oper2);break;
		case '/': st_d.Push(oper1/oper2);break;
		case '^': st_d.Push(pow(oper1,oper2));break;
	}
		}

	i++;}
	return (st_d.Pop());
}
double TParser:: ExNumber(char *s, int &len)
{
	int i=0;
	double tmp = atof(s);
	while (s[i]!='\0')
	{
		if (IsNumber(s[i]))
			i++;
		else break;
	}
	len = i;
	return tmp;
}
double TParser:: InfCalc()
{
	st_d.Clear();
	st_c.Clear();
	int i=0, j=0;
	int len;
	st_c.Push('=');
	while (inf[i]!='\0')
	{
		if (IsNumber(inf[i]))
		{
			double tmp = ExNumber(&inf[i], len);
			st_d.Push(tmp);
			i+=len-1;
		}
		else
			if(inf[i] == '(')
			{
				st_c.Push(inf[i]);
			}
			else
				if (inf[i]==')')
				{
					char tmp = st_c.Pop();
					while (tmp!='(')
					{
						double oper2 = st_d.Pop();
						double oper1 = st_d.Pop();
					    switch (tmp)
	                    {
	                       case '+': st_d.Push(oper1 + oper2);break;
	                       case '-': st_d.Push(oper1 - oper2);break;
		                   case '*': st_d.Push(oper1*oper2);break;
		                   case '/': st_d.Push(oper1/oper2);break;
		                   case '^': st_d.Push(pow(oper1,oper2));break;
	                    }
							tmp=st_c.Pop();
					}
				}
				else
					if(IsOper(inf[i]))
					{
						char tmp = st_c.Pop();
						while (Priority(tmp)>=Priority(inf[i]))
						{ double oper2 = st_d.Pop();
						  double oper1 = st_d.Pop();
						  switch (tmp)
	                      {
	                         case '+': st_d.Push(oper1 + oper2);break;
	                         case '-': st_d.Push(oper1 - oper2);break;
		                     case '*': st_d.Push(oper1*oper2);break;
		                     case '/': st_d.Push(oper1/oper2);break;
		                     case '^': st_d.Push(pow(oper1,oper2));break;
	                      }
						  tmp=st_c.Pop();
						}
						st_c.Push(tmp);
						st_c.Push(inf[i]);
					}
					i++;
	}
    char tmp = st_c.Pop();
	while (tmp!='=')
	{
		double oper2 = st_d.Pop();
        double oper1 = st_d.Pop();
	    switch (tmp)
		{
		    case '+': st_d.Push(oper1 + oper2);break;
            case '-': st_d.Push(oper1 - oper2);break;
            case '*': st_d.Push(oper1*oper2);break;
		    case '/': st_d.Push(oper1/oper2);break;
	        case '^': st_d.Push(pow(oper1,oper2));break;
	    }
		tmp=st_c.Pop();
	}
	return st_d.Pop();
}
void TParser:: PrintPost()
{
	int i = 0;
	while ( post[i]!='\0')
		{
			cout<<post[i];
			i++;
	    }
}
