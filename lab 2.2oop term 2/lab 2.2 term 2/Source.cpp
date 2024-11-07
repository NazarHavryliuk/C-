#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include <iomanip>
#include <algorithm>


using namespace std;

class Sclad
{
public:
	Sclad();
	void change_el(int iterat, const char * procesor_type = "", double frequency = 0, const char * type_of_motherboard = "", double cost = 0)
	{
		masiv[iterat - 1].procesor_type = procesor_type;
		masiv[iterat - 1].frequency = frequency;
		masiv[iterat - 1].type_of_motherboard = type_of_motherboard;
		masiv[iterat - 1].cost = cost;
	}
	void Print_Procesors_info()
	{
		Print_Procesor_tabl();
		for (int i = 0; i < Size; i++) {
			cout << "| " <<
				setw(2) << left << i + 1 << "| " <<

				setw(29) << left << masiv[i].procesor_type<< "| " <<
				setw(10) << left << masiv[i].frequency << "| " <<
				setw(30) << left << masiv[i].type_of_motherboard << "| " <<
				setw(10) << left << masiv[i].cost << "| " << endl;

		}
		cout << "____________________________________________________________________________________________\n" << endl;
	}
	
	void Print_Procesor_tabl()
	{
		cout << "____________________________________________________________________________________________" << endl;
		cout << "| # |" <<

			setw(30) << left << "procesor_type" << "| " <<
			setw(10) << left << "frequency" << "| " <<
			setw(30) << left << "type_of_motherboard" << "| " <<
			setw(10) << left << "cost" << "| " << endl;

		cout << "|___|______________________________|___________|_______________________________|___________|" << endl;
	}
	void pop_element(int iterato)
	{
		if (iterato > Size)
		{
			cout << "error" << endl;
			return;
		}
		int i = 0;
		for (; i!=iterato-1; i++)
		{
		}
		masiv[i] = Procesor();
		sort_sclad();
		Size--;
	}
	void sort_sclad()
	{
		for (int i = 0; i < Size-1; i++)
		{
			for (int j = 0; j < Size-1; j++)
			{
				if (masiv[j].cost < masiv[j + 1].cost)
				{
					swap(masiv[j], masiv[j + 1]);
				}
			}
		}
	}
	void search_type_of_motherboard(const char * data);
	void push_back(const char * procesor_type="", double frequency=0, const char * type_of_motherboard="", double cost = 0);
	void print_element_number(int index);
private:
	class Procesor
	{
	public:
		const char* procesor_type;
		double frequency;
		const char * type_of_motherboard;
		double cost;
		Procesor(const char * procesor_type=nullptr, double frequency=0, const char * type_of_motherboard=nullptr, double cost=0)
		{
			this->procesor_type = procesor_type;
			this->frequency = frequency;
			this->type_of_motherboard = type_of_motherboard;
			this->cost = cost;
		}
		~Procesor()
		{
			this->procesor_type = "";
			this->frequency = 0;
			this->type_of_motherboard = "type_of_motherboard";
			this->cost = 0;
		}
		Procesor& operator = (Procesor* object)
		{
			this->cost = object->cost;
			this->frequency= object->frequency;
			this->procesor_type = object->procesor_type;
			this->type_of_motherboard = object->type_of_motherboard;
		}
	};
	int Size;
	Procesor* mymasiv;
	const int max_Size=10;

	Procesor masiv[10];
};

int main()
{
	Sclad sclad;
	
	sclad.push_back("6 cores / 12 threads", 3.7, "AMD AM4", 7500);
	sclad.push_back("6 cores / 12 threads", 2.5, "Intel LGA 1700", 6000);
	sclad.push_back("8 cores / 12 threads", 3.4, "AMD AM4", 12000);
	sclad.push_back("12 cores / 20 threads", 3.4, "AMD AM4", 20000);
	sclad.change_el(1, "12 cores / 20 threads", 3.4, "AMD AM4", 20000);
	sclad.pop_element(5);
	sclad.sort_sclad();
	sclad.Print_Procesors_info();
	sclad.search_type_of_motherboard("AMD AM4");
	sclad.print_element_number(1);
}

Sclad::Sclad()
{
	this->Size = 0;
}

void Sclad::search_type_of_motherboard(const char * data)
{
	Print_Procesor_tabl();
	int k = 1;
	for (int i = 0; i < Size; i++)
	{
		 string str1= data, str2 = masiv[i].type_of_motherboard;
		transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
		transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
		if (str1 == str2)
		{

			cout << "| " <<
				setw(2) << left << k << "| " <<

				setw(29) << left << masiv[i].procesor_type << "| " <<
				setw(10) << left << masiv[i].frequency << "| " <<
				setw(30) << left << masiv[i].type_of_motherboard << "| " <<
				setw(10) << left << masiv[i].cost << "| " << endl;
			k++;
		}
	}
	cout << "|___|______________________________|___________|_______________________________|___________|" << endl;
}

void Sclad::push_back(const char * procesor_type, double frequency, const char * type_of_motherboard, double cost)
{
	if (Size == max_Size)
	{
		cout << "has no place in the composition" << endl;
		return;
	}
	masiv[Size] = Procesor(procesor_type, frequency, type_of_motherboard, cost);
	Size++;
}
void Sclad::print_element_number(int index)
{
	if ((index < 1) || (index > Size))
	{
		cout << "error" << endl;
		return;
	}
	else
	{
		
			Print_Procesor_tabl();
				cout << "| " <<
					setw(2) << left << index << "| " <<

					setw(29) << left << masiv[index-1].procesor_type << "| " <<
					setw(10) << left << masiv[index-1].frequency << "| " <<
					setw(30) << left << masiv[index-1].type_of_motherboard << "| " <<
					setw(10) << left << masiv[index-1].cost << "| " << endl;

			cout << "____________________________________________________________________________________________\n" << endl;
		
	}
}
