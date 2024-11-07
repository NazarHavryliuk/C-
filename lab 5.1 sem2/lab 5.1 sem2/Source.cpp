#include <iostream>

using namespace std;

class B
{
public:
	B(){}
	B(int data)
	{
		this->data = data;
		cout << "Constructor for B, data is " << data << endl;
	}
	void show()
	{
		cout << "Data is: " << data << endl;
	}
	int getData()
	{
		return data;
	}
	~B()
	{
		cout << "Destructor for B, data is " << data << endl << "Delete data " << data<<endl;
	}
private:
	int data;
};
class D1 :public B
{
public:
	D1(){}
	D1(int data):B(data)
	{
		
		cout << "Constructor for D1, data is " << data << endl;
	}
	void show()
	{
		B::show();
	}
	int getData()
	{
		return B::getData();
	}
	~D1()
	{
		cout << "Destructor for D1, data is "<<B::getData()<< endl;
	}
};
class D2 :private B
{
public:
	D2(){}
	D2(int data):B(data)
	{
		cout << "Constructor for D2, data is " << data << endl;
	}
	void show()
	{
		B::show();
	}
	int getData()
	{
		return B::getData();
	}
	~D2()
	{
		cout << "Destructor for D2, data is " << B::getData()<< endl;
	}
};
class D3 :private B
{
public:
	D3(){}
	D3(int data):B(data)
	{
		cout << "Constructor for D3, data is " << data << endl;
	}
	void show()
	{
		B::show();
	}
	int getData()
	{
		return B::getData();
	}
	~D3()
	{
		cout << "Destructor for D3, data is " <<B::getData()<< endl;
	}
};
class D4 :private D1
{
public:
	D4(int data):D1(data)
	{
		cout << "Constructor for D4, data is " << data << endl;
	}
	void show()
	{
		D1::show();
	}
	int getData()
	{
		return D1::getData();
	}
	~D4()
	{
		cout << "Destructor for D4, data is " << D1::getData()<< endl;
	}
};
class D5: public D2, private D3
{
public:
	D5(int data):D2(data),D3(data)
	{
		cout << "Constructor for D5, data is " << data << endl;
	}
	void show()
	{
		D2::show();
		D3::show();
	}
	int getData()
	{
		return D2::getData();
	}
	~D5()
	{
		cout << "Destructor for D5, data is " <<D2::getData()<< endl;
	}
};
void FOO()
{
	D4 d4(5);
	d4.show();
	D5 d5(6);
	d5.show();
}
int main()
{
	B b(1);
	b.show();
	D1 d1(2);
	d1.show();
	D2 d2(3);
	d2.show();
	D3 d3(4);
	d3.show();
	cout << "--------" << endl;
	FOO();
	cout << "--------" << endl;
}