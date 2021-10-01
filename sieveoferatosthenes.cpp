#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int p;
	cout<<"Enter a number upto which you want to find prime numbers: ";
	cin>>p;

	vector<int> prime(p+1,1);
	for(int i=2;i*i<=p;i++)
	{
		if(prime[i]==1)
		{
			for(int j=i;i*j<=p;j++)
			{
				prime[i*j]=0;
			}
		}
	}

	cout<<"The prime numbers upto number"<<p<<" are as follows: ";
	for(unsigned i=2;i<=prime.size();i++)
	{
		if(prime[i]==1)
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;

	return 0;
}
