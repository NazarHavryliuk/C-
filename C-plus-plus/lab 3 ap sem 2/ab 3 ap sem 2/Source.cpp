#include<iostream>
#include<string>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void push_back(T data);
	void pop_front();
	void clear();
	T get_front();
	bool empty();
private:
	template<typename T>
	class Node
	{
	public:
		T data;
		Node<T>* pnext;
		Node<T>* pprevious;
		Node(T data = T(), Node<T>* pnext = nullptr, Node<T>* pprevious = nullptr)
		{

			this->data = data;
			this->pnext = pnext;
			this->pprevious = pprevious;
		}

	};
	Node<T>* head;
	Node<T>* tail;
	int Size;

};
int main()
{
	List<int> lst;
	lst.push_back(10);
	lst.push_back(3);
	lst.push_back(6);
	lst.push_back(36);
	lst.push_back(23);

	cout<<lst.empty()<<endl;
	cout<<lst.get_front()<<endl;

}

template<typename T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if ((head == nullptr) && (tail == nullptr))
	{
		head = tail = new Node<T>(data);
	}
	else
	{
		Node<T>* current = tail;
		tail = new Node<T>(data);
		tail->pprevious = current;
		current->pnext = tail;
	}
	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* ptr = head;
	head = head->pnext;
	cout << "destructor for" << ptr->data << endl;
	if (head != nullptr)
	{
		head->pprevious = nullptr;
	}
	delete ptr;
	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size > 0)
	{
		pop_front();
	}
}

template<typename T>
T List<T>::get_front()
{
	if (head == nullptr) 
	{
		cout << "list is clear" << endl; 
		return 0;
	}
	else
	{
	    return head->data;
	}
}

template<typename T>
bool List<T>::empty()
{
	if (head == nullptr)
	{
		return false;
	}
	else { return true; }
}
