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
inline ll rs(ll n) { return (n = n % mod) >= 0 ? n : n + mod; }
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
#define segment 0
#define prefix 1
#define suffix 2
#define sum 3
#define lazy 4
    V<vi> tree;
    // segment, prefix, suffix, sum, lazyassign
    seg(ll n)
    {
        ll n1 = 1;
        while (n1 < n)
            n1 <<= 1;
        tree.assign(n1 * 2, {0, 0, 0, 0, INT_INF});
    }
    vi opr(vi &a, vi &b)
    {
        vi c = a;
        c[segment] = max(a[segment], b[segment], a[suffix] + b[prefix]);
        c[prefix] = max(a[prefix], a[sum] + b[prefix]);
        c[suffix] = max(b[suffix], b[sum] + a[suffix]);
        c[sum] = a[sum] + b[sum];
        c[lazy] = INT_INF;
        return c;
    }
    void update(ll l, ll r, ll val, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return;
        else if (l <= start && end <= r)
        {
            ll c = val * (end - start + 1);
            tree[node] = {max(0LL, c), max(0LL, c), max(0LL, c), c, val};
            return;
        }
        if (tree[node][lazy] != INT_INF)
        {
            ll left = tree[node][lazy] * (mid - start + 1);
            ll right = tree[node][lazy] * (end - (mid + 1) + 1);
            tree[lnode] = {max(0LL, left), max(0LL, left), max(0LL, left), left, tree[node][lazy]};
            tree[rnode] = {max(0LL, right), max(0LL, right), max(0LL, right), right, tree[node][lazy]};
            tree[node][lazy] = INT_INF;
        }
        update(l, r, val, lnode, start, mid);
        update(l, r, val, rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
    }
};
void func()
{
    newint(n, m);
    seg s(n);
    range(i, m)
    {
        newint(a, b, c);
        s.update(a, b - 1, c, 0, 0, n - 1);
        print(s.tree[0][segment]);
    }
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    func();
}
