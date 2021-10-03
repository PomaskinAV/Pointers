#pragma once
#include"stdafx.h"
template<typename T>
T* insert(T arr[], int& n, int index, int value2);
template<typename T>
T** insert_row(T** arr, unsigned int& rows, const unsigned int cols, const unsigned int index);
template<typename T>
void insert_col(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int index);