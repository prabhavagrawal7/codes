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
const ll mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n = n % mod) >= 0 ? n : n + mod; }
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

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
const ll range = 31623;
vi primevec(range + 1, 1);
vi primes;
void sieve()
{
    for (int p = 2; p * p <= range; ++p)
    {
        if (primevec[p] == 1)
        {
            for (int i = p * p; i <= range; i += p)
                if (primevec[i] == 1)
                    primevec[i] = p;
        }
    }
    for (int i = 2; i < range; i++)
    {
        if (primevec[i] == 1)
            primes.pb(i);
    }
}

vector<pair<int, int>> merge_factors(ll m1, ll m2)
{
    map<ll, ll> primestore;
    foreach (i, primes)
    {
        while (m1 % i == 0)
        {
            ++primestore[i];
            m1 /= i;
        }
        while (m2 % i == 0)
        {
            ++primestore[i];
            m2 /= i;
        }
    }
    if (m1 != 1)
        primestore[m1]++;
    if (m2 != 1)
        primestore[m2]++;
    return vector<pair<int, int>>(all(primestore));
}

void func()
{
    newint(n, m1, m2);
    auto fac = merge_factors(m1, m2);
    vi bit(fac.size());

    UM<ll, ll> ans;
    US<ll> vis; 
    queue<pair<ll, vi>> bfs;
    bfs.push({1, vi(fac.size())});
    ans[1] = 1;

    while (bfs.size())
    {
        auto x = bfs.front().second;
        auto y = bfs.front().first;
        bfs.pop();
        for (int i = 0; i < x.size(); i++)
        {
            if (fac[i].second == x[i] || !ans.count(y))
                continue;
            ll ny = y * fac[i].first;
            ll prevans = ans[y];
            ll potentialans = INT_INF;
            if (ny / prevans <= n)
                potentialans = min(potentialans, prevans);
            if (prevans * fac[i].first <= n)
                potentialans = min(potentialans, prevans * fac[i].first);
            if (potentialans != INT_INF)
                ans[ny] = (ans[ny] == 0) ? potentialans : min(potentialans, ans[ny]);
            if (vis.count(ny) == 0)
            {
                vis.insert(ny); 
                x[i]++;
                bfs.push({ny, x});
                x[i]--;
            }
        }
    }
    ll rep = 0;
    foreach (i, ans)
    {
        rep ^= i.second;
    }
    print(ans.size(), rep);
}
int main()
{
    sieve();
    FAST;
    newint(t);
    range(t)
    {
        func();
    }
}