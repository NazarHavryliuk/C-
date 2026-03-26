#include "My dll.h"
int main()
{
	cout << "Enter number:";
	int a;
	cin >> a;
	if (a <= 0)
	{
		cout << endl << "number is < or =0" << endl;
	}
	else
	{
		cout << "All numbers with no remainder the given integer is divided by : ";
		vector<int> arr = numbers_that_are_divisible_without_a_remainder(a);
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
	cout << "Enter x to find arcsin(x):";
	double x;
	cin >> x;
	cout << "Enter the number of iterations to find a more accurate result:";
	int n;
	cin >> n;
	if ((x > -1) && (x < 1))
	{
		if (n >= 0)
		{
			cout << "The function arcsin(x) in terms of the Taylor series: " << arcsin(x, n) << endl;
		}
		else
		{
			cout << "n<0" << endl;
		}
	}
	else
	{
		cout << "-1>x or x>1" << endl;
	}
	cout << "Enter the sides of the triangle:";
	int q, b, c ;
	cin >> q >> b >> c;
	if ((q > 0) && (b > 0) && (c > 0))
	{
		cout << "The radius of the circle inscribed in the triangle:" << the_radius_of_the_inscribed_circle(q, b, c) << endl;
		cout << "The radius of the circumscribed circle around the triangle:" << the_radius_of_the_circle(q, b, c) << endl;
	}
	else
	{
		cout << "Side cannot be negative" << endl;
	}
	
	return 0;
}