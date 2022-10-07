#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO          {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define yes "Yes"
#define no "No"
#define pb push_back
#define mp make_pair
#define all(v) (v.begin(),v.end())
typedef vector<int> vi;
typedef vector<long long> vl;
vector<pair<ll,ll>> v;

void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true) {
            for(int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    for(int p=2;p<=n;p++){
        if(prime[p]){
          cout << p << " ";
        }
    }
}

void solve()
{   
   int n;
   cin>>n; //Enter the value of n upto which you need prime_numbers
   SieveOfEratosthenes(n);
   cout<<endl;
}


    
//<><><><><><><><><><><><>><><>><><><><><><><>

int32_t main()
{ 
    fastIO;
    auto start = std::chrono::high_resolution_clock::now(); 
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();        
    } 
    
    return 0;
}