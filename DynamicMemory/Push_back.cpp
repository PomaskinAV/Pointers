template<typename T>
T* push_back(T arr[], int& n, int value)
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
template<typename T>
T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols)
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
template<typename T>
void push_col_back(T** arr, const unsigned int rows, unsigned int& cols)
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