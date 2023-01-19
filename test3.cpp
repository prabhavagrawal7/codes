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
inline ll rs(ll n) { return (n = n) >= 0 ? n : n + mod; }
template <typename T>
ll power(T x, ll y)
{
    ll _x = x;
    _x %= mod;
    y %= mod - 1;
    ll res = 1;
    while (y)
    {
        if (y & 1LL)
            res = (res * _x);
        y >>= 1;
        _x = (_x * _x);
    }
    return res;
}
ll inv(ll n) { return power(n, mod - 2); }

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
class ModularInteger
{
private:
    int64_t val = 0;
    int64_t mod = 1e9 + 7;

public:
    operator int64_t() const { return val; }
    template <typename T> operator T() { return static_cast<T>(val); }
    constexpr ModularInteger() : val(0) {}
    template <typename T>
    constexpr ModularInteger(T _n) : val((_n % mod + mod) % mod) {}
    int64_t getMod() { return mod; }
    void setMod(int64_t newMod) { mod = newMod; }
    inline ModularInteger power(ModularInteger b, int64_t p) const noexcept
    {
        int64_t res = 1;
        while (p > 0)
        {
            if (p & 1)
                res = (res * b.val) % mod;
            b.val = (b.val * b.val) % mod;
            p = p >> 1;
        }
        return res;
    }

    // arithmetic operators
    inline ModularInteger operator++() { return val++; }
    inline ModularInteger operator--() { return val--; }
    inline ModularInteger operator+(const ModularInteger a) const noexcept { return ModularInteger(val + a.val); }
    inline ModularInteger operator-(const ModularInteger a) const noexcept { return ModularInteger(val - a.val); }
    inline ModularInteger operator*(const ModularInteger a) const noexcept { return ModularInteger(a.val * val); }
    inline ModularInteger operator/(const ModularInteger a) const noexcept { return ModularInteger(power(a, mod - 2) * val); }
    inline ModularInteger operator%(const ModularInteger a) const noexcept { return ModularInteger(val % a.val); }
    inline ModularInteger operator>>(const ModularInteger a) const noexcept { return ModularInteger(val >> a.val); }
    inline ModularInteger operator<<(const ModularInteger a) const noexcept { return ModularInteger(val << a.val); }
    template <typename T>
    inline ModularInteger operator+(T a) const noexcept { return val + ModularInteger(a); }
    template <typename T>
    inline ModularInteger operator-(T a) const noexcept { return val - ModularInteger(a); }
    template <typename T>
    inline ModularInteger operator*(T a) const noexcept { return val * ModularInteger(a); }
    template <typename T>
    inline ModularInteger operator/(T a) const noexcept { return val / ModularInteger(a); }
    template <typename T>
    inline ModularInteger operator%(T a) const noexcept { return val % ModularInteger(a); }
    template <typename T>
    inline ModularInteger operator>>(T a) const noexcept { return val >> ModularInteger(a); }
    template <typename T>
    inline ModularInteger operator<<(T a) const noexcept { return val << ModularInteger(a); }

    template <typename T>
    inline void operator+=(T a) { this = *this + ModularInteger(a); }
    template <typename T>
    inline void operator-=(T a) { val = val - ModularInteger(a); }
    template <typename T>
    inline void operator*=(T a) { val = val * ModularInteger(a); }
    template <typename T>
    inline void operator/=(T a) { val = val / ModularInteger(a); }
    template <typename T>
    inline void operator%=(T a) { val = val % a; }
    template <typename T>
    inline void operator>>=(T a) { val = val >> ModularInteger(a); }
    template <typename T>
    inline void operator<<=(T a) { val = val << ModularInteger(a); }

    // logical operators
    template <typename T>
    inline bool operator<(T a) const noexcept { return (val < a); }
    template <typename T>
    inline bool operator>(T a) const noexcept { return (val > a); }
    template <typename T>
    inline bool operator<=(T a) { return (val <= a); }
    template <typename T>
    inline bool operator>=(T a) { return (val >= a); }
    inline bool operator!() { return !val; }
    friend istream &operator>>(istream &cc, ModularInteger &a)
    {
        ll __x;
        cc >> __x;
        a = __x;
        return cc;
    }
};

void func()
{
}
int main()
{
    // FAST;
    ll a = 1e18;
    ModularInteger b = a;
    b.
    print();
}
