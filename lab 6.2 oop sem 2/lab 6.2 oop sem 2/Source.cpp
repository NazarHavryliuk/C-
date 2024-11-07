#include <iostream>
#include <string>
#include<vector>
#include<memory>
#include<fstream>
#include <algorithm>
#include <iomanip>

using namespace std;
void StartMenu();
void StartMenuInfo();
void ProgramMenuInfo();
void ProgramTabl();


template<typename T>
class List
{
public:
	List();
	~List();
	void push(T data, int r);

	void StartWork();
	void SearchWord();
	void pop_obj()
	{
		cout << "Enter word ";
		string data;
		cin >> data;
		bool fl = false;
		if (data == "")
		{
			cout << "error";
			return;
		}

		shared_ptr<Node<T>> ptr = head;
		PopElement(ptr, data, fl);
		if (!fl)
		{
			cout << "Word don`t searched" << endl;
		}
	}


private:
	template<typename T>
	class Node
	{
	public:
		shared_ptr<Node<T>> pleft;
		shared_ptr<Node<T>> pright;
		int balance;
		T data;
		vector<int> pages;
		Node(T data = T(), shared_ptr<Node<T>> pleft = nullptr, shared_ptr<Node<T>> pright = nullptr, int balance = 0)
		{
			this->pleft = pleft;
			this->pright = pright;
			this->data = data;
			this->balance = balance;
		}
	};
	shared_ptr<Node<T>> head;



	int Height(shared_ptr<Node<T>> ptr);
	void SetBalance(shared_ptr<Node<T>> ptr);
	void TurnLeft(shared_ptr<Node<T>>(&ptr));
	void TurnRight(shared_ptr<Node<T>>(&ptr));
	void insert(shared_ptr<Node<T>>(&ptr), T data, int r);

	void ReadPage(string page, int r);
	void PrintInfoAboutAllWords(shared_ptr<Node<T>> ptr);
	void PopElement(shared_ptr<Node<T>> ptr, int k);
public:
	void PrintInfoAboutWord(shared_ptr<Node<T>> ptr, string word, bool& fl);
	void ShowAllWords();
	void PopElement(shared_ptr<Node<T>> ptr, T data, bool& fl);
	void PopListTo(T data);

};

template<typename T>
int List<T>::Height(shared_ptr<Node<T>> ptr)
{
	if (ptr == nullptr)
	{
		return 0;
	}
	int  hLeft = Height(ptr->pleft), hRight = Height(ptr->pright);
	if (hLeft > hRight)
	{
		return hLeft + 1;
	}
	else
	{
		return hRight + 1;
	}

}
template<typename T>
void List<T>::SetBalance(shared_ptr<Node<T>> ptr)
{
	if (ptr != nullptr)
	{
		ptr->balance = Height(ptr->pright) - Height(ptr->pleft);
	}
}
template<typename T>
void List<T>::TurnRight(shared_ptr<Node<T>>(&ptr))
{
	if (ptr == nullptr)
	{
		return;
	}
	shared_ptr<Node<T>> current1 = ptr->pleft;
	shared_ptr<Node<T>> current2 = current1->pright;
	current1->pright = ptr;
	ptr->pleft = current2;
	ptr = current1;

	SetBalance(current1);
	SetBalance(current1->pright);

}
template<typename T>
void List<T>::insert(shared_ptr<Node<T>>(&ptr), T data, int r)
{
	if ((ptr != nullptr))
	{
		if (ptr->data == data)
		{
			for (int i = 0; i < ptr->pages.size(); i++)
			{
				if (ptr->pages[i] == r)
				{
					return;
				}

			}
			ptr->pages.push_back(r);
			return;
		}
	}
	if (ptr == nullptr)
	{
		//cout << "constructor for data " << data << endl;
		ptr.reset(new Node<T>(data));
		ptr->pages.push_back(r);
	}
	else
	{

		if (data > ptr->data)
		{
			insert(ptr->pright, data, r);
			if (Height(ptr->pright) - Height(ptr->pleft) > 1)
			{
				if (Height(ptr->pright->pright) < Height(ptr->pright->pleft))
				{
					TurnRight(ptr->pright);
				}
				TurnLeft(ptr);
			}
		}
		else
		{
			insert(ptr->pleft, data, r);
			if (Height(ptr->pleft) - Height(ptr->pright) > 1)
			{
				if (Height(ptr->pleft->pleft) < Height(ptr->pleft->pright))
				{
					TurnLeft(ptr->pleft);
				}
				TurnRight(ptr);
			}
		}
		SetBalance(ptr);
	}
}
template<typename T>
void List<T>::TurnLeft(shared_ptr<Node<T>>(&ptr))
{
	if (ptr == nullptr)
	{
		return;
	}
	shared_ptr<Node<T>> current1 = ptr->pright;
	shared_ptr<Node<T>> current2 = current1->pleft;
	current1->pleft = ptr;
	ptr->pright = current2;
	ptr = current1;
	SetBalance(current1);
	SetBalance(current1->pright);

}
template<typename T>
List<T>::List()
{
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
	//pop_l(head);
	//head = nullptr;
}

