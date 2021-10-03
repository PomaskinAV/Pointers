#pragma once
template<typename T>
T* erase(T arr[], int& n, int index1);
template<typename T>
T** erase_row(T** arr, unsigned int& rows, const unsigned int index);
template<typename T>
void erase_col(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int index);