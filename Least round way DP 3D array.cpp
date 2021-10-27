#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//#pragma GCC optimize('O2') 
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define tin tuple<ll,ll,ll>
#define mll map<ll,ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define fo(i,x,z) for(ll i=x;i<z;i++)
#define rf(i,x,z) for(ll i=x-1;i>=z;i--)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define fa(i,vect) for(auto i : vect)
#define fr(i,vect) for(VI :: reverse_iterator i = vect.rbegin(); i != vect.rend(); i++)
#define mod 1000000007
//  for (auto &a : v)
//cin >> a;
//for (auto me : m) {
//std::vector<ll>::iterator it; 
//it = std::find (v.begin(), v.end(), ser);
//if (it != v.end())
# define INF 0x3f3f3f3f
const int MAX = 1e3 + 7; 
////////////////////////////////////////////////////////////////////////////////////////////

ll power(ll base,ll por)
{
ll res=1;
while(por>1){
if(por%2==1)
{
res*=base;
por--;
}
por/=2;
base*=base;
}
res*=base;
return res;
}

////////////////////////////////////////////////////////////////////////
int i,j,k,t,n,q,l,r,mid;
int zerorow=-1,x;
int a[MAX][MAX][2],f[MAX][MAX][2];      //3 D array
///////////////////////////////////////////////////////////////////
    
    
    void fn(int i,int j)
    {
        if(i==1 && j==1)
        return;
        if(f[i-1][j][k]<f[i][j-1][k])
        fn(i-1,j),cout<<'D';
        else
        fn(i,j-1),cout<<'R';
        
    }
    void solve()
    {
        cin>>n;
        fo(i,1,n+1)
        {
            fo(j,1,n+1)
            {
                cin>>x;
                if(x==0)
                    zerorow=i;
                    
                while(x && x%2==0)
                    a[i][j][0]++,x/=2;
                while(x && x%5==0)
                    a[i][j][1]++,x/=5;
            }   
        }
        
        fo(i,2,n+1)
        {
            fo(j,0,2)
                f[0][i][j]=f[i][0][j]=mod;
        }
        
        fo(i,1,n+1)
            fo(j,1,n+1)
                {
                    f[i][j][0]=min(f[i][j-1][0],f[i-1][j][0])+a[i][j][0];
                    f[i][j][1]=min(f[i][j-1][1],f[i-1][j][1])+a[i][j][1];
                }
        
        k=(f[n][n][1]<f[n][n][0]);
        // deb(k)
        if(zerorow!=-1 && f[n][n][k])
        {
            cout<<1<<endl;
            fo(i,1,zerorow)
            cout<<'D';
            fo(i,1,n)
            cout<<'R';
            fo(i,zerorow,n)
            cout<<'D';
            return;
        }
        
        cout<<f[n][n][k]<<endl;
        fn(n,n);
                
    	
    }

/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
//   freopen('a.txt', 'r', stdin); freopen('a_out.txt', 'w', stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n;
    solve();
    
   return 0;
}