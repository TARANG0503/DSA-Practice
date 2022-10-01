#pragma once

/*
Array ADT Having all main functionalites of STL array. Supports N-Dimensions.
:protected members: 
=> arr is a 1D array used to support functionality from 1 to N - D.
=> size is the total size of array required.
=> D is a dynamic array which holds the record for values of all dimension. for example for 2D { what by what } is stored.
=> dimNo tells the dimension.
=> I is a dynamic array which holds current/required indeces being used. E.g. [0][3]
=> count tells the current no of values stored.
*/

template<class T>
class Array {
protected:
	T* arr;
	int size;
	int* D, dimNo;
	int* I, count;
public:
	Array();
	Array(int , ...);
	T at(int);
	void setValue(int, int);
	T front();
	T back();
	void resize();
	bool isFull();
	bool isEmpty();
	int getIndex(int , ...);
	~Array();
};

