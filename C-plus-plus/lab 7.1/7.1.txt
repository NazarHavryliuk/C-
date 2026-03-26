#include<iostream>
#include<ctime>
#include <cstdlib>
#include<string>
#include <locale>
#include<cmath>


using namespace std;
void interval_and_precision(double& a, double& b, double& e)
{
	cout << "[a;b]" << endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "enter precision:";
	cin >> e;
	cout << endl;
}
void question(double& x, double& n)
{

	n = (pow(2.71828, 2 * x)) / cos(2 * x) + 3 * x;
}
void work_from_question(double a, double b, double e, double& result)
{
	double n;
	double x = (b - a) / 2;
	question(x, n);
	double part1, part2, n1, n2;
	for (int i = 0; fabs(n) > e; i++)
	{
		part1 = ((a + ((b + a) / 2)) / 2);
		part2 = ((b + ((b + a) / 2)) / 2);
		question(part1, n1);
		question(part2, n2);
		if (fabs(n1) < fabs(n2))
		{
			b = (a + b) / 2;
		}
		if (fabs(n1) > fabs(n2))
		{
			a = (a + b) / 2;
		}
		x = (b + a) / 2;
		question(x, n);
	}
	result = (a + b) / 2;

}

void main()
{
	setlocale(LC_ALL, "uk_UA.UTF-8");
	cout << "enter interval" << endl;
	double a, b;
	double e;
	interval_and_precision(a, b, e);
	double result = 0;
	work_from_question(a, b, e, result);
	cout << "x=" << result;

}