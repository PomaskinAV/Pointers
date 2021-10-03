template<typename T>
T* push_front(T arr[], int& n, int value1)
{
	///���������� ��������� � ������
	//1. ������� �������� ������ ������� �������
	int* buffer = new int[n + 1];
	//2. �������� �������� ������ � buffer
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3. ������� �������� ������
	delete[] arr;
	//4. ��������� �������� ������ ����� (��������), �� ���� ������� ������
	arr = buffer;
	//5. ������ ����� ���� ���� �������� ����� �������� �������� � ������ �������
	arr[0] = value1;
	//6. ����� ���������� ��������� � ������ ���������� ��� ��������� ������������� �� ����
	n++;
	return arr;
}
template<typename T>
T** push_row_front(T** arr, unsigned int& rows, const unsigned int cols)
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
template<typename T>
void push_col_front(T** arr, const unsigned int rows, unsigned int& cols)
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