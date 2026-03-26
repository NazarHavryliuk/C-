#pragma once
#include<iostream>
using namespace std;

class Procesor
{
public:
	Procesor(const char * procesor_type, int frequency, const char * type_of_motherboard, double cost);
	void Print_procesor_type();
	void Print_frequency();
	void Print_type_of_motherboard();
	void Print_cost();
	void Change_procesor_type(const char * data);
	void Change_frequency(int data);
	void Change_type_of_motherboard(const char * data);
	void Change_cost(double data);
	int Get_frequency();
	int Get_cost();
	const char* Get_procesor_type();
	const char* Get_type_of_motherboard();

private:
	const char * procesor_type;
	int frequency;
	const char * type_of_motherboard;
	int cost;
};

