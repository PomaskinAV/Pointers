template<typename T>
void clear(T** arr, const unsigned int rows)
{
	//3. �������� ���
	//1. ������� ������
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2. ������� ������ ����������
	delete[] arr;
}