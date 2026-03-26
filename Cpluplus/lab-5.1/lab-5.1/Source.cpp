#include<iostream>
#include<ctime>
#include <cstdlib>
#include<string>
#include <locale>

using namespace std;


void main()
{
	setlocale(LC_ALL, "ukraine");
	string name1;
	string name2;
	string name3;
	cin >> name1;
	cin >> name2;
	cin >> name3;
	cout << name1[0] << ". " << name2[0] << ". " << name3[0] << ". ";
}