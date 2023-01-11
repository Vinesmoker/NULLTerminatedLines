#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define Lesson

int StringLength(const char str[]);
void ToUpper(char str[]);
void ToLower(char str[]);
void Shrink(char str[]);
bool Polindrome(char str[]);
void RemoveSymbol(char str[], char symbol);
bool IsIntNumber(const char str[]);

void main() 
{
	setlocale(LC_ALL, "");
#ifdef Lesson
	cout << "Hello Strings!";
	char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; //����� ������ 0 - ���� int, �� ������� �� 1 ���� � ����� char.
	char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;

	const int n = 20;
	char str[n] = {};
	cout << "������� ������: ";
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866); // - ��� �� ����������� � ��������� ������ ������.
	cout << str << endl;
#endif // Lesson
	
	const int n = 256;
	char str[n] = {"Qqqqqqq   qqqqqqq   qqqqqq"};
	//cout << "������� ������: ";
	SetConsoleCP(1251);
	//cin.getline(str, n);
	SetConsoleCP(866); // - ��� �� ����������� � ��������� ������ ������.
	cout << "�� ����� ������:\n" << str << " ������ " << StringLength(str) << " ��������" << endl;
	ToUpper(str); 
	ToLower(str);
	Shrink(str);
	cout << str << endl;
	cout << "������ " << (Polindrome(str) ? "" : " �� ") << "���������";
	//cout << IsIntNumber(str);
}


int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void ToUpper(char str[])
{ 
	
	for (int i = 0; i < str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		if (str[i] >= '�' && str[i] <= '�')str[i] -= ' ';
		cout << str[i];
	}
	cout << endl;
	
	//for (int i = 0; str[i]; i++)str[i] = toupper(str[i]);
}
void ToLower(char str[])
{
	for (int i = 0; str[i]; i++)str[i] = tolower(str[i]);
}
void Shrink(char str[])
{
	for (int i = 0; i < str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; j < str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
void RemoveSymbol(char str[], char symbol)
{
	for (int i = 0; i < str[i]; i++)
	{
		while (str[i] == symbol)	
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}
bool Polindrome(char str[])
{
	ToLower(str);
	RemoveSymbol(str, ' ');
	int n = strlen(str);
	for (int i = 0; i < n /2; i++)
	{
		if (str[i] != str[n - 1 - i])return false;
	}
	return true;
}
bool IsIntNumber(const char str[])
{
	return 0;
}