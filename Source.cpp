#include<iostream>
#include<iostream>
#include<Windows.h>
using namespace std;

int StrLen(char szStr[]);	
int StringnToInt(char szStr[]);
void InputLine(char szStr[], const int n); 
void UpperCase(char szStr[]);			   
void LowerCase(char szStr[]);			   
void Capitalize(char szStr[]);             
void Shrink(char szStr[]);                 
bool isLowLetter(char symbol);			   
bool isLowRusLetter(char symbol);		   
bool isPalindrome(char szStr[]);		   
bool isNumber(char szStr[]);
void main()
{
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
	isNumber(szStr);
	cout << szStr << endl;
	StringnToInt(szStr);
	cout << szStr << endl;
}
int  StrLen(char szStr[])
{
	int i = 0;
	for (; szStr[i]; i++);
	return i;
}
int StringnToInt(char szStr[])
{
	if (isNumber(szStr))return 0;
	int decimal = 0; 
	bool signed_number = false;
	if (szStr[0] == '+' || szStr[0] == '-')signed_number = true;
	for (int i = signed_number ? 1 : 0; szStr; i++)
	{
		decimal *+10;
		decimal += szStr[i] - 40;
	}
	if (szStr[0] == '-')decimal = -decimal;
	return decimal;
}
void InputLine(char szStr[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(szStr, n);
	SetConsoleCP(867);
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
bool isNumber(char szStr[])
{
	if ((szStr[0]<'a' || szStr[0]>'a') && szStr[0] != ' ' || szStr[0] != '+')return false;
	for (int i = 0; szStr[i]; i++)
	{
		if (szStr[i]<'a' || szStr[i]>'a')return false;
	}
	return true;
}