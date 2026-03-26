#include<iostream>
#include<string>

using namespace std;

template<typename T,typename T2>
class List
{
public:
	List();
	~List();
	int push_back(T key ,T2 data);
	void pow_list_to(T key);
	void pop_obj(T2 data)
	{
		Node<T, T2>* ptr = head;
		pop_obj_el(ptr, data);
	}
	

private:
	template<typename T, typename T2>
	class Node
	{
	public:
		Node<T,T2>* pleft;
		Node<T,T2>* pright;
		T key;
		T2 data;
		Node(T key = T(),T2 data=T2(), Node<T,T2>* pleft = nullptr, Node<T,T2>* pright = nullptr)
		{
			this->key = key;
			this->pleft = pleft;
			this->pright = pright;
			this->data = data;
		}

	};
	Node<T,T2>* head;
	void PrintElements(Node<T,T2>* ptr);
	void pop_obj_el(Node<T,T2>*ptr ,T2 data);

public:
	void pop_l(Node<T,T2>* ptr);
	void pop_element(Node<T,T2>* ptr, int k = 0);
	void PrintList();

};
int main()
{
	List<int,string> lst;
	lst.push_back(50,"fdr");
	lst.push_back(25,"qqq");
	lst.push_back(10,"ED");
	lst.push_back(15,"eee");
	lst.push_back(55,"rrr");
	cout << "_______________" << endl;
	lst.PrintList();
	lst.pop_obj("ED");
	lst.PrintList();
}

template<typename T,typename T2>
List<T,T2>::List()
{
	head = nullptr;
}
template<typename T, typename T2>
List<T,T2>::~List()
{
	pop_l(head);
	head = nullptr;
}

template<typename T, typename T2>
int List<T,T2>::push_back(T key,T2 data)
{

	if (head == nullptr)
	{
		head = new Node<T,T2>(key,data);
		cout << "constructor for " << key << endl;
	}
	else
	{
		Node<T,T2>* current = head;
		while (1 > 0)
		{

			if (key < current->key)
			{
				if (current->pleft == nullptr)
				{
					current->pleft = new Node<T,T2>(key,data);
					cout << "constructor for "<< key << endl;
					return 0;
				}
				else
				{
					current = current->pleft;
				}
			}
			if (key > current->key)
			{
				if (current->pright == nullptr)
				{
					current->pright = new Node<T,T2>(key,data);
					cout << "constructor for "<<key << endl;
					return 0;
				}
				else
				{
					current = current->pright;
				}
			}
			if ((key < current->key) && (key > current->key))
			{
				cout << "such an element already exists" << endl;
			}
		}
	}
	return 0;
}



template<typename T, typename T2>
void List<T,T2>::pow_list_to(T key)
{
	Node<T,T2>* ptr1 = head;
	Node<T,T2>* ptr2 = head;
	int i = 0;
	while (ptr2->key != key)
	{
		if (ptr1->key > key)
		{
			i = 1;
			ptr2 = ptr1->pleft;
			if (ptr2->key != key)
			{
				ptr1 = ptr2;
			}
		}
		if (ptr1->key < key)
		{
			i = 2;
			ptr2 = ptr1->pright;
			if (ptr2->key != key)
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
	pop_element(ptr2, 0);
}




template<typename T,typename T2>
void List<T,T2>::PrintList()
{

	Node<T, T2>* ptr =head;

	PrintElements(ptr);
}
template<typename T, typename T2>
void List<T, T2>::pop_obj_el(Node<T, T2>* ptr, T2 data)
{
	if (ptr->pleft != nullptr)
	{
		pop_obj_el(ptr->pleft, data);
	}
	if (ptr->pright != nullptr)
	{
		pop_obj_el(ptr->pright, data);
	}
	if (data == ptr->data)
	{
		pow_list_to(ptr->key);
		return;
	}
}

template<typename T,typename T2>
void List<T,T2>::PrintElements(Node<T,T2>* ptr)
{
	if (ptr->pleft != nullptr)
	{
		PrintElements(ptr->pleft);
	}
	if (ptr->pright != nullptr)
	{
		PrintElements(ptr->pright);
	}
	cout << ptr->data << endl;
}
template<typename T, typename T2>
void List<T,T2>::pop_l(Node<T,T2>* ptr)
{
	if (ptr->pleft != nullptr)
	{
		pop_l(ptr->pleft);
		ptr->pleft = nullptr;
	}
	if (ptr->pright != nullptr)
	{
		pop_l(ptr->pright);
		ptr->pright = nullptr;
	}
	cout << "destructor for " << ptr->key << endl;
	delete ptr;
}

template<typename T, typename T2>
void List<T,T2>::pop_element(Node<T,T2>* ptr, int k)
{
	if (ptr->pleft != nullptr)
	{
		pop_element(ptr->pleft, 1);
		ptr->pleft = nullptr;
	}
	if (ptr->pright != nullptr)
	{
		pop_element(ptr->pright, 1);
		ptr->pright = nullptr;
	}
	if (k != 0)
	{
		cout << "---";
		push_back(ptr->key,ptr->data);
	}
	cout << "___destructor for " << ptr->key << endl;
	delete ptr;
}
