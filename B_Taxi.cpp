
//🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣🤓😁😎😎🎃🎃🎃
#include<bits/stdc++.h>
using namespace std;
#define int         long long
#define pb          emplace_back
#define ld          long double
#define f(i,a,b)    for(int i=a;i<b;i++)
#define mp          make_pair
#define pi         pair<int, int>
#define vi          vector<int>
#define vp        vector<pair<int, int>>
#define mi         map<int, int>
#define all(a)      a.begin(),a.end()
#define ff           first
#define ss           second
#define endl        '\n'
#define el          '\n'
#define si(x)       (int)(x.size())
#define IOS         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define elapsed_time 1.0 * clock() / CLOCKS_PER_SEC
#define tree        vector<vector<int>>
#define PI          acos(-1)
#define set_bits __builtin_popcountll
int inf=99999999999;
const int mod=1e9+7;
const int cmp=1e18;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
int pow(int a, int b) {
    int ans = 1;
    while(b>0) {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int lcm(int a, int b){
    return a/__gcd(a, b)*b;
}
int N=1000000;
void sieve(){
    vector<bool> isprime(N+1, 1);
    isprime[0]=isprime[1]=0;
    for(int i=2; i<=N; i++){
        if(isprime[i] && i*i<=N){
            for(int j=i*i; j<=N; j+=i){
                isprime[j]=0;
            }
        }
    }
}
void gv(vi &v, int n){
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
}
// ================ ================ ================ ================ ================ ================ ================ ================ ================ ================
int solve()
{
    IOS;
    int n;
    cin>>n;
    vi v;
    int o=0,to=0,th=0,f=0;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
        if(t==1)o++;
        else if(t==2)to++;
        else if(t==3)th++;
        else if(t==4)f++;
    }
    int cnt=f;
    cnt+=to/2;
    to%=2;
    if(o>=2&&to){
        o-=2;
        to=0;
        cnt++;
    }
    if(th<o){
        cnt+=th;
        o-=th;
        cnt+=ceil((double)(o+to)/4);
    }else{
        cnt+=o;
        th-=o;
        cnt+=to%2;
        cnt+=th;

    }
    cout<<cnt;
    return 0;
}
// ================ ================ ================ ================ ================ ================ ================ ================ ================ ================
signed main(){
    IOS;
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }    
    return 0;
}