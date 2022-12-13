#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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

vvi g, up;
vi depth;
ll find_lca(ll a, ll b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    range(i, 18, -1, -1)
    {
        if (up[a][i] != -1 && depth[up[a][i]] >= depth[b])
            a = up[a][i];
    }
    range(i, 18, -1, -1)
    {
        if (up[a][i] != up[b][i])
            a = up[a][i],
            b = up[b][i];
    }
    if (a == b)
        return a;
    else
        return up[a][0];
}
ll lift(ll a, ll to_depth)
{
    range(i, 18, -1, -1)
    {
        if (up[a][i] == -1 || (1 << i) > to_depth)
            continue;
        to_depth -= (1 << i);
        a = up[a][i];
    }
    return a;
}
void func()
{
    newint(a, b, c);
    ll u = find_lca(a, b);
    ll fpath = depth[a] + depth[b] - 2 * depth[u];
    if (fpath <= c)
    {
        give(b);
    }
    ll hpath = depth[a] - depth[u];
    if (hpath >= c)
    {
        range(i, 18, -1, -1)
        {
            if (up[a][i] == -1 || (1 << i) > c)
                continue;
            c -= (1 << i);
            a = up[a][i];
        }
        give(a);
    }
    else
    {
        c = fpath - c;
        range(i, 18, -1, -1)
        {
            if (up[b][i] == -1 || (1 << i) > c)
                continue;
            c -= (1 << i);
            b = up[b][i];
        }
        give(b);
    }
}

int main()
{
    newint(n);
    g = vvi(n + 1);
    range(n - 1)
    {
        newint(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // hang on 1
    stack<ll> dfs;
    depth = vi(n + 1);
    depth[1] = 0;
    vi visit(n + 1);
    dfs.push(1);
    up = vvi(n + 1, vi(19, -1));
    while (dfs.size())
    {
        ll x = dfs.top();
        dfs.pop();
        visit[x] = true;
        foreach (i, g[x])
        {
            if (!visit[i])
            {
                depth[i] = depth[x] + 1;
                dfs.push(i);
                up[i][0] = x;
                range(j, 1, 19)
                {
                    if (up[i][j - 1] == -1 || up[up[i][j - 1]][j - 1] == -1)
                        break;
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
    }
    newint(q);
    while (q--)
    {
        func();
    }
}
