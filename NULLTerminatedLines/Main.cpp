#include<iostream>
#include<Windows.h>
using namespace std;

void main() 
{
	setlocale(LC_ALL, "");
	//cout << "Hello Strings!";
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'}; //����� ������ 0 - ���� int, �� ������� �� 1 ���� � ����� char.
	//char str[] = "Hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;

	const int n = 20;
	char str[n] = {};
	cout << "������� ������: "; 
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866); // - ��� �� ����������� � ��������� ������ ������.
	cout << str << endl;
}