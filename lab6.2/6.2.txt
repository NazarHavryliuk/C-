#include<iostream>
#include<ctime>
#include <cstdlib>
#include<string>
#include <locale>

using namespace std;
void work_from_text(string& str)
{
	const int size = str.length();
	int number_of_sentences = 0;
	for (int i = 0; i < size; i++)
	{
		if ((str[i] == '.') && (str[i + 1] != '.'))
		{
			number_of_sentences++;
		}

	}
	char** arr = new char* [number_of_sentences] {};
	int nsentences = 0;
	int a = 0, b = 0;
	for (int i = 0; i < size; i++)
	{
		if ((str[i] == '.') && (str[i + 1] != '.'))
		{
			b = i;
			arr[nsentences] = new char[b - a + 1];
			for (int j = 0; j < b - a + 1; j++)
			{
				arr[nsentences][j] = str[a + j];
			}
			nsentences++;
			a = b + 1;

		}
	}
	for (int j = 0; j < number_of_sentences; j++)
	{
		for (int k = 0; k < number_of_sentences-1; k++)
		{
			int size1=strlen(arr[k]);
			int size2 = strlen(arr[k+1]);
			if (size1 > size2)
			{
				swap(arr[k],arr[k+1]);
			}
		}
	}
	int index = 0;
	for (int j = 0; j < number_of_sentences; j++)
	{
		for (int k = 0; arr[j][k] != '.'; k++)
		{
			str[index] = arr[j][k];
			index++;
		}
		str[index] = '.';
		index++;
	}
	for (int j = 0; j < number_of_sentences; j++)
	{
		delete[] arr[j];
	}
	delete[] arr;
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "ukraine");
	string str;

	getline(cin, str);
	work_from_text(str);
	cout << "edited text :" << endl;
	cout << str;
}