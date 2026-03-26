#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

string file_name = "file.txt";
void Add(int* &arr,int &size, int q)
{
	int* newarr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	newarr[size] = q;
	size++;
	delete[] arr;
	arr = newarr;
}
void FOO(int* &arr, int& sizeArr, int* &finalArr, int& sizeFinalArr)
{
	int* arr2 = new int[sizeArr];
	for (int i = 0; i < sizeArr; i++)
	{
		arr2[i] = arr[i];
	}
	for (int i = 0; i < sizeArr - 1; i++)
	{
		for (int j = 0; j < sizeArr - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	for (int i = 0; i < sizeArr; i++)
	{
		if (arr2[i] == arr[i])
		{
			Add(finalArr, sizeFinalArr, arr[i]);
		}
	}
	delete[] arr2;

}



int main()
{
	int* arr=nullptr;
	int sizeArr=0;
	int* finalArr=nullptr;
	int sizeFinalArr = 0;
	ifstream file(file_name, ios::in);
	if (!file.is_open())
	{
		cout << "file don't open" << endl;
	}
	else
	{
		int q;
		while (file >> q)
		{
			Add(arr, sizeArr, q);
		}
		
	}
	for (int i = 0; i < sizeArr; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << "\n";
	FOO(arr,sizeArr, finalArr,sizeFinalArr);
	for (int i = 0; i < sizeFinalArr; i++)
	{
		cout << finalArr[i] << " ";
	}
	delete[] arr;
	delete[] finalArr;
}