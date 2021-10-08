#include<iostream>
using namespace std;
int c[32][5];
int i=0,j=0;
int val=0;
int give_subset(int A[],int sum, int n)
{
	int m[n+1][sum+1];
	for(int h=0;h<n+1;h++)
	{
		for(int g=0;g<sum+1;g++)
		{
			if(g==0)
			{
				m[h][g]=1;
			}
			else if(h==0)
			{
				m[h][g]=0;
			}
		}
	}
	for(int h=1;h<n+1;h++)
	{
		for(int g=1;g<sum+1;g++)
		{
			if(A[h-1]<=g)
			{
				m[h][g]=(1&&m[h-1][g-A[h-1]]);
				if(m[h][g]==1&&val+A[h-1]==11)
				{
					c[i][j]=A[h-1];
			        i++;
			        j=0;
			        val=0;
				}
				else if(m[h][g]==1)
				{
					c[i][j]=A[h-1];
			        j++;
			        val=val+g;
				}
				int c=m[h-1][g];
				m[h][g]=m[h][g]||c;
			}
			else if(A[h-1]>g)
			{
				m[h][g]=m[h-1][g];
			}	
		}
	}
}
int main()
{
	int A[]={2,3,7,8,10};
	int sum=11;
	int n=5;
	give_subset(A,sum,n);
	for(int h=0;h<32;h++)
	{
		for(int g=0;g<5;g++)
		{
			cout<<c[h][g]<<"\t";
		}
		cout<<"\n";
	}
}
