#include <iostream>
#include <string>
using namespace std;
class HashTable
{
	class List
	{
		
	public:
		class Node
		{
		public:
			string key;
			shared_ptr<Node> next;
			string data;
			Node(string str,string data)
			{
				this->key = str;
				this->next = nullptr;
				this->data = data;
			}
		};
		List()
		{
			head = nullptr;
		}
		shared_ptr<Node> head;
		void insertNod(string key,string data);
		void insertNode(string key,string data,shared_ptr<Node> &ptr);
		void searchLis(string key);
		void searchList(string key, shared_ptr<Node>& ptr)
		{
			if (ptr == nullptr)
			{
				cout << "don't searched" << endl;
				return;
			}
			if (ptr->key == key)
			{
				cout << ptr->data << endl;
			}
			else
			{

				searchList(key, ptr->next);

			}
		}
		void print(shared_ptr<Node> ptr);

	};
	const int Size = 10;
	List list[10];
public:
	void insert(string key,string data);
	void search(string key);
	void display();
};
int main()
{
	HashTable tbl;
	tbl.insert("111","The Hitchhiker's Guide to the Galaxy");
	tbl.insert("112","The Lord of the Rings");
	tbl.insert("113","Harry Potter and the Sorcerer's Stone");
	tbl.insert("114","The Little Prince");
	tbl.insert("115","To Kill a Mockingbird");
	tbl.insert("116","Pride and Prejudice");
	tbl.insert("117","It");
	tbl.insert("118","The Catcher in the Rye");
	tbl.insert("119","The Catcher in the Rye");
	tbl.insert("120","Animal Farm");
	tbl.search("120");
	tbl.display();
}

void HashTable::insert(string key,string data)
{
	int number = 0;
	for (auto h : key)
	{
		number = number + (h - '0');
	}
	list[number % 10].insertNod(key,data);
}

void HashTable::List::insertNod(string key,string data)
{
	if (head == nullptr)
	{
		head.reset(new Node(key,data));
	}
	else
	{
		insertNode(key,data, head);
	}
}

void HashTable::List::insertNode(string key,string data, shared_ptr<Node> &ptr)
{
	if (ptr == nullptr)
	{
		ptr.reset(new Node(key,data));
	}
	else
	{
		insertNode(key,data, ptr->next);
	}
}
void HashTable::search(string key)
{
	int number = 0;
	for (auto h : key)
	{
		number = number + (h - '0');
	}
	list[number % 10].searchLis(key);
}

void HashTable::List::searchLis(string key)
{
	searchList(key, head);
}
void HashTable::display()
{
	int i = 1;
	for (auto q : list)
	{
		cout << i;
		
		q.print(q.head);
		cout << endl;
		i++;
	}
}
void HashTable::List::print(shared_ptr<Node> ptr)
{
	if (ptr == nullptr)
	{
		cout << endl;
		return;
	}
	else
	{
		cout << "[" << ptr->key << "," << ptr->data << "]  ";
		print(ptr->next);
	}
}

