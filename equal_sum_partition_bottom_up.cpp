#include<iostream>
using namespace std;
bool equal_partition(int A[],int n,int sum)
{
	int m[n+1][28];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<28;j++)
		{
			if(j-A[i-1]==0)
			{
				m[i][j]=1;
			}
			else if(i==0)
			{
				m[i][j]=0;
			}
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<28;j++)
		{
			m[i][j]=(1&&m[i-1][j+A[i-1]])||(m[i-1][j]);
		}
	}
	return m[n][27];
}
int main()
{
	int A[]={12,9,5,2};
	int n=4;
	cout<<equal_partition(A,n,0);
}
