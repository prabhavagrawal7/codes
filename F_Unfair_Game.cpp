#include "bits/stdc++.h"
using namespace std;
#define ll int

// Uncomment them for optimisations
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)

// printing bullshits open
template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os
        << "[" << p.first << "," << p.second << "]";
    return os;
}
template <typename T, typename = void>
struct is_iterable : false_type
{
};
template <typename T>
struct is_iterable<T, void_t<decltype(begin(declval<T &>())), decltype(end(declval<T &>()))>> : true_type
{
};
template <typename T>
using is_string = is_same<decay_t<T>, string>;
template <typename T>
constexpr bool is_iterable_v = is_iterable<T>::value;
template <typename T>
typename enable_if<!is_iterable_v<T>, void>::type
__print(T &&container) { cout << container; }
template <typename T>
typename enable_if<is_iterable_v<T> && !is_string<T>::value, void>::type __print(T &&container)
{
    for (auto
             itr = container.begin();
         itr != container.end(); itr++)
    {
        __print(*itr);
        if (next(itr) != container.end())
            cout << ' ';
    }
}
template <typename T>
typename enable_if<is_string<T>::value, void>::type
__print(T &&string_container) { cout << string_container; }
template <typename T>
typename enable_if<is_same<T, const char *>::value, void>::type __print(T &&string_container) { cout << string_container; }
template <size_t N>
void __print(const char (&str)[N]) { cout << str; }
template <typename... T>
inline void print(T &&...args)
{
    ((__print(args), cout << " "), ...);
    cout << endl;
}
template <typename... T>
inline void printl(T &&...args) { ((__print(args), cout
                                                       << " "),
                                   ...); }
// printing bullshits close

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
    do                      \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    } while (false)
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
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
const ll mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n %= mod) >= 0 ? n : n + mod; }
// define rll above this
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
/* ----------------------------------------------------------------------------------------------*/
vi getDivisors(int n)
{
    vi divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    sort(all(divisors)); 
    return divisors;
}
// join two sorted vectors and return sorted vector with unique elements
vi join(vi &v1, vi &v2)
{
    vi ans;
    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            if (ans.empty() || ans.back() != v1[i])
                ans.push_back(v1[i]);
            i++;
        }
        else if (v2[j] < v1[i])
        {
            if (ans.empty() || ans.back() != v2[j])
                ans.push_back(v2[j]);
            j++;
        }
        else
        {
            if (ans.empty() || ans.back() != v1[i])
                ans.push_back(v1[i]);
            i++;
            j++;
        }
    }

    while (i < v1.size())
    {
        if (ans.empty() || ans.back() != v1[i])
            ans.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        if (ans.empty() || ans.back() != v2[j])
            ans.push_back(v2[j]);
        j++;
    }

    return ans;
}

vi prune(vi &v, ll val)
{
    vi ans;
    foreach (a, v)
    {
        if (val % a == 0)
            ans.push_back(a);
    }
    return ans;
}
vi combine(vi &v1, vi &v2, ll val)
{
    vi ans1, ans2;
    ans1 = prune(v1, val);
    ans2 = prune(v2, val);
    return join(ans1, ans2);
}
void func()
{
    newint(n, m);
    vvi vec(n, vi(m));
    cin >> vec;

    V<vvi> dp(n, vvi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i - 1 >= 0 && j - 1 >= 0)
                dp[i][j] = combine(dp[i][j - 1], dp[i - 1][j], vec[i][j]);
            else if (i - 1 >= 0)
                dp[i][j] = prune(dp[i - 1][j], vec[i][j]);
            else if (j - 1 >= 0)
                dp[i][j] = prune(dp[i][j - 1], vec[i][j]);
            else
                dp[i][j] = getDivisors(vec[i][j]);
        }
        if (i - 2 >= 0)
            vvi().swap(dp[i - 2]);
    }
    cout << *max_element(all(dp[n - 1][m - 1])) << endl;
}
int main()
{
    FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
