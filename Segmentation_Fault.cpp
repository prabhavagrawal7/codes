#include "bits/stdc++.h"
using namespace std;
#define ll long long

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

// for segment tree
#define mid (start+end)/2
#define lnode (node*2+1)
#define rnode (node*2+2)
#define popcount(x) __builtin_popcount(x)
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...)                         \
    GET_MACRO(__VA_ARGS__, r4, r3, r2, r1) \
    (__VA_ARGS__)
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
const ll mod = 1000000007;
// const ll mod = 998244353;
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
void take_input(T &&...args) { ((cin >> args), ...); }
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    range(i, start, n) cin >> vec[i];
    return vec;
}
template <typename T>
bool btn(T a, T b, T c)
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
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
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

class stree
{
public:
    vi vec, lazy;
    ll n;
    void buildtree(ll node, ll start, ll end)
    {
        if (start == end)
        {
            vec[start];
            return;
        }
        buildtree(lnode, start, mid);
        buildtree(rnode, mid + 1, end);
    }

    stree(vi vec)
    {
        this->vec = vec;
        lazy.assign(vec.size() * 4, 0);
        n = vec.size();
        buildtree(0, 0, n - 1);
    }
    void ru(ll l, ll r, ll val)
    {
        ru(l, r, val, 0, 0, n-1);
    }
    void ru(ll l, ll r, ll val, ll node, ll start, ll end)
    {
        if (r < start || end < l)
        {
            return;
        }
        else if (l <= start && end <= r)
        {
            lazy[node] += val;
            return;
        }
        lazy[lnode] += lazy[node];
        lazy[rnode] += lazy[node];
        lazy[node] = 0;
        ru(l, r, val, lnode, start, mid);
        ru(l, r, val, rnode, mid + 1, end);
    }

    ll pfind(ll ind)
    {
        return pfind(ind, 0, 0, n - 1);
    }
    ll pfind(ll ind, ll node, ll start, ll end)
    {
        if (start == end)
        {
            return lazy[node];
        }
        lazy[lnode] += lazy[node];
        lazy[rnode] += lazy[node];
        lazy[node] = 0;
        if (ind <= mid)
            return pfind(ind, lnode, start, mid);
        else
            return pfind(ind, rnode, mid + 1, end);
    }
};

void func()
{
    newint(n);
    V<pii> vec;
    stree seg(vi(n, 0));
    range(i, n)
    {
        newint(a, b);
        vec.push_back({a, b});
        seg.ru(a - 1, b - 1, 1);
    }
    vi ans;
    range(i, n)
    {
        if (btn(vec[i].first, i + 1, vec[i].second))
            continue;
        seg.ru(vec[i].first - 1, vec[i].second - 1, -1);
        ll c = seg.pfind(i);
        if (abs(c) == n - 1)
            ans.push_back(i);
        seg.ru(vec[i].first - 1, vec[i].second - 1, 1);
    }
    print(ans.size()); 
    foreach(i, ans){
        print(i+1); 
    }
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
