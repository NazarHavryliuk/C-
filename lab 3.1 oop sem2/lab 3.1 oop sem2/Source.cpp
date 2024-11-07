#include<iostream>
#include <vector>;
#include <algorithm>
using namespace std;


class Programa
{
public:
	Programa()
	{
		Size = 0;//створення обєкта у конструкторі
	}
	~Programa();
	void push(int data);//обявлення методу
	void Print();//обявлення методу

	bool operator ==(const Programa& other)//оператор присвоєння
	{
		other.push(10);
		if (this->Size != other.Size)
		{
			return false;//повертає заперечення, якщо масиви різного розміру
		}
		else//перевірка рівночсті елементів масиву
		{
			for (int i = 0; i < Size; i++)
			{
				if (this->ptr[i] != other.ptr[i])
				{
					return false;
				}
			}
		}
		return true;
	}
	void operator =(const Programa& other)//оператор присвоєння 
	{
		delete this->ptr;//видаляє старий вказівник
		this->ptr = new int[other.Size];
		this->Size = other.Size;
		for (int i = 0; i < other.Size; i++)//цикл записування інформації
		{
			this->ptr[i] = other.ptr[i];
		}
	}
	void pop_element();//обявлення методу
	void pop_element(int index);//обявлення перегрузки метода
	friend Programa unit_masiv(Programa& prg1, Programa& prg2);//передача функції прав достопу до приватних полів і функцій
	friend Programa crossing_masiv(Programa& prg1, Programa& prg2);//передача функції прав достопу до приватних полів і функцій

private:
	int* ptr;
	int Size;
};
void menu_start(vector<Programa> &programa);
void menu_start_print();
void menu_work_of_class_print();
void menu_work_of_class(vector<Programa>& programa);
void show_list(vector<Programa>& programa);
void show_list_tabl();
void create_object(vector<Programa>& programa);
void add_element_in_masiv(vector<Programa>& programa);
void delete_object(vector<Programa>& programa);
void assign_object(vector<Programa>& programa);
void equate_masiv(vector<Programa>& programa);
void union_of_sets(vector<Programa>& programa);
void intersection(vector<Programa>& programa);


int main()
{
	int caunte = 0;
	
	vector<Programa>  programa(0);
	vector<Programa>::iterator head;
	head = programa.begin();
	generate(programa.begin(), programa.end(), []() { return Programa(); });
	menu_start(programa);
}

void menu_start_print()
{
	
	cout << "\n\tMenu\n" << endl;
	cout <<
		"1. Work with class\n"
		"0. Exit\n";
}
void menu_start(vector<Programa> &programa)
{
	bool flag = true;
	menu_start_print();

	while (flag) {
		cout << "Enter a number: ";
		int k;
		cin >> k;
		switch (k) {

		case 1:
			menu_work_of_class(programa);
			menu_start_print();
			break;

		case 0:
			exit(0);
			break;
		default:
			cout << "Wrong number" << endl;
			break;
		}
	}
}
void menu_work_of_class_print()
{
	cout << "1. Show list of object " << endl <<
		"2. Create an object " << endl <<
		"3. Add an element to an object" <<endl<<
		"4. Delete object " << endl <<
		"5. To assign " << endl <<
		"6. Equate " << endl <<
		"7. Union of sets " << endl <<
		"8. Intersection of sets " << endl <<
		"0. Exit"<<endl;
		
}

