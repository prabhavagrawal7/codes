#include "bits/stdc++.h"
using namespace std;
#define ll int64_t

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)
#define popcount(x) __builtin_popcount(x)
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
#define r4(var, start, stop, step) for (ll var = start; step >= 0 ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (ll var = start; var < stop; var++)
#define r2(var, stop) for (ll var = 0; var < stop; var++)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 < stop; start_from_0++)
#define newint(...) \
    ll __VA_ARGS__; \
    take_input(__VA_ARGS__)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define give(...)           \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    }
#define endl "\n"
#define FULL_INF numeric_limits<double>::infinity()
#define INF INT64_MAX
#define INT_INF INT32_MAX
#define ld long double
#define V vector
#define P pair
#define S set
#define MS multiset
#define M map
#define UM unordered_map
#define US unordered_set
#define MM multimap
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define pf push_front
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
string db_bin(ll n)
{
    string ans;
    while (n)
    {
        ans.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(all(ans));
    return ans;
}
#define newstring(str) \
    string str;        \
    cin >> str;
#define foreach(a, x) for (auto &&a : x)
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef map<ll, ll> mii;
typedef set<ll> si;
typedef vector<vector<ll>> vvi;
template <typename... T>
inline void take_input(T &&...args) { ((cin >> args), ...); }
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    range(i, start, n) cin >> vec[i];
    return vec;
}
template <typename T>
inline bool btn(T a, T b, T c)
{
    if ((a <= b && b <= c) || (a >= b && b >= c))
        return true;
    return false;
}
template <typename T>
ostream &operator<<(ostream &os, const V<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}
template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}
template <typename... T>
inline void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
inline void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
const int64_t mod = 1000000007;
// const ll mod = 998244353;
#define rs(n) (n) % mod
ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1LL)
            res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res % mod;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

struct seg
{
#define mid (start + end) / 2
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
    V<pair<ll, ll>> tree;
    // sum , mul

    seg(ll n)
    {
        tree.assign(n * 4, {1, 1});
        buildtree(0, 0, n - 1);
    }

    void buildtree(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = {1, 1};
            return;
        }
        buildtree(lnode, start, mid);
        buildtree(rnode, mid + 1, end);
        tree[node].first = rs(tree[lnode].first * tree[lnode].second +
                              tree[rnode].first * tree[rnode].second);
        return;
    }
    void rupdate(ll l, ll r, ll val, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return;
        else if (l <= start && end <= r)
        {
            tree[node].second = rs(tree[node].second * val);
            return;
        }
        tree[lnode].second = rs(tree[lnode].second * tree[node].second);
        tree[rnode].second = rs(tree[rnode].second * tree[node].second);
        tree[node].second = rs(1);
        rupdate(l, r, val, lnode, start, mid);
        rupdate(l, r, val, rnode, mid + 1, end);
        tree[node].first = rs(tree[lnode].first * tree[lnode].second +
                              tree[rnode].first * tree[rnode].second);
        return;
    }

    ll rfind(ll l, ll r, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return 0;
        else if (l <= start && end <= r)
        {
            return rs(tree[node].first * tree[node].second);
        }
        tree[node].first = rs(tree[node].first * tree[node].second);
        tree[lnode].second = rs(tree[lnode].second * tree[node].second);
        tree[rnode].second = rs(tree[rnode].second * tree[node].second);
        tree[node].second = rs(1);
        return rs(rfind(l, r, lnode, start, mid) + rfind(l, r, rnode, mid + 1, end));
    }
};
void func()
{
    newint(n, m);
    seg s(n);
    range(i, m)
    {
        newint(a);
        if (a == 1)
        {
            newint(b, c, d);
            s.rupdate(b, c - 1, d, 0, 0, n - 1);
        }
        else
        {
            newint(b, c);
            print(s.rfind(b, c - 1, 0, 0, n - 1));
        }
    }
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    func();
}
    