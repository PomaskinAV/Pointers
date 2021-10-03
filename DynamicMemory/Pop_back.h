#pragma once
template<typename T>
T* pop_back(T arr[], int& n);
template<typename T>
T** pop_row_back(T** arr, unsigned int& rows);
template<typename T>
void pop_col_back(T** arr, const unsigned int rows, unsigned int& cols);