#include<iostream>
using namespace std;
int main()
{
	int A[8]={4,3,2,10,12,1,5,6};
	for(int i=1;i<8;i++)
	{
		int value=A[i];
		int hole=i;
		while(hole>0&&A[hole-1]<value)
		{
			A[hole]=A[hole-1];
			hole--;
		}
		A[hole]=value;
	}
	for(int i=0;i<8;i++)
	{
		cout<<A[i];
	}
}
