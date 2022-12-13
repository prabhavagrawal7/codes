#include <bits/stdc++.h>
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

ll height_opr(vvi &g, ll mid, vi &par)
{
    vi vis(g.size()), vis_bfs(g.size());
    stack<ll> traversed;
    queue<ll> bfs;
    bfs.push(1);
    vis_bfs[1] = true;
    while (bfs.size())
    {
        ll x = bfs.front();
        bfs.pop();
        traversed.push(x);
        foreach (i, g[x])
        {
            if (vis_bfs[i] == 0)
                bfs.push(i);
            vis_bfs[i] = 1;
        }
    }

    // traversed complete
    // chote mote dfs marne honge
    ll ans = 0;
    while (traversed.size())
    {
        ll x = traversed.top();
        traversed.pop();
        if (vis[x])
            continue;
        for (int i = 0; i < mid - 1; i++)
            x = par[x]; 
        if (x == 1 || x == 0 || par[x] == 1)
            break; 
        else
            ans++;

        stack<ll> dfs;
        dfs.push(x);
        vis[x] = true;
        while (dfs.size())
        {
            ll u = dfs.top();
            dfs.pop();
            foreach (i, g[u])
            {
                if (i != par[u] && vis[i] == 0)
                {
                    dfs.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    return ans;
}
void func()
{
    newint(n, k);
    V<vi> g(n + 1);
    vi par(n + 1);
    range(i, n - 1)
    {
        newint(a);
        par[i + 2] = a;
        g[i + 2].pb(a);
        g[a].pb(i + 2);
    }
    ll l = 0, r = n, mid;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        ll x = height_opr(g, mid, par);
        if (x <= k)
            r = mid;
        else
            l = mid;
    }
    print(r);
}
int main()
{
    FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
