template<typename T>
T* erase(T arr[], int& n, int index1)
{
	for (int i = index1; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	return arr;
}
template<typename T>
T** erase_row(T** arr, unsigned int& rows, const unsigned int index)
{
	for (int i = index; i < rows - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	rows--;
	return arr;
}
template<typename T>
void erase_col(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}