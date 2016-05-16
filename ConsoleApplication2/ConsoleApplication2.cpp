// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TLink.h"
#include "TText.h"
#include <conio.h>
#include <cstdlib>

TTextMem TLink::TextMem;
const int MaxSize = 3;

int _tmain(int argc, _TCHAR* argv[])
{
	TLink::InitMem(100);
	setlocale(LC_ALL, "russian");

		char StM[][25] =
		{
			"Загрузить из файла", "Выход"
		};

		int Skl = 2;

		int i, Ches = 0, code;
		char D;

		TText Word;

		while (Skl == 2)
		{

			for (i = 0; i<2; i++)
			{
				if (i == Ches)
				{
					cout << '[' << StM[i] << ']' << endl;
				}
				else
				{
					cout << StM[i] << endl;
				}
			}

			D = _getch();
			code = static_cast<int>(D);
			system("cls");

			switch (D)
			{
			case 80:
				Ches = (Ches + 1) % 2;
				break;
			case 72:
				Ches = (Ches + 1) % 2;
				break;
			case 13:
				switch (Ches)
				{
				case 0:
				{
					Word.ReadFile("text.txt");
					Skl = 1;
					break;
				}
				case 1:
					Skl = 0; // Выход
					break;
				}
			}

		}

		while (Skl)
		{

			cout << "V - переход по pNext" << endl <<
				"A - переход к предедущему" << endl <<
				"> - переход по pDown" << endl <<
				"< - переход к pFirst" << endl <<
				"Ins - добавить звено" << endl <<
				"Del - удалить звено " << endl <<
				"Esc - выход" << endl << 
				"Home - сохранить текст в фаил" << endl << endl;

			Word.PrintText();

			D = _getch();
			code = static_cast<int>(D);
			system("cls");

			switch (D)
			{
			case 80: //вниз
				Word.GoNextLink();
				break;
			case 72: //вверх
				Word.GoPrevLink();
				break;
			case 75: //влево
				Word.GoFirstLink();
				break;
			case 77: //вправо
				Word.GoDownLink();
				break;

			case 82: //ins
			{
				char st[81];
				cout << endl << "Введите строку: ";
				cin >> st;
				system("cls");
				int Skl1 = 1;

				char StM1[][25] =
				{
					"Добавить звено по pNext", "Добавить секцию по pNext", "Добавить звено по pDown", "Добавить секцию по pDown", "Назад"
				};
				int Ches1 = 0;
				char D1;

				while (Skl1)
				{

					cout << "Новая строка: " << st << endl << endl;

					for (i = 0; i < 5; i++)
					{
						if (i == Ches1)
						{
							cout << '[' << StM1[i] << ']' << endl;
						}
						else
						{
							cout << StM1[i] << endl;
						}
					}

					D1 = _getch();
					code = static_cast<int>(D1);
					system("cls");

					switch (D1)
					{
					case 80:
						Ches1 = (Ches1 + 1) % 5;
						break;
					case 72:
						Ches1 = (Ches1 + 4) % 5;
						break;
					case 13:
						switch (Ches1)
						{
						case 0:
							Word.IncNextLine(st);
							Skl1 = 0;
							break;
						case 1:
							Word.IncNextSection(st);
							Skl1 = 0;
							break;
						case 2:
							Word.IncDownLine(st);
							Skl1 = 0;
							break;
						case 3:
							Word.IncDownSection(st);
							Skl1 = 0;
							break;
						case 4:
							Skl1 = 0;
							break;
						}
					}

				}
				break;
			}

			case 83: //del
			{
				int Skl2 = 1;

				char StM2[][25] =
				{
					"Удалить звено по pNext", "Удалить звено по pDown", "Назад"
				};
				int Ches2 = 0;
				char D2;

				while (Skl2)
				{
					for (i = 0; i < 3; i++)
					{
						if (i == Ches2)
						{
							cout << '[' << StM2[i] << ']' << endl;
						}
						else
						{
							cout << StM2[i] << endl;
						}
					}

					D2 = _getch();
					code = static_cast<int>(D2);
					system("cls");

					switch (D2)
					{
					case 80:
						Ches2 = (Ches2 + 1) % 3;
						break;
					case 72:
						Ches2 = (Ches2 + 2) % 3;
						break;
					case 13:
						switch (Ches2)
						{
						case 0:
							Word.DelNextLine();
							Skl2 = 0;
							break;
						case 1:
							Word.DelDownLine();
							Skl2 = 0;
							break;
						case 2:
							Skl2 = 0;
							break;
						}
					}

				}
				break;
			}
			case 27: //esc
				Skl = 0;
				TLink::ClearMem(Word, 100); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				break;
			case 71: //Home
			{
				cout << "Сохранился" << endl << endl;
				Word.SaveText("text.txt");
				break;
			}
			}

		}

		cout << "Нажмите Enter для выхода";

		_getch();

		system("cls");


	return 0;
}

