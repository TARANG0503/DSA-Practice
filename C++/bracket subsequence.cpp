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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int use[n];
    stack<string> st;
    int ctr=0;
    for(int i=0;i<n;i++){
    	if(s[i]=='('){
    		st.push("(");
		}
		else if(s[i]==')'){
			use[st.top()]=1;
			use[i]=1;
			ctr+=2;
			st.pop();
		}
		if(ctr==k){
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(use[i]==1){
			cout<<s[i];
		}
	}
    return 0;
}


