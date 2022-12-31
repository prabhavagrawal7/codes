#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)
#define popcount(x) __builtin_popcount(x)
#define clz(x) (63 - __builtin_clzl(x)) // count leading zeros
#define ctz(x) __builtin_ctz(x)         // count trailing zeros
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
#define r4(var, start, stop, step) for (ll var = start; step > 0 ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (ll var = start; var < stop; ++var)
#define r2(var, stop) for (ll var = 0; var < stop; ++var)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 < stop; ++start_from_0)
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
#define ppb pop_back
#define pf push_front
#define ppf pop_front
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
istream &operator>>(istream &is, V<T> &v)
{
    range(i, v.size()) { is >> v[i]; }
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const V<T> &v)
{
    range(i, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); }
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
const ll mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n = n % mod) >= 0 ? n : n + mod; }
ll power(ll x, ll y)
{
    x %= mod, y %= mod - 1;
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
ll inv(ll n) { return power(n, mod - 2); }

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

vvi g;
vi depth, parent, vis;
si vc1, vc2;
pair<bool, bool> dfs(ll n)
{
    vis[n] = true;
    foreach (i, g[n])
    {
        if (vis[i])
            continue;
        depth[i] = depth[n] + 1;
        parent[i] = n;
        auto ans = dfs(i);
        if (ans.first)
            vc1.insert(n);
        if (ans.second)
            vc2.insert(n);
    }
    return {vc1.count(n), vc2.count(n)};
}
vi coin1;
vi coin2;
ll dislim;
ll dfs(ll n, ll mode)
{
    ll ans = 0;
    vis[n] = true;
    if (mode == 0)
    {
        coin1.push_back(n);
        ans++;
        coin2.push_back(n);
        ans++;
        foreach (i, g[n])
        {
            if (vis[i] || (vc1.count(i) == 0 && vc2.count(i) == 0))
                continue;
            if (vc1.count(i) && vc2.count(i))
                ans += dfs(i, 0);
            else if (vc1.count(i))
                ans += dfs(i, 1);
            else
                ans += dfs(i, 2);
        }
        while (coin1.size() > coin2.size())
        {
            coin1.pop_back();
            ans++;
        }
        while (coin1.size() < coin2.size())
        {
            coin2.pop_back();
            ans++;
        }
        coin1.pop_back();
        ans++;
        coin2.pop_back();
        ans++;
    }
    else if (mode == 1)
    {
        coin1.pb(n);
        ans++;
        foreach (i, g[n])
        {
            if (vis[i] || vc1.count(i) == 0)
                continue;
            if (coin1.size() - coin2.size() == dislim)
            {
                coin2.push_back(coin1[coin2.size()]);
                ans++;
            }
            ans += dfs(i, 1);
        }
        coin1.pop_back();
        ans++;
        while (coin2.size() > coin1.size())
        {
            coin2.pop_back();
            ans++;
        }
    }
    else
    {
        coin2.pb(n);
        ans++;
        foreach (i, g[n])
        {
            if (vis[i] || vc2.count(i) == 0)
                continue;
            if (coin2.size() - coin1.size() == dislim)
            {
                coin1.push_back(coin2[coin1.size()]);
                ans++;
            }
            ans += dfs(i, 2);
        }
        coin2.pop_back();
        ans++;
        while (coin1.size() > coin2.size())
        {
            coin1.pop_back();
            ans++;
        }
    }
    return ans;
}
void func()
{
    ll n;
    cin >> n >> dislim;
    g.assign(n + 1, {});
    range(i, n - 1)
    {
        newint(a, b);
        g[a].pb(b);
        g[b].pb(a);
    }
    newint(c1);
    range(i, c1)
    {
        newint(x);
        vc1.insert(x);
    }
    newint(c2);
    range(i, c2)
    {
        newint(x);
        vc2.insert(x);
    }
    depth.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    dfs(1);
    vis.assign(n + 1, 0);
    print(dfs(1, 0) - 4);
}
int main()
{
    // FAST;
    func();
}
