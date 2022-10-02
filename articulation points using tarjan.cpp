#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define double long double
#define endl "\n"
#define v(x) vector<x>
#define pb push_back
#define all(s) s.begin(),s.end()
#define sz(x) (int)x.size()
#define f(i,n) for(int i = 0; i < n; ++i)
#define ff(i,n) for(int i = 1; i <= n; ++i)
#define frev(i,n) for(int i = n; i >= 0; --i)
#define rep(i, lo, hi, inc) for(int i=lo; i<=hi and inc>0 or i >= hi and inc<0; i+=inc)
#define input(x) for(auto &e:x)cin>>e
#define fa(x) for(auto it:x)
#define far(x) for(auto &it:x)
#define sci(x) int x; cin>>x
#define scii(x,y) int x,y; cin>>x>>y
#define sciii(x,y,z) int x,y,z; cin>>x>>y>>z
#define print(x) fa(x) cout<<it<<" ";cout<<"\n"
#define numberOfSetBits(x) __builtin_popcountll(x)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
int MOD = 1e9 + 7, intmax = LLONG_MAX, intmin = LLONG_MIN;

int power(int x, int y, int p = MOD) { //gives x^y, logy time
    int res = 1; x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1; x = (x * x) % p;
    }
    return res;
}

int add(int x, int y, int mod = MOD) {return ( (x % mod) + (y % mod)) % mod;}
int subtract(int x, int y, int mod = MOD) {return ((x % mod) - (y % mod) + mod) % mod;}
int multiply(int x, int y, int mod = MOD) {return ( (x % mod) * (y % mod)) % mod;}
int divide(int x, int y, int mod = MOD) { //y and mod must be coprime,log(mod) time
    x %= mod; y %= mod; int gcd = __gcd(x, y); x /= gcd; y /= gcd;
    int yinverse = power(y, mod - 2, mod); return (x * yinverse) % mod;
}

v(int) factorial;
void computeFactorialTill(int maxn, int mod = MOD) {
    factorial.assign(maxn + 1, 1);//call this fn in main, O(maxn) time
    ff(i, maxn)
    factorial[i] = (i * factorial[i - 1]) % mod;
}

int ncr(int n, int r, int mod = MOD) {
    if (r > n - r) r = n - r; //O(maxn) time due to computing factorial
    return divide(factorial[n], factorial[r] * factorial[n - r], mod);
}

void query(int a, int b) {
    cout << "? " << a << ' ' << b << endl; cout.flush();
}

int n, m, timer;
v(v(int)) adj;
v(int) disc, ap, low;

void tarjan(int node, int parent = -1) {
    disc[node] = low[node] = ++timer;
    int children = 0;
    for (auto child : adj[node]) {
        if (disc[child] == 0) {
            ++children;
            tarjan(child, node);
            low[node] = min(low[node], low[child]);
            if (parent == -1 and children > 1)
                ap[node] = 1;
            if (parent != -1 and disc[node] <= low[child])
                ap[node] = 1;
        }
        else if (child != parent)
            low[node] = min(low[node], disc[child]);
    }
}

void solve() {
    adj.assign(n, {});
    disc.assign(n, 0);
    ap.assign(n, 0);
    low.assign(n, 0);
    timer = 0;
    f(i, m) {
        scii(x, y);
        adj[x - 1].pb(y - 1);
        adj[y - 1].pb(x - 1);
    }
    f(i, n) {
        if (disc[i] == 0)
            tarjan(i);
    }
    cout << count(all(ap), 1) << endl;
}

signed main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (true) {
        // cout << "Case #" << i << ": \n";
        cin >> n >> m;
        if (n == 0 and m == 0)
            break;
        solve();
    }
    return 0;
}
/*
input :
3 3
1 2
2 3
1 3
6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2
3 5
0 0

output :
0
1
*/
