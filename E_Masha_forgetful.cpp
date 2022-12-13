#include <bits/stdc++.h>
// Uncomment them for optimisations
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
using namespace std;
#define cntpop(x) __builtin__popcount(x)
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
#define ll int
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
//const ll mod = 998244353;
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

void func()
{
    newint(n, size);
    V<string> vstr(n);
    range(i, n)
    {
        cin >> vstr[i];
    }
    newstring(str);

    map<string, vector<ll>> store;

    range(i, n)
    {
        range(j, size)
        {
            if (j + 1 < size)
                store[vstr[i].substr(j, 2)] = {j, j + 1, i};
            if (j + 2 < size)
                store[vstr[i].substr(j, 3)] = {j, j + 2, i};
        }
    }
    UM<ll, vi> dp;
    dp[size] = vi();
    dp[size - 1] = vi(1, -1);
    dp[size + 1] = vi(1, -1);
    range(i, size - 2, -1, -1)
    {
        if (dp[i + 2] != vi(1, -1) && store.find(str.substr(i, 2)) != store.end())
        {
            dp[i] = store[str.substr(i, 2)];
        }
        else if (dp[i + 3] != vi(1, -1) && store.find(str.substr(i, 3)) != store.end())
        {
            dp[i] = store[str.substr(i, 3)];
        }
        else
        {
            dp[i] = vi(1, -1);
        }
    }
    if (dp[0] == vi(1, -1))
    {
        give(-1);
    }
    V<vi> ans;
    ll u = 0;
    while (u != size)
    {
        ans.push_back(dp[u]);
        if (dp[u][1] - dp[u][0] == 1)
        {
            u += 2;
        }
        else
            u += 3;
    }
    print(ans.size());
    range(i, ans.size())
    {
        range(j, ans[i].size())
        {
            cout << ans[i][j] +1<< " ";
        }
        cout << endl;
    }
}
int main()
{
    // Uncomment for faster I/O
    FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
