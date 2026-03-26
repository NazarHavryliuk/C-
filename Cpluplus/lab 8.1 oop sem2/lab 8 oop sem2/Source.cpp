#include "My dll.h"
int main()
{
	cout << "enter radius ";
	double r;
	cin >> r;
	if (r < 0)
	{
		cout << "Radius can't be negativ" << endl;
	}
	else
	{
		cout << "the area of the sphere " << area(r) << endl;
		cout << "the volume of the sphere " << volume(r) << endl;
	}
	return 0;
}