#include<iostream>
using namespace std;

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
#define DYNAMIC_MEMORY_3

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);

void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const unsigned int n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);

int* push_back(int arr[], int& n, int value);
int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols);
void push_col_back(int** arr, const unsigned int rows, unsigned int& cols);
int* push_front(int arr[], int& n, int value1);
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols);
void push_col_front(int** arr, const unsigned int rows, unsigned int& cols);
int* insert(int arr[], int& n, int index, int value2);
int** insert_row(int** arr, unsigned int& rows, const unsigned int cols, const unsigned int index);
void insert_col(int** arr, const unsigned int rows, unsigned int& cols, const unsigned int index);
int* pop_back(int arr[], int& n);
int** pop_row_back(int** arr, unsigned int& rows);
void pop_col_back(int** arr, const unsigned int rows, unsigned int& cols);
int* pop_front(int arr[], int& n);
int** pop_row_front(int** arr, unsigned int& rows);
void pop_col_front(int** arr, const unsigned int rows, unsigned int& cols);
int* erase(int arr[], int& n, int index1);
int** erase_row(int** arr, unsigned int& rows, const unsigned int index);
void erase_col(int** arr, const unsigned int rows, unsigned int& cols, const unsigned int index);

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

#ifdef DYNAMIC_MEMORY_2
	unsigned int rows;
	unsigned int cols;
	cout << "Введите колличество строк: "; cin >> rows;
	cout << "Введите колличество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	FillRand(arr, rows, cols);
	arr = push_row_back(arr, rows, cols);
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	int index;
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << endl;
	arr = pop_row_back(arr, rows);
	arr = pop_row_front(arr, rows);
	Print(arr, rows, cols);
	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, index);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}

	clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

	unsigned int rows;
	unsigned int cols;
	cout << "Введите колличество строк: "; cin >> rows;
	cout << "Введите колличество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	FillRand(arr, rows, cols);
	push_col_back(arr, rows, cols);
	push_col_front(arr, rows, cols);
	//for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand();
	Print(arr, rows, cols);
	int index;
	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
}

int** allocate(const unsigned int rows, const unsigned int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, const unsigned int rows)
{
	//3. удаление ДДМ
	//1. удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2. удаляем массив указателей
	delete[] arr;
}

void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
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
int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
	return arr;
}
void push_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
int* push_front(int arr[], int& n, int value1)
{
	///Добавление элементов в массив
	//1. Создаем буферный массив нужного размера
	int* buffer = new int[n + 1];
	//2. Копируем исходный массив в buffer
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
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
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//delite[] arr[0];
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}
void push_col_front(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
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
	for (int i = n - 1; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[index] = value2;
	n++;
	return arr;
}
int** insert_row(int** arr, unsigned int& rows, const unsigned int cols, const unsigned int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = rows - 1; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[index] = new int[cols] {};
	rows++;
	return arr;
}
void insert_col(int** arr, const unsigned int rows, unsigned int& cols, const unsigned int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
			//(j < index ? buffer[j] : buffer[j + 1]) = arr[i][j];
			buffer[j < index ? j : j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
		/*for (int i = 0; i < rows; i++)
		{
			for (int j = index; j < cols; j++)
			{
				arr[j+1] = arr[j];
			}
			arr[index] = new int[cols] {};
		}*/
	}
	cols++;

	/*for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols+1] {};
		for (int j = 0; j < cols; j++)
		{
			if (j >= index)buffer[j + index] = arr[i][j];
			else buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;*/
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int** pop_row_back(int** arr, unsigned int& rows)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
void pop_col_back(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
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
int** pop_row_front(int** arr, unsigned int& rows)
{
	for (int i = 1; i < rows; i++)
	{
		arr[i - 1] = arr[i];
	}
	rows--;
	return arr;
}
void pop_col_front(int** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols-1]{};
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
int* erase(int arr[], int& n, int index1)
{
	for (int i = index1; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	return arr;
}
int** erase_row(int** arr, unsigned int& rows, const unsigned int index)
{
	for (int i = index; i < rows - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	rows--;
	return arr;
}
void erase_col(int** arr, const unsigned int rows, unsigned int& cols, const unsigned int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols-1; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}