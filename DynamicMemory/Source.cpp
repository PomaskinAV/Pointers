#include<iostream>
using namespace std;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void FillRand(int arr[], const unsigned int n);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols);
void Print(int arr[], const unsigned int n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value1);
int* insert(int arr[], int& n, int index, int value2);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index1);

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	int value1;
	cout << "Введите добавляемое значение: "; cin >> value1;
	arr = push_front(arr, n, value1);
	Print(arr, n);
	int value2;
	int index;
	cout << "Введите добавляемое значение: "; cin >> value2;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	arr = insert(arr, n, index, value2);
	Print(arr, n);
	arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);
	int index1;
	cout << "Введите индекс удаляемого элемента: "; cin >> index1;
	arr = erase(arr, n, index1);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int rows;
	int cols;
	cout << "Введите колличество строк: "; cin >> rows;
	cout << "Введите колличество элементов строки: "; cin >> cols;
	// объявление двумерного динамического массива
	// 1. объявляем указатель на указатель и сохраняем в него адрес массива указателей
	int** arr = new int* [rows];
	//2. создаем строки двумерного динамического массива
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	// обращение к элементам ДДМ
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//3. удаление ДДМ
	//1. удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2. удаляем массив указателей
	delete[] arr;
}

void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int& n, int value)
{
	///Добавление элементов в массив
	//1. Создаем буферный массив нужного размера
	int* buffer = new int[n + 1];
	//2. Копируем исходный массив в buffer
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3. Удаляем исходный массив
	delete[] arr;
	//4. Подменяем исходный массив новым (буферным), за счет подмены адреса
	arr = buffer;
	//5. Только после всех этих действий можно добавить значение в конец массива
	arr[n] = value;
	//6. После добавления элементов в массив количество его элементов увеличивается на один
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int value1)
{
	///Добавление элементов в массив
	//1. Создаем буферный массив нужного размера
	int* buffer = new int[n + 1];
	//2. Копируем исходный массив в buffer
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	//3. Удаляем исходный массив
	delete[] arr;
	//4. Подменяем исходный массив новым (буферным), за счет подмены адреса
	arr = buffer;
	//5. Только после всех этих действий можно добавить значение в начало массива
	arr[0] = value1;
	//6. После добавления элементов в массив количество его элементов увеличивается на один
	n++;
	return arr;
}
int* insert(int arr[], int& n, int index, int value2)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = n-1; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[index] = value2;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
	//n--;
	//return arr;
}
int* pop_front(int arr[], int& n)
{
	for (int i = 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}
	n--;
	return arr;
}
int* erase(int arr[], int& n, int index1)
{
	for (int i = index1; i < n-1; i++)
	{
		arr[i] = arr[i+1];
	}
	n--;
	return arr;
}