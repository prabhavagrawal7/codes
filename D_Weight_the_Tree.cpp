#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define os_at(k) find_by_order(k)
#define os_lb(k) order_of_key(k) // lower_bound key
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#define popcount(x) __builtin_popcount(x)
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...)                         \
    GET_MACRO(__VA_ARGS__, r4, r3, r2, r1) \
    (__VA_ARGS__)
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
#define INF LONG_LONG_MAX
#define INT_INF INT_MAX
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
const ll mod = 1000000007;
// const ll mod = 998244353;
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
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
#define foreach(a, x) for (auto &a : x)
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef map<ll, ll> mii;
typedef set<ll> si;
typedef vector<vector<ll>> vvi;
template <typename... T>
void take_input(T &&...args) { ((cin >> args), ...); }
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    range(i, start, n) cin >> vec[i];
    return vec;
}
template <typename T>
bool btn(T a, T b, T c)
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
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
inline ll gcd(ll m, ll n) { return __gcd(m, n); }
inline ll rs(ll n) { return n % mod; }

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

vvi g;
V<V<pii>> dp;
pii dfs(ll n, bool taken, ll parent)
{
    if (dp[n][taken].first != -1)
        return dp[n][taken];
    pii ans = {taken, taken ? g[n].size() : 1};
    foreach (i, g[n])
    {
        if (parent == i)
            continue;
        if (taken)
        {
            auto uans = dfs(i, false, n);
            ans.first += uans.first, ans.second += uans.second;
        }
        else
        {
            auto uans1 = dfs(i, false, n);
            auto uans2 = dfs(i, true, n);
            if (uans1.first > uans2.first)
            {
                ans.first += uans1.first, ans.second += uans1.second;
            }
            else if (uans1.first < uans2.first)
            {
                ans.first += uans2.first, ans.second += uans2.second;
            }
            else
            {
                ans.first += uans1.first, ans.second += (uans1.second < uans2.second ? uans1.second : uans2.second);
            }
        }
    }
    return dp[n][taken] = ans;
}
si good;
void ndfs(ll n, bool taken, ll parent)
{
    if (taken)
        good.insert(n);
    foreach (i, g[n])
    {
        if (parent == i)
            continue;
        if (taken)
            ndfs(i, false, n);
        else
        {
            if (dp[i][true].first > dp[i][false].first)
                ndfs(i, true, n);
            else if (dp[i][true].first < dp[i][false].first)
                ndfs(i, false, n);
            else if (dp[i][true].second < dp[i][false].second)
                ndfs(i, true, n);
            else
                ndfs(i, false, n);
        }
    }
}
void func()
{
    newint(n);
    g = vvi(n + 1);
    dp = V<V<pii>>(n + 1, V<pii>(2, {-1LL, 0LL}));
    range(n - 1)
    {
        newint(a, b);
        g[a].push_back(b), g[b].push_back(a);
    }
    if (n == 2)
    {
        print("2 2");
        print("1 1");
        return;
    }
    (dfs(1, false, -1));
    (dfs(1, true, -1));
    if (dp[1][true].first > dp[1][false].first ||
        (dp[1][true].first == dp[1][false].first && dp[1][true].second < dp[1][false].second))
    {
        ndfs(1, true, -1);
    }
    else
        ndfs(1, false, -1);
    vi ans(n + 1, -1);
    range(i, 1, n + 1)
    {
        if (!good.count(i))
            ans[i] = 1;
    }

    range(i, 1, n + 1)
    {
        if (ans[i] == -1)
            ans[i] = g[i].size();
    }

    print(good.size(), accumulate(ans.begin() + 1, ans.end(), 0LL));
    range(i, 1, n + 1)
    {
        printl(ans[i]);
    }
    print();
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    {
        func();
    }
}