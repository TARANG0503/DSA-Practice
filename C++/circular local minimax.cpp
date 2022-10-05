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
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n%2!=0){
			cout<<"NO"<<endl;
		}
		else{
			sort(a,a+n);
			int p = a[(n/2)-1];
			int q = a[n/2];
			if(p==q){
				cout<<"NO"<<endl;
			}
			else{
				int b[n/2];
				int c[n/2];
				for (int i=0;i<n/2;i++){
					b[i]=a[i];
				}
				for(int i=0;i<n/2;i++){
					c[i]=a[i+(n/2)];
				}
				cout<<"YES"<<endl;
				for(int i=0;i<n/2;i++){
					cout<<b[i]<<" "<<c[i]<<" ";
				}
				cout<<endl;
			}
		}
    }
    return 0;
}


