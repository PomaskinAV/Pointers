#pragma once
template<typename T>
T* push_back(T arr[], int& n, int value);
template<typename T>
T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>
void push_col_back(T** arr, const unsigned int rows, unsigned int& cols);