#include<iostream>
using namespace std;

void FillRand(int arr[], const unsigned int n);
void Print(int arr[], const unsigned int n);

void push_back(int** arr, int& n, int value);
void push_front(int** arr, int& n, int value1);
void insert(int** arr, int& n, int index, int value2);
void pop_back(int** arr, int& n);
void pop_front(int** arr, int& n);
void erase(int** arr, int& n, int index1);

#define DYNAMIC_MEMORY1
//#define DYNAMIC_MEMORY2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	push_back(&arr, n, value);
	Print(arr, n);
	int value1;
	cout << "Введите добавляемое значение: "; cin >> value1;
	push_front(&arr, n, value1);
	Print(arr, n);
	int value2;
	int index;
	cout << "Введите добавляемое значение: "; cin >> value2;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	insert(&arr, n, index, value2);
	Print(arr, n);
	pop_back(&arr, n);
	Print(arr, n);
	pop_front(&arr, n);
	Print(arr, n);
	int index1;
	cout << "Введите индекс удаляемого элемента: "; cin >> index1;
	erase(&arr, n, index1);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY1

#ifdef DYNAMIC_MEMORY2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество столбцов: "; cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
#endif // DYNAMIC_MEMORY2

}

void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
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
void push_back(int** arr, int& n, int value)
{
	///Добавление элементов в массив
	//1. Создаем буферный массив нужного размера
	int* buffer = new int[n + 1];
	//2. Копируем исходный массив в buffer
	for (int i = 0; i < n; i++)
	{
		buffer[i] = (*arr)[i];
	}
	//3. Удаляем исходный массив
	delete[] *arr;
	//4. Подменяем исходный массив новым (буферным), за счет подмены адреса
	*arr = buffer;
	//5. Только после всех этих действий можно добавить значение в конец массива
	(*arr)[n] = value;
	//6. После добавления элементов в массив количество его элементов увеличивается на один
	n++;
}
void push_front(int** arr, int& n, int value1)
{
	///Добавление элементов в массив
	//1. Создаем буферный массив нужного размера
	int* buffer = new int[n + 1];
	//2. Копируем исходный массив в buffer
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = (*arr)[i];
	}
	//3. Удаляем исходный массив
	delete[] *arr;
	//4. Подменяем исходный массив новым (буферным), за счет подмены адреса
	*arr = buffer;
	//5. Только после всех этих действий можно добавить значение в начало массива
	(*arr)[0] = value1;
	//6. После добавления элементов в массив количество его элементов увеличивается на один
	n++;
}
void insert(int** arr, int& n, int index, int value2)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = (*arr)[i];
	}
	delete[] *arr;
	*arr = buffer;
	for (int i = n-1; i >= index; i--)
	{
		(*arr)[i + 1] = (*arr)[i];
	}
	(*arr)[index] = value2;
	n++;
}
void pop_back(int** arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = (*arr)[i];
	}
	delete[] *arr;
	*arr = buffer;
}
void pop_front(int** arr, int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = (*arr)[i];
	}
	delete[] *arr;
	for (int i = 1; i < n; i++)
	{
		buffer[i-1] = buffer[i];
	}
	n--;
	*arr = buffer;
}
void erase(int** arr, int& n, int index1)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = (*arr)[i];
	}
	delete[] *arr;
	for (int i = index1; i < n-1; i++)
	{
		buffer[i] = buffer[i+1];
	}
	n--;
	*arr = buffer;
}