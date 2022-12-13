#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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
vi ddp(3000, INT_INF);
void ddpm()
{
    ddp[1] = 0;
    range(i, 1, 1001)
    {
        range(j, 1, i + 1)
        {
            ll x = i / j;
            ddp[i + x] = min(ddp[i + x], ddp[i] + 1);
        }
    }
}
ll rec(vi &cost, vi &weight, ll start, ll k, V<vi> &dp)
{
    if (start == cost.size())
        return 0;
    if (dp[start][k] != -1)
        return dp[start][k];
    if (k - cost[start] >= 0)
    {
        return dp[start][k] = max(
                   rec(cost, weight, start + 1, k, dp),
                   rec(cost, weight, start + 1, k - cost[start], dp) + weight[start]);
    }
    else
    {
        return dp[start][k] = rec(cost, weight, start + 1, k, dp);
    }
}
void func()
{
    newint(n, k);
    vi vec = inputvec(n);
    vi weight = inputvec(n);
    vi cost;
    cost.reserve(n);
    ll sum = 0;
    foreach (i, vec)
    {
        cost.push_back(ddp[i]);
        sum += ddp[i];
    }
    if (accumulate(all(cost), 0LL) < k)
    {
        give(accumulate(all(weight), 0LL));
    }
    V<vi> dp(n + 1, vi(k + 1, -1));
    print(rec(cost, weight, 0, k, dp));
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    ddpm();
    newint(t);
    range(t)
    {
        func();
    }
}
