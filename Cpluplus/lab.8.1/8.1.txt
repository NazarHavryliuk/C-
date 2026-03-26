#include<iostream>
#include<ctime>
#include <cstdlib>
#include<string>
#include <locale>
#include<cmath>
#include<fstream>
#include <iomanip>
#include <algorithm>
#include <ccType>
#include <windows.h>

using namespace std;
string file_name = "people.txt";

int const max_people = 100;


struct people {
	string lastname;
	string firstname;
};


void search_name(people* people_arr, int& people_num);
void go_to_program();
void menu_start_print();
void menu_start();
void read_file_people(people* people_arr, int& people_num);
void show_people(people* people_arr, int& people_num);
void print_info();

int main()
{
	setlocale(LC_CTYPE, "ukraine");
	go_to_program();
	return 0;
}


void go_to_program()
{
	menu_start();
}


void menu_start_print()
{
	cout << "1. Show list" << endl;
	cout << "2. Serch name" << endl;
	cout << "3. exit" << endl;
}

void menu_start()
{
	people people_arr[max_people];
	int people_num = 0;

	menu_start_print();

	bool flag = true;

	while (flag)
	{
		cout << "enter number ";
		int k;
		cin >> k;
		switch (k)
		{
		case 1:
			read_file_people(people_arr, people_num);
			show_people(people_arr, people_num);
			menu_start_print();
			break;
		case 2:
			search_name(people_arr, people_num);
			menu_start_print();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "\nWrong number!" << endl;
			break;
		}
	}
}

void read_file_people(people* people_arr, int& people_num)
{
	ifstream in_file(file_name, ios::in);
	if (!in_file.is_open())
	{
		cout << "This file does not open" << endl;
	}
	else
	{
		int i = 0;
		while (in_file >> people_arr[i].lastname >> people_arr[i].firstname)
		{
			i++;
		}
		people_num = i;
	}
	in_file.close();
}
void print_info()
{
	cout << "_______________________________________________________________________________________" << endl;
	cout << "|    |" <<
		setw(20) << left << "last name" << "| " <<
		setw(20) << left << "first name" << "| " << endl;
	cout << "_______________________________________________________________________________________" << endl;
}
void show_people(people* people_arr, int& people_num)
{
	print_info();
	for (int i = 0; i < people_num; i++)
	{
		cout << "| " <<
			setw(20) << left << people_arr[i].lastname << "| " <<
			setw(20) << left << people_arr[i].firstname << "| " << endl;
		cout << "_______________________________________________________________________________________" << endl;
	}
}
void search_name(people* people_arr, int& people_num)
{
	cout << "\n\tSearch for people by name\n" << endl;
	read_file_people(people_arr, people_num);

	string Name;
	string s;
	int k = 0;
	cout << "Enter the name ";
	cin >> s;

	transform(s.begin(), s.end(), s.begin(), ::tolower);
	print_info();
	for (int i = 0; i < people_num; i++)
	{
		string name = people_arr[i].firstname;
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		if (s == name)
		{
			cout << "| " <<
				setw(2) << left << i + 1 << "| " <<
				setw(20) << left << people_arr[i].lastname << "| " <<
				setw(20) << left << people_arr[i].firstname << "| " << endl;
			k++;
			Name = people_arr[i].firstname;
		}
	}

	if (k == 0)
	{
		cout << "No data" << endl;
	}
	else
	{
		cout << "The number of students with a name " << Name << " is " << k << endl;
	}
	cout << "_______________________________________________________________________________________" << endl;
}