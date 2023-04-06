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
// #pragma GCC target("avx2")

// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)
#define popcount(x) __builtin_popcountll(x)
#define clz(x) (63 - __builtin_clzll(x)) // count leading zeros
#define ctz(x) __builtin_ctzll(x)        // count trailing zeros
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
ll mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n %= mod) >= 0 ? n : n + mod; }
// define rll above this
#define __RLL__ 1
template <typename T>
ll power(T, ll);
inline ll inv(ll n) { return power(n, mod - 2); }
class rll
{
public:
    int64_t val;
    rll power(unsigned long long y) { return ::power(val, y); }
    rll div_by(ll x) { return val / x; }
    friend inline istream &operator>>(istream &cc, rll &a) { return (cc >> a.val), (a += 0), cc; }
    operator int64_t() const { return val; }
    // template <typename T>
    rll(int _val) : val(rs(_val)) {}
    rll(ll _val) : val(rs(_val)) {}
    rll() : val(0) {}
    // arithmetic operators
    inline rll operator++() { return val++; }
    inline rll operator--() { return val--; }
    inline rll operator+(rll a) { return rs(val + a.val); }
    inline rll operator-(rll a) { return rs(val - a.val); }
    inline rll operator*(rll a) { return rs(a.val * val); }
    inline rll operator/(rll a) { return inv(a) * *this; }
    inline rll operator%(rll a) { return rs(val % a.val); }
    template <typename T, typename U>
    friend inline rll operator+(T &&a, U &&b) { return rll(a) + rll(b); }
    template <typename T, typename U>
    friend inline rll operator-(T &&a, U &&b) { return rll(a) - rll(b); }
    template <typename T, typename U>
    friend inline rll operator*(T &&a, U &&b) { return rll(a) * rll(b); }
    template <typename T, typename U>
    friend inline rll operator/(T &&a, U &&b) { return rll(a) / rll(b); }
    template <typename T, typename U>
    friend inline rll operator%(T &&a, U &&b) { return rll(a) % rll(b); }

    template <typename T, typename U>
    friend inline rll operator+=(T &&a, U &&b) { return a = rll(a) + rll(b); }
    template <typename T, typename U>
    friend inline rll operator-=(T &&a, U &&b) { return a = rll(a) - rll(b); }
    template <typename T, typename U>
    friend inline rll operator*=(T &&a, U &&b) { return a = rll(a) * rll(b); }
    template <typename T, typename U>
    friend inline rll operator/=(T &&a, U &&b) { return a = rll(a) / rll(b); }
    template <typename T, typename U>
    friend inline rll operator%=(T &&a, U &&b) { return a = rll(a) % rll(b); }

    // logical operators
    inline bool operator<(rll &&a) { return (val < a.val); }
    inline bool operator>(rll &&a) { return (val > a.val); }
    inline bool operator<=(rll &&a) { return (val <= a.val); }
    inline bool operator>=(rll &&a) { return (val >= a.val); }
    inline bool operator!() { return !val; }

    template <typename T, typename U>
    friend inline bool operator<(T &&a, U &&b) { return (ll)a < (ll)b; }
    template <typename T, typename U>
    friend inline bool operator>(T &&a, U &&b) { return (ll)a > (ll)b; }
    template <typename T, typename U>
    friend inline bool operator<=(T &&a, U &&b) { return (ll)a <= (ll)b; }
    template <typename T, typename U>
    friend inline bool operator>=(T &&a, U &&b) { return (ll)a >= (ll)b; }
    explicit operator int() const {
        return val;
    }
};
template <typename T>
ll power(T _x, ll _y)
{
    rll x = _x;
    _y %= mod - 1;
    rll res = 1;
    while (_y)
    {
        if (_y & 1LL)
            res *= x;
        _y >>= 1;
        x = x * x;
    }
    return res;
}

#ifndef __RLL__
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
#endif
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

V<rll> f = {1};
rll fac(ll n)
{
    while (n >= f.size())
        f.pb(f.back() * (ll)f.size());
    return f[n];
}
ll n;
rll NCR(rll n, rll r)
{
    return fac(n) / (fac(r) * fac(n - r));
}
void func()
{
    cin >> n >> mod;
    rll ans = 0;
    if (n % 2 == 0)
    {
        range(dis, 1, n / 2)
        {
            rll tempans = 0;
            ll left = n - dis - 2;
            range(r, 0, dis)
            {
                ll N = dis - 1;
                tempans += fac(left + r) * NCR(N, r);
            }
            ans += tempans * (dis);
        }
        range(i, 0, n / 2)
        {
            ll right = n / 2 - 1;
            ll tlft = n / 2 - 1;
            ans += fac(right + i) * NCR(tlft, i);
        }
    }
    else
    {
        range(dis, 1, n / 2 + 1)
        {
            rll tempans = 0;
            ll left = n - dis - 2;
            range(r, 0, dis)
            {
                ll N = dis - 1;
                tempans += fac(left + r) * NCR(N, r);
            }
            // print(tempans);
            ans += tempans * (dis);
        }
    }
    print(ans * n);
}
int main()
{
    FAST;
    func();
}