#include <iostream>
#include <bitset>
using namespace std;

// Naive solution to count the total number of set bits in `n`
int countSetBits(int n)
{
	int count = 0;

	while (n)
	{
		count += (n & 1);	// check last bit
		n >>= 1;
	}

	return count;
}

int main()
{
	int n = 16;

	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "The total number of set bits in " << n << " is "
		 << countSetBits(n) << endl;

	return 0;
}