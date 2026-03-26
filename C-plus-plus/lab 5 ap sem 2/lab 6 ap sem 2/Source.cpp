#include<iostream>
#include<string>

using namespace std;

template<typename T>
class Tree
{
public:
	Tree();
	~Tree();
	void push(T data);
	T SearchMinElement();


private:
	template<typename T>
	class Node
	{
	public:
		Node<T>* pleft;
		Node<T>* pright;
		int balance;
		T data;
		Node(T data = T(), Node<T>* pleft = nullptr, Node<T>* pright = nullptr, int balance = 0)
		{
			this->pleft = pleft;
			this->pright = pright;
			this->data = data;
			this->balance = balance;
		}
	};
	Node<T>* head;



	int Height(Node<T>* ptr);
	void SetBalance(Node<T>* ptr);
	void TurnLeft(Node<T>* (&ptr));
	void TurnRight(Node<T>* (&ptr));
	void insert(Node<T>* (&ptr), T data);
	void pop_l(Node<T>* ptr);
	void SearchMinElementProces(Node<T>* ptr, T& numeric);
};
int main()
{
	Tree<int> lst;
	lst.push(10);
	lst.push(7);
	lst.push(13);
	lst.push(15);
	lst.push(12);
	lst.push(17);
	lst.push(25);

	cout << lst.SearchMinElement() << endl;


	return 0;
}

template<typename T>
int Tree<T>::Height(Node<T>* ptr)
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
void Tree<T>::SetBalance(Node<T>* ptr)
{
	if (ptr != nullptr)
	{
		ptr->balance = Height(ptr->pright) - Height(ptr->pleft);

	}
}
template<typename T>
void Tree<T>::TurnRight(Node<T>* (&ptr))
{
	if (ptr == nullptr)
	{
		return;
	}
	Node<T>* current1 = ptr->pleft;
	Node<T>* current2 = current1->pright;
	current1->pright = ptr;
	ptr->pleft = current2;
	ptr = current1;

	SetBalance(current1);
	SetBalance(current1->pright);

}
template<typename T>
void Tree<T>::insert(Node<T>* (&ptr), T data)
{
	if (ptr == nullptr)
	{
		cout << "constructor for data: " << data << endl;
		ptr = new Node<T>(data);
	}
	else
	{

		if (data > ptr->data)
		{
			insert(ptr->pright, data);
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
			insert(ptr->pleft, data);
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
void Tree<T>::TurnLeft(Node<T>* (&ptr))
{
	if (ptr == nullptr)
	{
		return;
	}
	Node<T>* current1 = ptr->pright;
	Node<T>* current2 = current1->pleft;
	current1->pleft = ptr;
	ptr->pright = current2;
	ptr = current1;
	SetBalance(current1);
	SetBalance(current1->pright);

}
template<typename T>
Tree<T>::Tree()
{
	head = nullptr;
}
template<typename T>
Tree<T>::~Tree()
{
	pop_l(head);
	head = nullptr;
}

template<typename T>
void Tree<T>::push(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		insert(head, data);
	}
}

template<typename T>
T Tree<T>::SearchMinElement()
{
	T numeric = 100000;
	SearchMinElementProces(head, numeric);
	return numeric;
}

template<typename T>
void Tree<T>::pop_l(Node<T>* ptr)
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
	cout << "destructor for " << ptr->data << endl;
	delete ptr;
}

template<typename T>
void Tree<T>::SearchMinElementProces(Node<T>* ptr, T& numeric)
{
	if (ptr->pleft != nullptr)
	{
		SearchMinElementProces(ptr->pleft, numeric);
	}
	if (ptr->pright != nullptr)
	{
		SearchMinElementProces(ptr->pright, numeric);
	}
	if (ptr->data < numeric)
	{
		numeric = ptr->data;
	}
}
