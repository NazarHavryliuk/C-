#include<iostream>
#include<ctime>
#include <cstdlib>
#include<string>
#include <locale>

using namespace std;


void main()
{
	setlocale(LC_ALL, "ukraine");
	string str;
	getline(cin, str);
	int size;
	size = str.length();
	int number_of_words=1;
	for (int i = 0; i < size; i++)
	{
		if (str[i] == ' ')
		{
			number_of_words++;
		}
	}
	char** arr = new  char*[number_of_words] {};
	int nwords = 0;
	int a = 0, b = 0;
	for (int i = 0; i < size; i++)
	{
		
		if (str[i] == ' ')
		{   
			b = i;
			arr[nwords] = new char[b - a + 2] {};
			int k;
			for (int j = 0; j<b-a; j++)
			{
				arr[nwords][j] = str[a + j];
				k = j;
			}
			arr[nwords][k+1] = ' ';
			nwords++;
			a = b + 2;
		}
	}
	for (int i = 0; i <= number_of_words + 1; i++)
	{
		swap(arr[i], arr[number_of_words-i]);
	}
	for (int i = 0; i < number_of_words; i++)
	{
		for (int j = 0; arr[i][j] != ' '; j++)
		{
			cout << arr[i][j] << endl;
		}
	}
	for (int j = 0; j < number_of_words; j++)
	{
		delete[] arr[j];
	}
	delete[] arr;
	cout << endl;
	
}