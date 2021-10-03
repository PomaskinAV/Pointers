#include"Insert.h"
template<typename T>
int* insert(T arr[], int& n, int index, int value2)
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
template<typename T>
T** insert_row(T** arr, unsigned int& rows, const unsigned int cols, const unsigned int index)
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
template<typename T>
void insert_col(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int index)
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