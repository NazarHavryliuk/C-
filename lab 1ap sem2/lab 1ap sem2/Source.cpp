#include<iostream>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void  push_back(T data);
	int GetSize();
	void pop_front();
	void clear();
	void pop_back();
	T& operator [](const int index);
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}

	};
	Node<T>* head;
	Node<T>* tail;
	int Size;
};
int main()
{
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	lst.pop_back();
	lst.pop_back();
	cout << "-----------------------------" << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
}

template<typename T>
List<T>::List()
{
	head = tail = nullptr;
	Size = 0;
}
template<typename T>
List<T>::~List()
{
	clear();
	head = tail = nullptr;

}
template<typename T>
void  List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
		tail = head;
		Size++;
	}
	else
	{
		Node<T>* current = tail;
		tail = tail->pNext;
		tail = new Node<T>(data);
		current->pNext = tail;
		tail->pPrev = current;
		Size++;
	}
}
template<typename T>
int List<T>::GetSize()
{
	return this->Size;
}
template<typename T>
void List<T>::pop_front()
{
	if ((head->pNext == nullptr) && (head->pPrev == nullptr))
	{
		cout << "destructor for " << head->data << endl;
		delete head;
		head = tail = nullptr;
		Size--;
	}
	else
	{
		Node<T>* current = head;
		head = head->pNext;
		cout << "destructor for data " << current->data << endl;
		delete current;
		head->pPrev = nullptr;
		Size--;
	}

}
template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}
template<typename T>
void List<T>::pop_back()
{
	if ((head->pNext == nullptr) && (head->pPrev == nullptr))
	{
		cout << "destructor for " << head->data << endl;
		delete head;
		head = tail = nullptr;
		Size--;
	}
	else
	{
		Node<T>* current = tail;
		tail = tail->pPrev;
		cout << "destructor for data " << current->data << endl;
		delete current;
		tail->pNext = nullptr;
		Size--;
	}

}
template<typename T>
T& List<T>::operator [](const int index)
{
	int id = 0;
	Node<T>* current = head;
	while (current != nullptr)
	{
		if (index == id)
		{
			return current->data;
		}
		id++;
		current = current->pNext;
	}
}