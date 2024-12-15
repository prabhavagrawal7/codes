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
// #define mid (start+end)/2x
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
inline ll rs(ll n) { return (n % mod + mod) % mod; }
ll power(ll x, ll y)
{
    x %= mod;
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

void func()
{
    newint(n, m);
    vi vec = inputvec(n);
    mii freq;
    foreach (i, vec)
        freq[i]++;
    ll prev = -1;
    while (freq.size())
    {
        auto x = freq.begin();
        if (prev == x->first)
            break;
        prev = x->first;
        if (x->first % m == 0)
        {
            give("Yes");
        }
        freq[x->first + 1] += x->second / (x->first + 1);
        x->second %= (x->first + 1);
        if(x->second == 0) {
            freq.erase(x); 
        }
    }
    give("No");
}
int main()
{
    // Uncomment for faster I/O
    // FAST;

    func();
}



// #include "bits/stdc++.h"
// using namespace std;
// #define ll __int128_t

// // ordered set
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// // using namespace __gnu_pbds;
// // #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// // Uncomment them for optimisations
// //#pragma GCC optimize("Ofast")
// //#pragma GCC target("avx,avx2,fma")

// // for segment tree
// // #define mid (start+end)/2
// // #define lnode (node*2+1)
// // #define rnode (node*2+2)
// #define popcount(x) __builtin_popcount(x)
// #define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
// #define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
// #define r4(var, start, stop, step) for (ll var = start; step >= 0 ? var < stop : var > stop; var = var + step)
// #define r3(var, start, stop) for (ll var = start; var < stop; var++)
// #define r2(var, stop) for (ll var = 0; var < stop; var++)
// #define r1(stop) for (ll start_from_0 = 0; start_from_0 < stop; start_from_0++)
// #define newint(...) \
//     ll __VA_ARGS__; \
//     take_input(__VA_ARGS__)
// #define min(...) min({__VA_ARGS__})
// #define max(...) max({__VA_ARGS__})
// #define give(...)           \
//     {                       \
//         print(__VA_ARGS__); \
//         return;             \
//     }
// #define endl "\n"
// #define FULL_INF numeric_limits<double>::infinity()
// #define INF INT64_MAX
// #define INT_INF INT32_MAX
// #define ld long double
// #define V vector
// #define P pair
// #define S set
// #define MS multiset
// #define M map
// #define UM unordered_map
// #define US unordered_set
// #define MM multimap
// #define mt make_tuple
// #define mp make_pair
// #define pb push_back
// #define pf push_front
// #define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define all(a) a.begin(), a.end()
// #define db(x) cout << #x << " = " << x << "\n"
// string db_bin(ll n)
// {
//     string ans;
//     while (n)
//     {
//         ans.push_back((n & 1) + '0');
//         n >>= 1;
//     }
//     reverse(all(ans));
//     return ans;
// }
// #define newstring(str) \
//     string str;        \
//     cin >> str;
// #define foreach(a, x) for (auto &&a : x)
// const ld pi = acos(-1);
// typedef vector<string> vs;
// typedef pair<ll, ll> pii;
// typedef vector<ll> vi;
// typedef map<ll, ll> mii;
// typedef set<ll> si;
// typedef vector<vector<ll>> vvi;
// template <typename... T>
// inline void take_input(T &&...args) { ((cin >> args), ...); }
// template <typename T>
// inline bool btn(T a, T b, T c)
// {
//     if ((a <= b && b <= c) || (a >= b && b >= c))
//         return true;
//     return false;
// }
// template <typename T>
// ostream &operator<<(ostream &os, const V<T> &v)
// {
//     for (int i = 0; i < v.size(); ++i)
//     {
//         os << v[i];
//         if (i != v.size() - 1)
//             os << " ";
//     }
//     return os;
// }
// template <typename _A, typename _B>
// ostream &operator<<(ostream &os, const pair<_A, _B> &p)
// {
//     os << "[" << p.first << ", " << p.second << "]";
//     return os;
// }
// template <typename... T>
// inline void print(T &&...args)
// {
//     ((cout << args << " "), ...);
//     cout << endl;
// }
// template <typename... T>
// inline void printl(T &&...args) { ((cout << args << " "), ...); }
// inline ld TLD(ll n) { return n; }
// ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
// const int64_t mod1 = 1000000007;
// const ll mod2 = 1000000009;
// const ll mod3 = 100000000069;
// ll power(ll x, ll y, ll mod)
// {
//     x %= mod;
//     ll res = 1;
//     while (y)
//     {
//         if (y & 1LL)
//             res = (res * x) % mod;
//         y >>= 1;
//         x = (x * x) % mod;
//     }
//     return res % mod;
// }

// /* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
// ll inv(ll n, ll mod)
// {
//     return power(n, mod - 2, mod);
// }
// static vi mul1 = {1};
// static vi mul2 = {1};
// static vi mul3 = {1};

// void func()
// {
//     int n, k; cin >> n >> k; 
//     vi vec;
//     range(i, n)
//     {
//         int x;
//         cin >> x;
//         vec.push_back((ll)x);
//     }
//     ll sum1 = 0, sum2 = 0, sum3 = 0;
//     range(i, n)
//     {
//         sum1 += mul1[vec[i]];
//         sum1 %= mod1;
//         sum2 += mul2[vec[i]];
//         sum2 %= mod2;
//         sum3 += mul3[vec[i]];
//         sum3 %= mod3;
//     }
//     ll div1 = (sum1 * inv(mul1[k], mod1)) % mod1; 
//     ll div2 = (sum2 * inv(mul2[k], mod2)) % mod2; 
//     ll div3 = (sum3 * inv(mul3[k], mod3)) % mod3; 
//     if (div1 == div2 && div2 == div3)
//     {
//         give("Yes");
//     }
//     give("No");
// }
// int main()
// {
//     // Uncomment for faster I/O
//     // FAST;
//     range(i, 5e5 + 2)
//     {
//         mul1.push_back((mul1.back() * mul1.size()) % mod1);
//         mul2.push_back((mul2.back() * mul2.size()) % mod2);
//         mul3.push_back((mul3.back() * mul3.size()) % mod3);
//     }
//     func();
// }
