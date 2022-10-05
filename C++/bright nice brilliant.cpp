#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define INF 1e18
#define fo(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define Fo(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vlli;
#define pb push_back
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

int main()
{
	IOS
    ll test=1;
    cin>>test;
    while (test--)
    {
        //your code goes here
		int n;
		cin>>n;
		if(n==1){
			cout<<1<<endl;
		}
		else if(n==2){
			cout<<1<<endl;
			cout<<1<<" "<<1<<endl;
		}
		else if(n>=3){
			cout<<1<<endl;
			for(int i=1;i<n;i++){
				cout<<1<<" ";
				for(int j=1;j<i;j++){
					cout<<0<<" ";
				}
				cout<<1<<" ";
				cout<<endl;
			}
		}
		
    }
    return 0;
}


