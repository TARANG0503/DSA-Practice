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
    
    //your code goes here
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	deque<int> q;
	for(int i=n-1;i>=0;i-=2){
		q.pb(a[i]);
		q.push_front(a[i-1]);
	}
	deque<int>::iterator it;
	for(it=q.begin();it!=q.end();++it){
		cout<<*it<<" ";
	}
		
    return 0;
}


