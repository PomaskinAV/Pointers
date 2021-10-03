#include"stdafx.h"
#include"allocate.h"
#include"clear.h"
#include"FillRand.h"
#include"FillRand.cpp"
#include"Print.h"
#include"Print.cpp"
#include"Push_back.h"
#include"Push_back.cpp"
#include"Push_front.h"
#include"Push_front.cpp"
#include"Insert.h"
#include"Insert.cpp"
#include"Pop_back.h"
#include"Pop_back.cpp"
#include"Pop_front.h"
#include"Pop_front.cpp"
#include"Erase.h"
#include"Erase.cpp"

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