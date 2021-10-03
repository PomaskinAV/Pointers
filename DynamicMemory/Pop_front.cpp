template<typename T>
T* pop_front(T arr[], int& n)
{
	for (int i = 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}
	n--;
	return arr;
}
template<typename T>
T** pop_row_front(T** arr, unsigned int& rows)
{
	for (int i = 1; i < rows; i++)
	{
		arr[i - 1] = arr[i];
	}
	rows--;
	return arr;
}
template<typename T>
void pop_col_front(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}