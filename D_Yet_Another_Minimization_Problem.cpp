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
ll rr;

ll code(ll n, ll sum1, ll sum2, vi &avec, vi &bvec, UM<ll, UM<ll, ll>> &dp)
{
    if (n == avec.size() - 1 || n == avec.size())
        return rr;
    if (dp.count(n) && dp[n].count(sum1))
        return dp[n][sum1];
    ll ans1 = code(n + 1, sum1, sum2, avec, bvec, dp);
    ll nsum1 = sum1 - avec[n] + bvec[n];
    ll nsum2 = sum2 + avec[n] - bvec[n];
    ll ans2 = code(n + 1, nsum1, nsum2, avec, bvec, dp);
    ll opr = (sum1 - avec[n]) * (bvec[n] - avec[n]) + (sum2 - bvec[n]) * (avec[n] - bvec[n]);
    return dp[n][sum1] = min(ans1, ans2 + opr);
}
void func()
{
    newint(n);
    vi avec = inputvec(n);
    vi bvec = inputvec(n);
    ll ans = 0;
    foreach (i, avec)
        ans += i * i;
    foreach (i, bvec)
        ans += i * i;
    rr = 0;
    range(i, n)
    {
        range(j, i + 1, n)
        {
            rr += avec[i] * avec[j] + bvec[i] * bvec[j];
        }
    }
    ll sum1 = accumulate(all(avec), 0LL), sum2 = accumulate(all(bvec), 0LL);
    UM<ll, UM<ll, ll>> dp;
    ll nans = code(0, sum1, sum2, avec, bvec, dp);
    print((n - 1) * ans + 2 * nans);
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
