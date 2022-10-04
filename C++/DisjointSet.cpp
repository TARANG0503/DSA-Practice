#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

//debugging template
//https://codeforces.com/blog/entry/68809

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


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
#define fi first
#define se second
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

//pbds
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
//order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
//consider it an array, it gives a[k - 1]


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
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
}

class disjointSet {
public:
    int n;
    vector<int> parent, rank;

    disjointSet(int sz) {
        n = sz;
        parent.resize(n);
        rank.assign(n, 1);
        iota(parent.begin(), parent.end(), 0ll);
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            if (rank[x] < rank[y])
                swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }
};

void solve() {

}

signed main() {
    auto start = high_resolution_clock::now();
    fastio();
    int t = 1;
    cin >> t;
    ff(i, t) {
        // cout << "Case #" << i << ": \n";
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "\nFinished in " << duration.count() << " µs!\n";
    return 0;
}
