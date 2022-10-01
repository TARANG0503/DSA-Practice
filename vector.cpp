// C++ program to demonstrate range based for
// loops for accessing vector and array elements
#include<iostream>
#include <vector>
using namespace std;

int main()
{
	// Create a vector object that
	// contains 5 elements
	vector<int> vec = {0, 1, 2, 3, 4};

	// Type inference by reference using auto.
	// Range based loops are preferred when no
	// modification is needed in value
	for (const auto &value : vec)
		cout << value << ' ';

	cout << '\n';

	// Basic 5 element integer array
	int array[]= {1, 2, 3, 4, 5};
	for (const auto &value: array)
		cout << value << " ";

	return 0;
}
