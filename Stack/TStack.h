#pragma once

template <class T>
class TStack
{
private: 
	int MaxSize;
	int Index;
	T *mas;
public:
    TStack(int _MaxSize) //конструктор
	{ 
		MaxSize = _MaxSize;
		Index = -1;
		if (MaxSize <= 0)
			throw MaxSize;
		mas = new T [MaxSize];
	}
~TStack() //диструктор
	{ 
		delete [] mas;
	}
TStack(const TStack &s) // конструктор копирования
	{
		MaxSize = s.MaxSize;
		Index = s.Index;
		mas = new T[MaxSize];
		for ( int i=0 ; i<MaxSize; i++)
			mas[i] = s.mas[i];
	}

TStack &operator = (const TStack &s) // присваивание
	{
		if (MaxSize != s.MaxSize)
			{
				delete [] mas;
		        MaxSize = s.MaxSize;
				mas = new T[MaxSize];
		    }
		Index = s.Index;
		for ( int i=0; i<=Index; i++)
			mas[i] = s.mas[i];
		return *this;
	}
bool IsEmpty () //проверка на пустоту
   {
	   return (Index == -1);
   }
bool IsFull () //проверка на полноту
   {
	   return (Index == MaxSize-1);
   }

T Top()  //вернуть элемент стека
   {
	   if (Index<0)
		   throw Index;
	   return mas[Index];
   }

T Pop() //вытолкнуть элемент стека
   {
	   if (Index < 0)
		   throw Index;
	   T tmp=mas[Index];
	   Index = Index-1;
	   return tmp;
   }
void Push(const T elem) //вставить элемент в стек
   {
	   if (Index >= MaxSize-1)
		   throw MaxSize;
	   Index++;
	   mas[Index] = elem;
   }
void Clear() //очистить стек
   {
	   Index= -1;
   }
};

