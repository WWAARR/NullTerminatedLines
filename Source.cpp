#include<iostream>
#include<iostream>
#include<Windows.h>
using namespace std;

void InputLine(char szStr[], const int n);
int  StrLen(char szStr[]);		//Вычесляет количество символов.
void UpperCase(char szStr[]);	//Переводит строку в верхний регистр.
void LowerCase(char szStr[]);	//Переводит строку в нижний  регистр.
void Capitalize(char szStr[]);  //Первая буква в каждом предложении делает заглавной
bool isLowLetter(char symbol);
bool isLowRusLetter(char symbol);
void Shrink(char szStr[]);
bool isPalindrome(char szStr[]);

//bool isNumber(char szStr[]);
//bool isHexNumber(char szStr[]);
void main()
{
	/*setlocale(LC_ALL, "");
	system("CHCP 1251");
	system("CLS");
	const int n = 20;	//Размер строки
	char szStr[n] = {};
	cout << "Введите строку: ";
	cin.getline(szStr, n);
	cout << szStr << endl;
	cout << sizeof(szStr) << endl;
	cout << StrLen(szStr) << endl;
	UpperCase(szStr);*/

	setlocale(LC_ALL, "");
	system("CHCP 1251");
	system("CLS");
	cout << (int)'A' << "\t" << (int)'a' << endl;
	cout << 'A' - 'a' << endl;
	const int n = 20;
	char szStr[n] = {};

	cout << "Введите строку: ";
	cin.getline(szStr, n);
	cout << szStr << endl;
	cout << sizeof(szStr) << endl;
	StrLen(szStr);
	cout << szStr << endl;
	UpperCase(szStr);
	cout << szStr << endl;
	LowerCase(szStr);
	cout << szStr << endl;
	Capitalize(szStr);
	cout << szStr << endl;
	Shrink(szStr);
	cout << szStr << endl;
	isPalindrome(szStr);
	cout << szStr << endl;
}
void InputLine(char szStr[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(szStr, n);
	SetConsoleCP(867);
}
int  StrLen(char szStr[])
{
	int i = 0;
	for (; szStr[i]; i++);
	return i;
}
void UpperCase(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		if
			(
				szStr[i] >= 'a' && szStr[i] <= 'z' ||
				szStr[i] >= 'а' && szStr[i] <= 'я'
				)
			szStr[i] -= 32;
	}
}
void LowerCase(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		if
			(
				szStr[i] >= 'A' && szStr[i] <= 'Z' ||
				szStr[i] >= 'А' && szStr[i] <= 'Я'
				)
			szStr[i] += ' ';
	}
}
void Capitalize(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		if
			(
				szStr[i] >= 'a' && szStr[i] <= 'z' ||
				szStr[i] >= 'а' && szStr[i] <= 'я'
				)
			szStr[i] -= 32;
	}
}
bool isLowLetter(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')return true;
	else return false;
}
bool isLowRusLetter(char symbol)
{
	if (symbol >= 'а' && symbol <= 'я')return true;
	else return false;
}
void Shrink(char szStr[])
{
	int i = 0;
	for (; szStr[i]; i++)
	{
		while (szStr[i] == ' '&& szStr[i + 1] == ' ');
	}
	for (int j = i + 1; szStr[i]; i++)
	{
		szStr[j] = szStr[j + 1];
	}
	{
	}
}
bool isPalindrome(char szStr[])
{

	int size = StrLen(szStr);
	char* buffer = new char[size + 1];
	for (int i = 0; i < size / 2; i++)buffer[i] = szStr[i];
	LowerCase(szStr);
	for (int i = 0; i < size / 2; i++)
	{
		if (szStr[i] != szStr[size - 1 - i]);
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
//bool isNumber(char szStr[]){}