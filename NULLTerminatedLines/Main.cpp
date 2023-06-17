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
string RemoveSymbol(const string& str);
bool Polindrome(const char str[]);
bool IsIntNumber(const char str[]);
int ToIntNumber(char str[]);
bool IsBinNumber(const char str[]);
int BinToDec(char str[]);
bool IsHexNumber(const char str[]);
int HexToDec(const char str[]);

void main() 
{
	setlocale(LC_ALL, "");
#ifdef Lesson
	cout << "Hello Strings!";
	char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; //Можно просто 0 - типа int, он ужмется до 1 бита и будет char.
	char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;

	const int n = 20;
	char str[n] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866); // - это не обязательно в последней версии студии.
	cout << str << endl;
#endif // Lesson
	
	const int n = 256;
	char str[n] = {"Was it    a       cat     I saw?"};
	//char str[n] = { "0101011001" };
	//char str[n] = { "7B" };
	//cout << "Введите строку: ";
	SetConsoleCP(1251);
	//cin.getline(str, n);
	SetConsoleCP(866); // - это не обязательно в последней версии студии.
	cout << "Вы ввели строку:\n" << str << " длиной " << StringLength(str) << " символов" << endl;
	cout << "Перевод в верхний регистр: "; ToUpper(str); cout << endl;
	cout << "Перевод в нижний регистр: "; ToLower(str); cout << str << endl;
	cout << "Удаление лишних пробелов: "; Shrink(str); cout << str << endl;
	//cout << str << endl;
	cout << "Строка" << (Polindrome(str) ? "" : " не") << " палиндром: ";
	cout << str << endl;
	if (!IsIntNumber(str))cout << "Строка не является целым десятичным числом!" << endl;
	else cout << ToIntNumber(str) << " - это число является целым десятичным." << endl;
	if (!IsBinNumber(str))cout << "Строка не является двоичным числом!" << endl;
	else cout << "Строка " << str << " является двоичным числом и перевод его в десятчное число: " 
		<< BinToDec(str) << endl;
	if (!IsHexNumber(str))cout << "Строка не является шестнадцатеричным числом!" << endl;
	else cout << "Строка " << str << " является шестнадцатеричным числом и перевод его в десятчное число: "
		<< HexToDec(str) << endl;
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
		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= ' ';
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
string RemoveSymbol(const string& str)
{
	string result;
	for (char c : str) 
	{
		if (isalnum(c)) 
		{
			result += c;
		}
	}
	return result;
}
bool Polindrome(const char str[])
{
	string copy = RemoveSymbol(str);
	int len = copy.length();
	for (int i = 0; i < len / 2; i++) 
	{
		if (tolower(copy[i]) != tolower(copy[len - i - 1]))
		{
			return false;
		}
	}
	return true;
}
bool IsIntNumber(const char str[])
{
	if (str == NULL || *str == '\0')return false;
	for (const char* i = str; *i != '\0'; ++i)
	{
		if (!isdigit(*i))return false;
	}
	return true;
}
int ToIntNumber(char str[])
{
	if (IsIntNumber(str))
	{
		int result = 0;
		for (const char *i = str; *i != '\0'; ++i)
		{
			result = result * 10 + (*i - '0');
		}
		return result;
	}	
}
bool IsBinNumber(const char str[])
{
	if (str[0] == '\0')
	{
		return false;
	}
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '0' && str[i] != '1')
		{
			return false;
		}
	}
	return true;
}
int BinToDec(char str[])
{
	if (IsBinNumber) 
	{
		int len = strlen(str);
		int res = 0;
		int buff = 1;
		for (int i = len; i >= 0; i--)
		{
			if (str[i] == '1')
			{
				res += buff;
			}
			buff *= 2;
		}
		return res;
	}
}
bool IsHexNumber(const char str[])
{
	int len = strlen(str);
	if (len == 0) return false;
	if (str[0] == '-') str++;
	if (len == 1 && str[0] == '0') return true;
	for (int i = 0; i < len; i++) 
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') ||
			(str[i] >= 'A' && str[i] <= 'F')))
			return false;
	}
	return true;
}
int HexToDec(const char str[])
{
	int len = strlen(str);
	if (len == 0) return 0;
	int res = 0, base = 1;
	if (str[0] == '-') str++;
	if (len > 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		str += 2;
		len -= 2;
	}
	for (int i = 0; i < len; i++) 
	{
		int digit;
		if (str[i] >= '0' && str[i] <= '9') digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f') digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F') digit = str[i] - 'A' + 10;
		else return 0;
		res = res * 16 + digit;
	}
	return res;
}