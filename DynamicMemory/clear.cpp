template<typename T>
void clear(T** arr, const unsigned int rows)
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