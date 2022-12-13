#include "bits/stdc++.h"
using namespace std;
#define ll int64_t

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
string narek = "narek";

void removeUnuseful(V<string> &vstr)
{
    foreach (str, vstr)
    {
        // remove all characters which are not in narek
        string newstr;
        foreach (ch, str)
        {
            if (narek.find(ch) != string::npos)
                newstr.push_back(ch);
        }
        str.swap(newstr);
    }
}

struct Values
{
    ll certain, uncertain, loss;
    ll lastchar;
};

ll dp[1001][5][5];
ll rec(ll n, V<V<Values>> &store, ll lastelement, ll unceratin)
{
    if (n == store.size())
        return -unceratin;
    if (dp[n][lastelement][unceratin] != -INT_INF)
        return dp[n][lastelement][unceratin];
    ll ans = rec(n + 1, store, lastelement, unceratin);
    auto &tonext = store[n][lastelement];
    ll newunceratin = (unceratin + tonext.uncertain);
    ll oans = tonext.certain + rec(n + 1, store, tonext.lastchar, newunceratin % 5) + 5 * (newunceratin / 5) - tonext.loss;
    return dp[n][lastelement][unceratin] = max(ans, oans);
}

void func()
{
    newint(n, m);
    V<string> vstr(n);
    range(i, n) cin >> vstr[i];
    removeUnuseful(vstr);

    ll ans = -INT_INF;
    V<V<Values>> store(n, V<Values>(narek.size()));

    range(i, vstr.size())
    {
        auto &word = vstr[i];
        for (int j = 0; j < narek.size(); j++)
        {
            int narekptr = (j + 1) % narek.size();
            foreach (letter, word)
            {
                if (letter == narek[narekptr])
                {
                    store[i][j].uncertain++;
                    narekptr = (narekptr + 1) % narek.size();
                }
                else
                {
                    store[i][j].loss++;
                }
            }
            store[i][j].certain = (store[i][j].uncertain / 5) * 5;
            store[i][j].uncertain %= 5;
            store[i][j].lastchar = (narekptr + 4) % 5;
        }
    }
    range(i, n)
    {
        range(j, 5)
        {
            range(k, 5)
            {
                dp[i][j][k] = -INT_INF;
            }
        }
    }
    ans = rec(0, store, 4, 0);

    print(ans);
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