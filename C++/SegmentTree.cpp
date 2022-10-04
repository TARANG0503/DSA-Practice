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

class SegmentTree {
    v(int) a;
    int n;
    //just call the constructor to build the tree

    void build(v(int) &input, int treeIdx, int lo, int hi) {
        if (lo == hi)
            a[treeIdx] = input[lo];
        else {
            int mid = lo + (hi - lo) / 2;
            int leftTree = 2 * treeIdx + 1, rightTree = leftTree + 1;
            build(input, leftTree, lo, mid);
            build(input, rightTree, mid + 1, hi);
            //GCD, change as per needs
            a[treeIdx] = __gcd(a[leftTree], a[rightTree]);
        }
    }

    int queryUtil(int lo, int hi, int treeIdx, int rangeLb, int rangeUb) {
        if (lo == rangeLb and hi == rangeUb)
            return a[treeIdx];
        int mid = lo + (hi - lo) / 2;
        if (rangeUb <= mid) //only left
            return queryUtil(lo, mid, 2 * treeIdx + 1, rangeLb, min(mid, rangeUb));
        else if (rangeLb > mid) //only right
            return queryUtil(mid + 1, hi, 2 * treeIdx + 2, max(mid + 1, rangeLb), rangeUb);
        else //GCD, change as per needs
            return __gcd(queryUtil(lo, mid, 2 * treeIdx + 1, rangeLb, min(mid, rangeUb)),
                         queryUtil(mid + 1, hi, 2 * treeIdx + 2, max(mid + 1, rangeLb), rangeUb));
    }

    void updateUtil(int lo, int hi, int treeIdx, int idx, int val) {
        if (lo == idx and hi == idx) {
            a[treeIdx] = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (idx <= mid) //left
            updateUtil(lo, mid, 2 * treeIdx + 1, idx, val);
        else //right
            updateUtil(mid + 1, hi, 2 * treeIdx + 2, idx, val);
        //GCD, change as per needs
        a[treeIdx] = __gcd(a[2 * treeIdx + 1], a[2 * treeIdx + 2]);
    }

public:

    SegmentTree(v(int) &input) {
        n = sz(input);
        a.assign(4 * n, -1); //mind it
        build(input, 0, 0, n - 1);
    }

    int query(int rangeLb, int rangeUb) {
        //can't handle invalid queries
        return queryUtil(0, n - 1, 0, rangeLb, rangeUb);
    }

    void update(int idx, int val) {
        //can't handle invalid queries
        updateUtil(0, n - 1, 0, idx, val);
    }
};

void solve() {

}

signed main() {
    fastio();
    int t = 1;
    cin >> t;
    ff(i, t) {
        // cout << "Case #" << i << ": \n";
        solve();
    }
    return 0;
}
