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

void solve() {
    scii(n, e);
    vp adj[n];
    f(i, e) {
        sciii(x, y, z);
        adj[x - 1].pb({y - 1, z});
        // adj[y - 1].pb({x - 1, z});
    }
    v dist(n, intmax);
    dist[0] = 0;
    priority_queue<pii, vp, greater<pii>> q;
    q.push({0, 0});
    int d, node, nbr, nbr_dist;
    vb visited(n, false);
    while (not q.empty()) {
        d = q.top().fi, node = q.top().se;
        // cout << node << ' ' << d << endl;
        q.pop();
        if (visited[node] == true)
            continue;
        visited[node] = true;
        for (auto p : adj[node]) {
            nbr = p.first, nbr_dist = p.se;
            // tie(nbr, nbr_dist) = p;
            if (dist[nbr] > d + nbr_dist) {
                dist[nbr] = d + nbr_dist;
                q.push({dist[nbr], nbr});
            }
        }
    }
    print(dist);
}
//0 9 11 20 13 14 19 29 27
//
signed main() {
    fastio();
    int t = 1;
    // cin >> t;
    ff(i, t) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
