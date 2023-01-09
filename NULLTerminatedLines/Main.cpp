#include<iostream>
#include<Windows.h>
using namespace std;

void main() 
{
	setlocale(LC_ALL, "");
	//cout << "Hello Strings!";
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'}; //Можно просто 0 - типа int, он ужмется до 1 бита и будет char.
	//char str[] = "Hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;

	const int n = 20;
	char str[n] = {};
	cout << "Введите строку: "; 
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866); // - это не обязательно в последней версии студии.
	cout << str << endl;
}