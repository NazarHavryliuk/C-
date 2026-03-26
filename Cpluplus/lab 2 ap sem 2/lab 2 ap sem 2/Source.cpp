#include<iostream>

using namespace std;

template<typename T>
class Steck
{
public:
	Steck();
	void push_back(T data);
	void pop_back();
	void clear();
	~Steck();
	T Getdata_head();
	void print_steck();
	

private:
	template<typename T>
	class Node
	{
	public:
		T data;
		Node<T>* pPrev;
		Node(T data = T(), Node<T>* pPrev = nullptr)
		{
			this->data = data;
			this->pPrev = pPrev;
		}
	};
	
	
	Node<T>* head;
	int Size = 0;
public:
	Node<T>* Get_ip_head()
	{
		return head;
	}
};

int main()
{
	Steck<int> steck;
	steck.push_back(1);
	/*steck.push_back(2);
	steck.push_back(3);
	steck.push_back(4);*/
	cout << steck.Get_ip_head() << endl;
	steck.print_steck();
}

template<typename T>
Steck<T>::Steck()
{
	head = nullptr;
	Size = 0;
}

template<typename T>
void Steck<T>::push_back(T data)
{
	if (head == nullptr)
	{
		cout << "constructor for data " << data << endl;
		head = new Node<T>(data);
		Size++;;
	}
	else
	{
		cout << "constructor for data " << data << endl;
		Node<T>* current = new Node<T>(data);
		current->pPrev = head;
		head = current;
		Size++;
	}
}

template<typename T>
void Steck<T>::pop_back()
{
	if (head == nullptr)
	{
		cout << "steck is clear" << endl;
		return;
	}
	else
	{
		Node<T>* current = head;
		head = head->pPrev;
		cout << "destructor for data " << current->data << endl;
		delete current;
		Size--;
	}
}

template<typename T>
void Steck<T>::clear()
{
	while (Size)
	{
		pop_back();
	}
}

template<typename T>
Steck<T>::~Steck()
{
	clear();
}

template<typename T>
T Steck<T>::Getdata_head()
{
	return head->data;
}

template<typename T>
void Steck<T>::print_steck()
{
	while (Size)
	{
		cout<<Getdata_head()<<endl;
		pop_back();
	}
}

