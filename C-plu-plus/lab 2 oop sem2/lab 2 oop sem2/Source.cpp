#include<iostream>
#include<string>
#include "Procesor.h"

using namespace std;

int main()
{
	Procesor procesor1("6 cores / 12 threads", 3.7, "AMD AM4", 7500);
	Procesor procesor2("6 cores / 12 threads", 2.5, "Intel LGA 1700", 6000);
	Procesor procesor3("8 cores / 12 threads", 3.4, "AMD AM4", 12000);
	Procesor procesor4("12 cores / 20 threads", 3.4, "AMD AM4", 20000);
	procesor1.Change_cost(3000);
	procesor1.Print_cost();
}