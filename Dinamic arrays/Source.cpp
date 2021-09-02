#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	/*int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	delete[] arr;*/
	int n;
	int CountEven=0, CountOdd=0;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		arr[i] % 2 == 0 ? CountEven++ : CountOdd++;
	}
	int *arrEven = new int[CountEven];
	int *arrOdd = new int[CountOdd];
	CountEven = 0, CountOdd = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] % 2 == 0 ? arrEven[CountEven++] = arr[i] : arrOdd[CountOdd++] = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < CountEven; i++)
	{
		cout << arrEven[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < CountOdd; i++)
	{
		cout << arrOdd[i] << "\t";
	}
	cout << endl;
	delete[] arr;
	delete[] arrEven;
	delete[] arrOdd;
}