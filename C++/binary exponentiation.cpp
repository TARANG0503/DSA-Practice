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

//approach 1 for binary exponentiation
long long binpow1(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow1(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

//approach 2 for binary exponentiation(recursive appraach)
long long binpow2(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
	IOS
	int n,m;
	cin>>n>>m;
	//to calculate n^m
    cout<<binpow1(n,m)<<endl;
    cout<<binpow2(n,m);
    return 0;
}


