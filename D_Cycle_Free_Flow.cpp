#include <bits/stdc++.h>
// Uncomment them for optimisations
#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
using namespace std;
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
#define INF LONG_LONG_MAX
#define INT_INF INT_MAX
#define ll long long
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
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define newstring(str) \
    string str;        \
    cin >> str;
#define foreach(a, x) for (auto &a : x)
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef map<ll, ll> mii;
typedef set<ll> si;
typedef vector<vector<ll>> vvi;
template <typename... T>
void take_input(T &&...args) { ((cin >> args), ...); }
ll input()
{
    newint(n);
    return n;
}
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    for (ll i = start; i < n; i++)
    {
        vec[i] = input();
    }
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
template <typename... T>
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
inline ll gcd(ll m, ll n) { return __gcd(m, n); }
inline ll rs(ll n) { return n % mod; }

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
const ll LOG = 20;
vvi up;
vvi minwup;
vi depth;
ll find_lca(ll a, ll b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    range(i, LOG - 1, -1, -1)
    {
        if (depth[a] - (1 << i) >= depth[b])
            a = up[a][i];
    }
    if (a == b)
        return a;
    range(i, LOG - 1, -1, -1)
    {
        if (up[a][i] != up[b][i])
            a = up[a][i], b = up[b][i];
    }
    return up[a][0];
}
int main()
{
    // Uncomment for faster I/O
    FAST;
    newint(n, m);
    V<V<pii>> g(n + 1);
    range(m)
    {
        newint(a, b, w);
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    // some processing
    up = vvi(n + 1, vi(LOG, -1));
    minwup = vvi(n + 1, vi(LOG, INT_INF));
    depth = vi(n + 1, 0);
    stack<ll> dfs;
    dfs.push(1);
    V<bool> visit(n + 1);
    while (dfs.size())
    {
        ll x = dfs.top();
        dfs.pop();
        visit[x] = true;
        foreach (i, g[x])
        {
            ll I = i.first;
            if (!visit[I])
            {
                ll WEIGHT = i.second;
                depth[I] = depth[x] + 1;
                dfs.push(I);
                up[I][0] = x;
                minwup[I][0] = WEIGHT;
                range(j, 1, LOG)
                {
                    if (up[I][j - 1] == -1 || up[up[I][j - 1]][j - 1] == -1) break;
                    minwup[I][j] = min(minwup[I][j - 1], minwup[up[I][j - 1]][j - 1]);
                    up[I][j] = up[up[I][j - 1]][j - 1];
                }
            }
        }
    }
    newint(q);
    range(q)
    {
        newint(a, b);
        ll u = find_lca(a, b);
        ll ans = INT_INF;
        range(i, LOG - 1, -1, -1)
        {
            if (depth[a] - (1 << i) >= depth[u])
            {
                ans = min(ans, minwup[a][i]);
                a = up[a][i];
            }
        }
        range(i, LOG - 1, -1, -1)
        {
            if (depth[b] - (1 << i) >= depth[u])
            {
                ans = min(ans, minwup[b][i]);
                b = up[b][i];
            }
        }
        print(ans);
    }
}
