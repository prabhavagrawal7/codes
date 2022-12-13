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
class rll
{
private:
    int64_t val = 0;

public:
    rll power(rll y)
    {
        rll x = *this;
        rll res = 1;
        while (y)
        {
            if (y % 2 == 1)
                res = (res * x);
            y = y >> 1;
            x = (x * x);
        }
        return res;
    }
    operator int64_t() const { return this->val; }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    rll(T val) { this->val = val; }
    rll() {}
    // arithmetic operators
    inline rll operator+(rll a)
    {
        a.val = (this->val + a.val) % mod;
        return a;
    }
    inline rll operator-(rll a)
    {
        a.val = ((this->val - a.val) % mod + mod) % mod;
        return a;
    }
    inline rll operator*(rll a)
    {
        a.val = (a.val * this->val) % mod;
        return a;
    }
    inline rll operator/(rll a) { return a.power(mod - 2) * (*this); }
    inline rll operator%(rll a)
    {
        a.val = (this->val % a.val) % mod;
        return a;
    }
    inline rll operator>>(rll a)
    {
        a.val = (this->val >> a.val) % mod;
        return a;
    }
    inline rll operator<<(rll a)
    {
        a.val = (this->val << a.val) % mod;
        return a;
    }

    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator+(T a) { return *this + rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator-(T a) { return *this - rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator*(T a) { return *this * rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator/(T a) { return *this / rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator%(T a) { return *this % rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator>>(T a) { return *this >> rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator<<(T a) { return *this << rll(a); }

    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator+=(T a) { return *this = *this + rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator-=(T a) { return *this = *this - rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator*=(T a) { return *this = *this * rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator/=(T a) { return *this = *this / rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator>>=(T a) { return *this = *this >> rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator<<=(T a) { return *this = *this << rll(a); }

    // logical operators
    inline bool operator<(rll a) { return (this->val < a.val); }
    inline bool operator>(rll a) { return (this->val > a.val); }
    inline bool operator<=(rll a) { return (this->val <= a.val); }
    inline bool operator>=(rll a) { return (this->val >= a.val); }
    inline bool operator!() { return !this->val; }

    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline bool operator<(T a) { return (this->val < a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline bool operator>(T a) { return (this->val > a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline bool operator<=(T a) { return (this->val <= a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline bool operator>=(T a) { return (this->val >= a); }
    friend istream &operator>>(istream &cc, rll &a)
    {
        cc >> a.val;
        return cc;
    }
};
rll power(rll x, rll y)
{
    rll res = 1;
    while (y)
    {
        if (y & 1LL)
            res = (res * x);
        y = y / 2;
        x = (x * x);
    }
    return res;
}
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

ll func(ll n, ll m)
{
    if (n % 2 == m % 2) return 1; 
    else return 0; 
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    range(t)
    {
        newint(a, b); 
        if(func(a, b)) cout << "Tonya" << endl ;
        else print("Burenka"); 
    }
}
