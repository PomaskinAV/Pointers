#pragma once
#include"stdafx.h"
template<typename T>
void FillRand(T arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
template<typename T>
void FillRand(T** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);