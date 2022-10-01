#include "Array.h"
#include<stdarg.h>
#include <iostream>
#include <cstdarg>

using namespace std;

template<class T>
Array<T>::Array()
{
	// Considering the default array as 1D of size 10.

	size = 10;
	dimNo = 1;
	D = new int[dimNo + 1];
	I = new int[dimNo + 1];
	D[1] = size;
	arr = new T[size];
	count = 0;	
}

template<class T>
Array<T>::Array(int d,  ...)
{
	/*
	Using va_list method to have N number of arguement. 
	D and I are created and initialized to respective values.
	*/

	va_list args;
	va_start(args, d);

	count = 0;
	size = 1;
	this->dimNo = d;
	D = new int[dimNo + 1];
	I = new int[dimNo + 1];

	for (int i = 1; i <= dimNo; i++) {
		D[i] = va_arg(args, int);
	}

	for (int i = 1; i <= dimNo; i++)
		size *= D[i];

	arr = new T[size];
	va_end(args);
}

template<class T>
int Array<T>::getIndex(int in, ...)
{
	/*
	This function converts ND indexes to 1D mapping. 
	Instead of converting index at every function, I used this function everytime passing indexes 
	as arguements.
	:param: N - indexes
	:return: Coverted linearly mapped index
	*/

	va_list args;
	va_start(args, in);

	this->I[1] = in;
	for (int i = 2; i <= dimNo; i++) {
		I[i] = va_arg(args, int);
	}

	int index = 0;
	int help = 1;
	for (int p = 1; p <= dimNo; p++) {
		help = I[p];
		for (int q = p + 1; q <= dimNo; q++) {
			help *= D[q];
		}
		index += help;
	}
	va_end(args);
	return index;
}

template<class T>
T Array<T>::at(int index)
{
	return arr[index];
}

template<class T>
void Array<T>::setValue(int index, int value)
{
	arr[index] = value;
}

template<class T>
T Array<T>::front()
{
	return arr[0];
}

template<class T>
T Array<T>::back()
{
	return arr[size - 1];
}

template<class T>
void Array<T>::resize()
{
	if (isEmpty()) {
		size = ceil(size / 2.0);
		T* arr2 = new T[size];
		for (int i = 0; i < size; i++) {
			arr2[i] = arr[i];
		}
		delete arr;
		arr = arr2;
	}
}

template<class T>
bool Array<T>::isFull()
{
	return count == size;
}

template<class T>
bool Array<T>::isEmpty()
{
	return count == 0;
}


template<class T>
Array<T>::~Array()
{
	if(arr)
		delete[] arr;
}