void menu_work_of_class(vector<Programa> &programa)
{
	bool flag = true;

	menu_work_of_class_print();

	while (flag) {
		cout << "Enter a number: ";
		int k;
		cin >> k;
		switch (k) {

		case 1:
			show_list(programa);
			menu_work_of_class(programa);
			break;
		case 2:
			show_list(programa);
			create_object(programa);
			menu_work_of_class(programa);
			break;
		case 3:
			show_list(programa);
			add_element_in_masiv(programa);
			menu_work_of_class(programa);
		case 4:
			show_list(programa);
			delete_object(programa);
			menu_work_of_class(programa);
		case 5:
			show_list(programa);
			assign_object(programa);
			menu_work_of_class(programa);
		case 6:
			show_list(programa);
			equate_masiv(programa);
			menu_work_of_class(programa);
		case 7:
			show_list(programa);
			union_of_sets(programa);
			menu_work_of_class(programa);
		case 8:
			show_list(programa);
			intersection(programa);
			menu_work_of_class(programa);
		case 0:
			exit(0);
			break;
		default:
			cout << "Wrong number" << endl;
			break;
		}
	}
}
void intersection(vector<Programa>& programa)
{
	cout << "Choose the number of the set in which the result will be recorded:";
	int index;
	cin >> index;
	if ((index - 1 < 0) || (index > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	cout << "Enter the number of the sirst set :";
	int index1, index2;
	cin >> index1;
	cout << "Enter the number of the second set :";
	cin >> index2;
	if ((index2 - 1 < 0) || (index2 > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	if ((index1 - 1 < 0) || (index1 > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	programa[index - 1] = crossing_masiv(programa[index1 - 1], programa[index2 - 1]);
}
void union_of_sets(vector<Programa>& programa)
{
	cout << "Choose the number of the set in which the result will be recorded:";
	int index;
	cin >> index;
	if ((index - 1 < 0) || (index > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	cout << "Enter the number of the sirst set :";
	int index1, index2;
	cin >> index1;
	cout << "Enter the number of the second set :";
	cin >> index2;
	if ((index2 - 1 < 0) || (index2 > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	if ((index1 - 1 < 0) || (index1 > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	programa[index - 1] = unit_masiv(programa[index1 - 1], programa[index2 - 1]);
}
void equate_masiv(vector<Programa>& programa)
{
	cout << "Enter the number of the first set :";
	int index1, index2;
	cin >> index1;
	cout << "Enter the number of the second set :";
	cin >> index2;
	if ((index1 - 1 < 0) || (index1 > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	if ((index2 - 1 < 0) || (index2 > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	else
	{
		if (programa[index1 - 1] == programa[index2 - 1])
		{
			cout << "sets of numbers are equal" << endl;
		}
		else
		{
			cout << "sets of numbers are not equal" << endl;
		}
	}
}
void assign_object(vector<Programa>& programa)
{
	cout << "Enter the number of the set to which you want to assign:";
	int index1, index2;
	cin >> index1;
	cout << "Enter the number of the set from which you want to assign:";
	cin >> index2;
	if ((index2 - 1 < 0) || (index2 > programa.size()))
	{
		cout << "There is no object with this index"<< endl;
		return;
	}
	if ((index1 - 1 < 0) || (index1 > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	else
	{
		programa[index1 - 1] = programa[index2 - 1];
		cout << "the operation was successful" << endl;
	}
}
void delete_object(vector<Programa>& programa)
{
	cout << "Enter index";
	int index;
	cin >> index;
	if ((index - 1 < 0) || (index > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	cout << "To confirm(1-yes/0-no)";
	int q;
	cin >>q;
	if ((q - 1 < 0) || (q > programa.size()))
	{
		cout << "There is no object with this index" << endl;
		return;
	}
	else
	{
		programa.erase(programa.begin() + index - 1);
		cout << "deleted" << endl;
	}
}
void add_element_in_masiv(vector<Programa>& programa)
{

	cout << "enter number of set:";
	int index;
	cin >> index;
	if (index > programa.size() + 1)
	{
		cout << "There is no object under this index" << endl;
		return;
	}
	else
	{
		cout << "Enter data:";
		int data;
		cin >> data;
		programa[index - 1].push(data);
		cout << "element added" << endl;
	}
}
void show_list(vector<Programa>& programa)
{
	show_list_tabl();
	for (int i = 0; i < programa.size(); i++)
	{
		cout << "|"<<i+1<<"|";
		programa[i].Print();
		cout << "| |-----------------------------------------------------------------\n";
	}
	

}
void show_list_tabl()
{
	cout << "--------------------------------------------------------------------" << endl
		<< "|#|" << endl
		<< "| |-----------------------------------------------------------------" << endl;
}
void create_object(vector<Programa>& programa)
{

	Programa programa1;
	vector<Programa> programa2(programa.size(),programa1);
	for (int i = 0; i < programa2.size(); i++)
	{
		programa2[i] = programa[i];
	}
	programa.clear();
	for (int i = 0; i < programa2.size()+1; i++)
	{
		programa.push_back(programa1);
	}
	for (int i = 0; i < programa2.size(); i++)
	{
		programa[i] = programa2[i];
	}
	//generate(programa.begin(), programa.end(), []() { return Programa(); });
	/*head = programa.begin();*/
}
Programa::~Programa()//оранізація конструктора
{
	delete[] ptr;
}
void Programa::push(int data)//організація метода додавання елемента в об'єкт
{
	int* ptr2 = ptr;
	for (int i=0; i < Size; i++)
	{
		if (ptr2[i] == data)
		{
			return;
		}
	}
	Size++;
	ptr = new int[Size];
	
	if (ptr2 == nullptr)//інструкція, якщо об'єкт пустий
	{
		ptr[0] = data;
		return;
	}
	if (ptr2[0] > data)//інструкція, якщо об'єкт має 1 елемент
	{
		ptr[0] = data;
		for (int i = 0; i < Size-1; i++)
		{
			ptr[i + 1] = ptr2[i];
		}
		delete[] ptr2;
		return;
	}
	if (ptr2[Size - 2] < data)//інструкція, якщо елемент який хочуть добавити більший за останій елемент
	{
		for (int i=0; i < Size-1; i++)
		{
			ptr[i] = ptr2[i];
		}
		ptr[Size - 1] = data;
		delete[] ptr2;
		return;
	}
	for (int i = 0, j = 0; i < Size; i++, j++)//інструкція, для додавання елемента в середину масива об'єкта
	{
		if ((ptr2[i - 1] < data) && (data <= ptr2[i]))
		{
			ptr[i] = data;
			i++;
		}
		ptr[i] = ptr2[j];
	}
	
}
void Programa::Print()//організація метода виводу масива об'єкта
{
	for (int i = 0; i < Size; i++)
	{
		cout << ptr[i] << " ";
	}
	cout << "\n";
}
void Programa::pop_element()//органцізація видалення елемента з кінця масиву об'єкта
{
	if (Size == 0)
	{
		cout << "object is clear!!!" << endl;
		return;
	}
	int* arr = new int[Size - 1];
	for (int i = 0; i < Size - 1; i++)
	{
		arr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = arr;
	Size--;
}
void Programa::pop_element(int index)//видалення елемента масива об'єкта за його індексом
{
	int* arr = new int[Size - 1];
	int k = Size;
	for (int i = 0, j=0; i < Size; i++, j++)
	{
		if (i == index - 1)
		{
			i++;
		}
		if (i != index - 1)
		{
			arr[j] = ptr[i];
		}
	}
	delete[] ptr;
	this->Size = k - 1;
	ptr = arr;
}
Programa unit_masiv(Programa& prg1, Programa& prg2)//функція об'єднанна масивів об'єктів
{
	Programa temp;
	temp.Size = prg1.Size;
	bool flag = true;
	for (int i = 0; i < prg2.Size; i++)//цикл , який визначає на скільки елементів потрібно створити новий масив
	{
		flag = true;
		for (int j = 0; j < prg1.Size; j++)
		{
			if (prg2.ptr[i] == prg1.ptr[j])
			{
				flag = false;
			}
		}
		if (flag)
		{
			temp.Size++;
		}
	}
	temp.ptr = new int[temp.Size];
	int k = 0;
	for (; k < prg1.Size; k++)//запис першого масиву у головний
	{
		temp.ptr[k] = prg1.ptr[k];
	}
	temp.Size = prg1.Size;
	for (int i = 0; i < prg2.Size; i++)//цикл запису елементів другогомасиву яких не вистачає у говному масиві
	{
		flag = true;
		for (int j = 0; j < prg1.Size; j++)
		{
			if (prg2.ptr[i] == prg1.ptr[j])
			{
				flag = false;
			}

		}
		if (flag)
		{
			temp.push(prg2.ptr[i]);

		}
	}	
	return temp;
}
Programa crossing_masiv(Programa& prg1, Programa& prg2)//функція перетину елементів масивів об'єктів
{
	Programa temp;
	temp.Size = 0;
	for (int i = 0; i < prg2.Size; i++)//цикл визкачає на скільки елементів потрібно створити масив головного об'єкта
	{
		for (int j = 0; j < prg1.Size; j++)
		{
			if (prg2.ptr[i] == prg1.ptr[j])
			{
				temp.Size++;
			}
		}
	}
	temp.ptr = new int[temp.Size];
	temp.Size = 0;
	for (int i = 0; i < prg2.Size; i++)//цикл запису елементів масивів об'єктів, які є в обох масивах
	{
		for (int j = 0; j < prg1.Size; j++)
		{
			if (prg2.ptr[i] == prg1.ptr[j])
			{
				temp.push(prg2.ptr[i]);
			}
		}
	}
	return temp;
}