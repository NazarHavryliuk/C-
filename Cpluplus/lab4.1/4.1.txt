#include<iostream>
#include<ctime>
#include <cstdlib>

using namespace std;

int main()
{
	/*srand(time(NULL));*/
	const int SIZE = 10;
	int arr[SIZE];
	int max = 10;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % max;
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout <<"maximum number "<<i+1<<" = "<< arr[SIZE - i - 1]<<endl;
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "minimum number " << i + 1 << " = " << arr[i] << endl;
	}
}