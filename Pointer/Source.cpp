#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;//Вывод значения переменной а на экран
	cout << &a << endl;//Взятие адреса переменной а прямо при выводе
	cout << pa << endl;//Вывод адреса переменной а, хранящегося в указателе pa
	cout << *pa << endl;
	int* pb;//Объявление указателя
	int b = 3;
	pb = &b;
	//int - int
	//int* - Указатель на int
	//double - doudle
	//double* - Указатель на double
	//char - char
	//char* - Указатель на char  
#endif // POINTERS_BASICS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	int *f = arr;
	for (int i = 0; i < n; i++)
	{
		cout << *(f + i) << "\t";
	}
	cout << endl;
}