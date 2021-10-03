#pragma once
template<typename T>
T* pop_front(T arr[], int& n);
template<typename T>
T** pop_row_front(T** arr, unsigned int& rows);
template<typename T>
void pop_col_front(T** arr, const unsigned int rows, unsigned int& cols);