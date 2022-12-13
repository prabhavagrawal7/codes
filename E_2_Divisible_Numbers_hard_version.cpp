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
            res = (res * x);
        y >>= 1;
        x = (x * x);
    }
    return res;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
V<pii> factors(ll n)
{
    V<pii> ans;
    while (n % 2 == 0)
    {
        if (ans.size())
            ans[ans.size() - 1].second++;
        else
            ans.push_back({2, 1});
        n >>= 1;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            if (ans.size() && ans.back().first == i)
                ans[ans.size() - 1].second++;
            else
                ans.push_back({i, 1});
            n /= i;
        }
    }
    if (n != 1)
    {
        ans.push_back({n, 1});
    }
    if (ans.size() == 0)
        ans.push_back({1, 1});
    return ans;
}
void increment(V<pii> &tfac, vector<int> &coff)
{
    coff[0]++;
    range(i, coff.size() - 1)
    {
        if (coff[i] > tfac[i].second)
        {
            coff[i] = 0;
            coff[i + 1] += 1;
        }
        else
            return;
    }
}
void func()
{
    newint(a, b, c, d);
    auto fa = factors(a), fb = factors(b);
    // join factors
    V<pii> tfac;
    ll itr1 = 0, itr2 = 0;
    // make tfac
    while (true)
    {
        if (itr1 == fa.size() && itr2 == fb.size())
            break;
        else if (itr1 == fa.size())
        {
            tfac.push_back(fb[itr2]);
            itr2++;
        }
        else if (itr2 == fb.size())
        {
            tfac.pb(fa[itr1]);
            itr1++;
        }
        else
        {
            if (fa[itr1].first < fb[itr2].first)
            {
                tfac.push_back(fa[itr1]);
                itr1++;
            }
            else if (fa[itr1].first > fb[itr2].first)
            {
                tfac.push_back(fb[itr2]);
                itr2++;
            }
            else
            {
                tfac.push_back({fa[itr1].first, fa[itr1].second + fb[itr2].second});
                itr1++, itr2++;
            }
        }
    }

    V<int> coff(tfac.size(), 0);
    while (coff.back() != tfac.back().second + 1)
    {
        ll u = 1;
        range(i, coff.size())
            u *= power(tfac[i].first, coff[i]);
        ll v = a * b / u;
        if (btn(a + 1, c / u * u, c) && btn(b + 1, d / v * v, d))
        {
            give(c / u * u, d / v * v);
        }
        increment(tfac, coff); 
    }
    give(-1, -1);
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
