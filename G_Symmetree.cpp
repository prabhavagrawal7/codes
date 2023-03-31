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

// printing bullshits open
template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os << "[" << p.first << "," << p.second << "]";
    return os;
}
template <typename T, typename = void>
struct is_iterable : false_type
{
};
template <typename T>
struct is_iterable<T, void_t<decltype(begin(declval<T &>())),
                             decltype(end(declval<T &>()))>> : true_type
{
};
template <typename T>
using is_string = is_same<decay_t<T>,
                          string>;
template <typename T>
constexpr bool is_iterable_v = is_iterable<T>::value;
template <typename T>
typename enable_if<!is_iterable_v<T>, void>::type __print(T &&container) { cout << container; }
template <typename T>
typename enable_if<is_iterable_v<T> && !is_string<T>::value, void>::type __print(T &&
                                                                                     container)
{
    auto itr = container.begin();
    __print(*itr), itr++;
    for (; itr != container.end(); ++itr)
    {
        cout << ' ';
        __print(*itr);
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
inline void printl(T &&...args) { ((__print(args), cout << " "), ...); }
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
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

ll dfs(ll n, V<V<pii>> &g)
{
    ll ans = 1;
    foreach (i, g[n])
    {
        ll tmpans = (power(2, dfs(i.first, g)));
        tmpans = inv(power(tmpans, tmpans*tmpans)); 
        i.second = tmpans;
        ans += tmpans << 1;
        ans %= mod;
    }
    sort(all(g[n]), [](pii &a, pii &b)
         { return a.second < b.second; });
    return ans;
}
ll checker(ll a, ll b, V<V<pii>> &g)
{
    vi hash1, hash2;
    foreach (i, g[a])
        hash1.push_back(i.second);
    foreach (i, g[b])
        hash2.push_back(i.second);
    if (hash1.size() != hash2.size())
        return false;
    if (hash1 != hash2)
        return false;
    range(i, g[a].size())
    {
        if (!checker(g[a][i].first, g[b][i].first, g))
            return false;
    }
    return true;
}
void _dfs(ll n, ll par, vi &parent, vvi &graph)
{
    parent[n] = par;
    foreach (i, graph[n])
        if (i != par)
            _dfs(i, n, parent, graph);
}
V<V<pii>> graph(ll n)
{
    vvi g(n + 1);
    range(i, n - 1)
    {
        newint(a, b);
        g[a].pb(b);
        g[b].pb(a);
    }
    vi parent(n + 1);
    _dfs(1, 0, parent, g);
    V<V<pii>> ans(n + 1);
    range(i, 1, n + 1)
    {
        ans[parent[i]].push_back({i, 1});
    }
    return ans;
}
void func()
{
    newint(n);
    auto g = graph(n);
    vi vpar(n + 1);
    dfs(1, g);
    ll u = 1, again = 1;
    while(again)
    {
        u = again; 
        again = 0; 
        map<ll, vi> freq;
        foreach (i, g[u])
            freq[i.second].pb(i.first);
        foreach (i, freq)
        {
            auto &x = i.second;
            range(j, 0, x.size() - 1, 2)
            {
                if (!checker(x[j], x[j + 1], g))
                    give("NO");
            }
            if (x.size() % 2 != 0)
            {
                if (again)
                    give("NO");
                else
                    again = x.back();
            }
        }
    }
    give("YES");
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
