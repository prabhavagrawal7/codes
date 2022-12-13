#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

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

#define popcount(x) __builtin_popcountll(x)
#define clz(x) (63 - __builtin_clzll(x))
#define ctz(x) __builtin_ctzll(x)
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

inline ll rs(ll n) { return (n %= mod) >= 0 ? n : n + mod; }

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
ll ans = 0;
int minDifference(vi &arr)
{
    ll n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int y = sum / 2 + 1;

    bool dp[y], dd[y];

    for (int i = 0; i < y; i++)
    {
        dp[i] = dd[i] = false;
    }

    dp[0] = true;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j + arr[i] < y; j++)
        {
            if (dp[j])
                dd[j + arr[i]] = true;
        }

        for (int j = 0; j < y; j++)
        {
            if (dd[j])
                dp[j] = true;
            dd[j] = false;
        }
    }

    for (int i = y - 1; i >= 0; i--)
    {
        if (dp[i])
            return (sum - 2 * i);
    }
    return 0; 
}
ll dfs(ll n, vvi &g, ll par, vi &subtree)
{
    vi heights;
    subtree[n] += 1;
    foreach (i, g[n])
    {
        if (i == par)
            continue;
        subtree[n] += dfs(i, g, n, subtree);
        heights.push_back(subtree[i]);
    }
    ll sum = accumulate(all(heights), 0LL); 
    ll diff = minDifference(heights);
    ll small = (sum - diff) / 2; 
    ll large = (small + diff); 
    ans += small * large; 
    return subtree[n];
}
void func()
{
    newint(n);
    vvi g(n + 1);
    range(i, 2, n + 1)
    {
        newint(x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
    vi subtree(n + 1);
    dfs(1, g, 0, subtree);
    print(ans);
}
int main()
{
    FAST;
    func();
}
