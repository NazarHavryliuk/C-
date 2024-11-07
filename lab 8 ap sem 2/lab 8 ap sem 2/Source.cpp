#include <iostream>
#include<vector>
using namespace std;
void SerchInsert(vector<int> &arr)
{
	int k=1;
	for (int i = 2; i < arr.size()+1; i++)
	{
		int q1 = k-1;
		int q2 = k;
		for (; q1 >= 0; q1--)
		{
			if (arr[q2] < arr[q1])
			{
				swap(arr[q2], arr[q1]);
				q2--;
			}
			else {
				break;
			}
		}
		k++;
	}

}
void SerchChuar(vector<int>& (arr))
{
	int number1 = 0;
	int number2 = arr.size()-1;
	int q = 1;
	int opore = arr[q];
	bool flag = true;
	while (q != arr.size())
	{
		while (flag)
		{
			int n1 = number1, n2 = number2;
			while (arr[n1] < arr[q])
			{
				n1++;
			}
			while (arr[n2] > arr[q])
			{
				n2--;
			}
			if ((n1 == q) && (n2 == q))
			{
				q++;
				break;
			}
			else(swap(arr[n1], arr[n2]));
		}
		
	}
}
void SerchComb(vector<int>& arr)
{
	int fact = arr.size();
	double e = 1.3;
	while (fact != 0)
	{ 
		fact = fact / e;
		for (int i = 0; (i + fact) < arr.size(); i++)
		{
			if (arr[i] > arr[i + fact])
			{
				swap(arr[i], arr[i + fact]);
			}
		}
	}
}
bool operate(vector<int>& arr)
{
	bool flg = true;
	int k = arr.size() % 2;
	for (int i = 0; i < (arr.size() - (arr.size() % 2)-1); i += 2)
	{
		if (arr[i] > arr[i + 1])
		{
			flg = false;
			swap(arr[i], arr[i + 1]);
		}
	}
	for (int i = 1; i < (arr.size() - (arr.size() % 2)-1); i += 2)
	{
		if (arr[i] > arr[i + 1])
		{
			flg = false;
			swap(arr[i], arr[i + 1]);
		}
	}
	if (flg)
	{
		return true;
	}
	else { return false; }
}
void SerchSteam(vector<int>& arr)
{
	while (!operate(arr)) {}
}

int main()
{
	vector<int> arr1{ -4,9,2,7,6,8,2 };
	SerchInsert(arr1);
	cout << "insertion sort: ";
	for (auto w : arr1)
	{
		cout << w << " ";
	}
	cout << endl<<"quick sort: ";
	vector<int> arr2{ 4,-3,5,7,6,8,2 };
	SerchChuar(arr2);
	for (auto w : arr2)
	{
		cout << w << " ";
	}
	cout << endl<<"comb sorting: ";
	vector<int> arr3{ 4,9,5,3,2,-6,1,2 };
	SerchComb(arr3);
	for (auto w : arr3)
	{
		cout << w << " ";
	}
	cout << endl<<"even-odd sorting: ";
	vector<int> arr4{ 4,3,5,6,9,2,8,-2 };
	SerchSteam(arr4);
	for (auto w : arr4)
	{
		cout << w << " ";
	}
	cout << endl;
}