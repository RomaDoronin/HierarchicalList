#pragma once

template <class T>
class TStack
{
private: 
	int MaxSize;
	int Index;
	T *mas;
public:
    TStack(int _MaxSize) //�����������
	{ 
		MaxSize = _MaxSize;
		Index = -1;
		if (MaxSize <= 0)
			throw MaxSize;
		mas = new T [MaxSize];
	}
~TStack() //����������
	{ 
		delete [] mas;
	}
TStack(const TStack &s) // ����������� �����������
	{
		MaxSize = s.MaxSize;
		Index = s.Index;
		mas = new T[MaxSize];
		for ( int i=0 ; i<MaxSize; i++)
			mas[i] = s.mas[i];
	}

TStack &operator = (const TStack &s) // ������������
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
bool IsEmpty () //�������� �� �������
   {
	   return (Index == -1);
   }
bool IsFull () //�������� �� �������
   {
	   return (Index == MaxSize-1);
   }

T Top()  //������� ������� �����
   {
	   if (Index<0)
		   throw Index;
	   return mas[Index];
   }

T Pop() //���������� ������� �����
   {
	   if (Index < 0)
		   throw Index;
	   T tmp=mas[Index];
	   Index = Index-1;
	   return tmp;
   }
void Push(const T elem) //�������� ������� � ����
   {
	   if (Index >= MaxSize-1)
		   throw MaxSize;
	   Index++;
	   mas[Index] = elem;
   }
void Clear() //�������� ����
   {
	   Index= -1;
   }
};

