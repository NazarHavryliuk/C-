#include "Procesor.h"

Procesor::Procesor(const char * procesor_type, int frequency,const char * type_of_motherboard, double cost)
{
	this->frequency = frequency;
	this->procesor_type = procesor_type;
	this->type_of_motherboard = type_of_motherboard;
	this->cost = cost;
}
void Procesor::Print_procesor_type()
{
	cout << "procesor type is " << Get_procesor_type() << endl;

}
void Procesor::Print_frequency()
{
	cout << "frequence is " << Get_frequency() << "GHz" << endl;

}
void Procesor::Print_type_of_motherboard()
{
	cout << "type_of_motherboard is " << Get_type_of_motherboard() << endl;

}
void Procesor::Print_cost()
{
	cout << "cost is " << Get_cost() << " uah" << endl;

}
void Procesor::Change_procesor_type(const char * data)
{
	this->procesor_type = data;
}
void Procesor::Change_frequency(int data)
{
	this->frequency = data;
}
void Procesor::Change_type_of_motherboard(const char * data)
{
	this->type_of_motherboard = data;
}
void Procesor::Change_cost(double data)
{
	this->cost = data;
}
int Procesor::Get_frequency()
{
	return this->frequency;
}
int Procesor::Get_cost()
{
	return this->cost;
}
const char* Procesor::Get_procesor_type()
{
	return procesor_type;
}

const char* Procesor::Get_type_of_motherboard()
{
	return type_of_motherboard;
}
