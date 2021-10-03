#pragma once
template<typename T>
T* push_front(T arr[], int& n, int value1);
template<typename T>
T** push_row_front(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>
void push_col_front(T** arr, const unsigned int rows, unsigned int& cols);