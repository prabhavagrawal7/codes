#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
const ll limit = 1e5;
V<vi> factors(limit + 1);
void find_factors()
{
    // range(i, factors.size()) {factors[i].reserve(20);}
    range(i, 2, limit)
    {
        for (ll j = i * i; j < limit; j += i)
        {
            factors[j].push_back(i);
        }
    }
}
void func()
{
    newint(a, b, c);
    ll ans = INF;
    ll ca = 1, cb = 1, cc = 1;
    range(tb, 1, b * 2)
    {
        ll ta = 1;
        if (abs(a - tb) < abs(a - ta))
            ta = tb;
        auto &fac = factors[tb];
        ll l = 0, r = fac.size(), mid;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (fac[mid] > a)
                r = mid;
            else
                l = mid;
        }
        if (l < fac.size() && abs(a - fac[l]) < abs(a - ta))
            ta = fac[l];
        if (l + 1 < fac.size() && abs(a - fac[l + 1]) < abs(a - ta))
            ta = fac[l + 1];

        l = 0, r = fac.size();
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (tb / fac[mid] >= a)
                l = mid;
            else
                r = mid;
        }
        if (l < fac.size() && abs(a - tb / fac[l]) < abs(a - ta))
            ta = tb / fac[l];
        if (l + 1 < fac.size() && abs(a - tb / fac[l + 1]) < abs(a - ta))
            ta = tb / fac[l + 1];

        ll tc = (c / tb) * tb;
        if (abs(tc - c) > abs(tc + tb - c))
            tc = tc + tb;
        ll tempans = abs(ta - a) + abs(tb - b) + abs(tc - c);
        if (ans > tempans)
        {
            ca = ta, cb = tb, cc = tc;
            ans = tempans;
        }
    }
    print(abs(ca - a) + abs(cb - b) + abs(cc - c));
    print(ca, cb, cc);
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    find_factors();
    newint(t);
    range(t)
    {
        func();
    }
}