template<typename T>
void List<T>::push(T data, int r)
{
	if (head == nullptr)
	{
		//cout << "constructor for data " << data << endl;
		head.reset(new Node<T>(data));
		head->pages.push_back(r);
	}
	else
	{
		insert(head, data, r);
	}
}



template<typename T>
void ProgramMenu(List<T> tree)
{

	bool flag = true;

	ProgramMenuInfo();

	while (flag) {
		cout << "Enter a number: ";
		int k;
		cin >> k;
		switch (k) {

		case 1:
			tree.SearchWord();
			ProgramMenu(tree);
			break;
		case 2:
			tree.ShowAllWords();
			ProgramMenu(tree);
			break;
		case 3:
			tree.ShowAllWords();
			tree.pop_obj();
			ProgramMenu(tree);
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
void StartMenu()
{
	List<string> tree;
	tree.StartWork();
	{
		bool flag = true;

		StartMenuInfo();

		while (flag) {
			cout << "Enter a number: ";
			int k;
			cin >> k;
			switch (k) {

			case 1:

				ProgramMenu(tree);
				StartMenu();
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
}
int main()
{
	StartMenu();
}
void StartMenuInfo()
{
	cout << "1. Start vork with program " << endl <<
		"0. Exit" << endl;
}

void 	ProgramMenuInfo()
{

	cout << "1.Search a word " << endl <<
		"2. Show all words" << endl <<
		"3. Pop word " << endl <<
		"0. Exit" << endl;
}


template<typename T>
void List<T>::ReadPage(string pageName, int r)
{
	string q;
	ifstream page(pageName, ios::in);
	if (!page.is_open())
	{
		cout << "This file does not exist!\n" << endl;
	}
	else
	{

		while (page >> q)
		{

			if ((q.back() == '.') || (q.back() == ',') || (q.back() == '!') || (q.back() == '?'))
			{
				q.pop_back();
			}
			transform(q.begin(), q.end(), q.begin(), ::tolower);
			push(q, r);
		}
	}
	page.close();
}
template<typename T>
void List<T>::PrintInfoAboutWord(shared_ptr<Node<T>> ptr, string word, bool& fl)
{
	if (ptr->pleft != nullptr)
	{
		PrintInfoAboutWord(ptr->pleft, word, fl);

	}
	if (ptr->pright != nullptr)
	{
		PrintInfoAboutWord(ptr->pright, word, fl);
	}
	if (ptr->data == word)
	{
		fl = true;
		cout << "|" <<
			setw(30) << left << ptr->data << "| ";
		for (int i = 0; i < ptr->pages.size(); i++)
		{
			cout << ptr->pages[i] << " ";
		}
		cout << endl;
		cout << "|____________________________________________________________________________________________|\n" << endl;
	}
}
template<typename T>
void List<T>::ShowAllWords()
{
	ProgramTabl();
	PrintInfoAboutAllWords(head);
}
template<typename T>
void List<T>::PrintInfoAboutAllWords(shared_ptr<Node<T>> ptr)
{
	if (ptr->pleft != nullptr)
	{
		PrintInfoAboutAllWords(ptr->pleft);

	}
	if (ptr->pright != nullptr)
	{
		PrintInfoAboutAllWords(ptr->pright);
	}
	cout << "|" <<
		setw(30) << left << ptr->data << "| ";
	for (int i = 0; i < ptr->pages.size(); i++)
	{
		cout << ptr->pages[i] << " ";
	}
	cout << endl;
	cout << "|____________________________________________________________________________________________|" << endl;

}
template<typename T>
void List<T>::StartWork()
{
	int r = 1;
	string page1 = "page 1.txt";
	ReadPage(page1, r);
	r++;
	page1 = "page 2.txt";
	ReadPage(page1, r);
	r++;
	page1 = "page 3.txt";
	ReadPage(page1, r);
	r++;
	page1 = "page 4.txt";
	ReadPage(page1, r);
	r++;
	page1 = "page 5.txt";
	ReadPage(page1, r);
	r++;
	page1 = "page 6.txt";
	ReadPage(page1, r);
	r++;
	page1 = "page 7.txt";
	ReadPage(page1, r);
	r++;
	page1 = "page 8.txt";
	ReadPage(page1, r);
	r++;
	page1 = "page 9.txt";
	ReadPage(page1, r);
	r++;
	page1 = "page 10.txt";
	ReadPage(page1, r);
}


void ProgramTabl()
{
	cout << "______________________________________________________________________________________________" << endl;
	cout <<

		setw(31) << left << "|Word" << "| " <<
		setw(60) << left << "Pagees where the word occurs " <<
		setw(1) << left << "|" << endl;
	cout << "|____________________________________________________________________________________________|" << endl;
}
template<typename T>
void List<T>::SearchWord()
{
	cout << "Enter a word: ";
	string str;
	cin >> str;
	bool fl = false;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	ProgramTabl();
	PrintInfoAboutWord(head, str, fl);
	if (!fl)
	{
		cout << "Word don`t searched!" << endl;
	}
}

template<typename T>
void List<T>::PopElement(shared_ptr<Node<T>> ptr, T data, bool& fl)
{
	if (ptr->pleft != nullptr)
	{
		PopElement(ptr->pleft, data, fl);
	}
	if (ptr->pright != nullptr)
	{
		PopElement(ptr->pright, data, fl);
	}
	if (data == ptr->data)
	{
		fl == true;
		PopListTo(ptr->data);
		return;
	}
}

template<typename T>
void List<T>::PopListTo(T data)
{
	shared_ptr<Node<T>> ptr1 = head;
	shared_ptr<Node<T>> ptr2 = head;
	int i = 0;
	while (ptr2->data != data)
	{
		if (ptr1->data > data)
		{
			i = 1;
			ptr2 = ptr1->pleft;
			if (ptr2->data != data)
			{
				ptr1 = ptr2;
			}
		}
		if (ptr1->data < data)
		{
			i = 2;
			ptr2 = ptr1->pright;
			if (ptr2->data != data)
			{
				ptr1 = ptr2;
			}
		}
	}
	if (i == 0)
	{
		head = nullptr;
	}
	if (i == 1)
	{
		ptr1->pleft = nullptr;
	}
	if (i == 2)
	{
		ptr1->pright = nullptr;
	}
	PopElement(ptr2, 0);
}
template<typename T>
void List<T>::PopElement(shared_ptr<Node<T>> ptr, int k)
{
	if (ptr->pleft != nullptr)
	{
		PopElement(ptr->pleft, 1);
		ptr->pleft = nullptr;
	}
	if (ptr->pright != nullptr)
	{
		PopElement(ptr->pright, 1);
		ptr->pright = nullptr;
	}
	if (k != 0)
	{
		for (int i = 0; i < ptr->pages.size(); i++)
		{
			push(ptr->data, ptr->pages[i]);
		}
	}
	//cout << "___destructor for " << ptr->data << endl;
}
