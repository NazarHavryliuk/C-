#include<iostream>
#include<ctime>
#include <cstdlib>
#include<string>
#include <locale>

using namespace std;
void fooforbrackets(string& str0)
{
	const int size = str0.length();
	char* str = new char[size + 1];
	/*a=������� (*/
	int a = 0;
	/*b=������� (*/
	int b = 0;
	for (int i = 0; i < size; i++)
	{
		str[i] = str0[i];
	}
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '(')
		{
			a++;
		}
		if (str[i] == ')')
		{
			b++;
		}

	}

	if (a == b)
	{
		cout << endl << "The number of open and closed brackets is the same" << endl;
	}
	if (a > b)
	{
		cout << "The number of open parentheses is greater than the number of closed parentheses" << endl;
	}
	if (a < b)
	{
		cout << "The number of open parentheses is less than the number of closed parentheses" << endl;
	}
	delete[] str;
}

void main()
{
	setlocale(LC_ALL, "uk_UA.UTF-8");
	string str0;
	cin >> str0;
	fooforbrackets(str0);
}