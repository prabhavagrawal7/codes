#include <bits/stdc++.h>
// Uncomment them for optimisations
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
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
#define ll int
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
//const ll mod = 998244353;
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
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
template <typename... T>
void take_input(T &&...args) { ((cin >> args), ...); }
ll input()
{
    newint(n);
    return n;
}
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    for (ll i = start; i < n; i++)
    {
        vec[i] = input();
    }
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
V<V<pii>> dp;
pii func(string str1, string str2, ll s1, ll s2)
{
    if (dp[s1][s2].first != INT_INF && dp[s1][s2].second != INT_INF)
        return dp[s1][s2];
    if (s1 == str1.size() && s2 == str2.size())
        return dp[s1][s2] = {0, 0};
    if (s1 == str1.size())
    {
        if (str2[s2] == '1')
        {
            pii ans = func(str1, str2, s1, s2 + 1);
            return dp[s1][s2] = {ans.first + ans.second, ans.second};
        }
        else
        {
            pii ans = func(str1, str2, s1, s2 + 1);
            ans.second++;
            return dp[s1][s2] = ans;
        }
    }
    if (s2 == str2.size())
    {
        if (str1[s1] == '1')
        {
            pii ans = func(str1, str2, s1 + 1, s2);
            return dp[s1][s2] = {ans.first + ans.second, ans.second};
        }
        else
        {
            pii ans = func(str1, str2, s1 + 1, s2);
            ans.second++;
            return dp[s1][s2] = ans;
        }
    }

    pii ans1, ans2;
    if (str1[s1] == '1')
    {
        ans1 = func(str1, str2, s1 + 1, s2);
        ans1.first += ans1.second;
    }
    else
    {
        ans1 = func(str1, str2, s1 + 1, s2);
        ans1.second++;
    }

    if (str2[s2] == '1')
    {
        ans2 = func(str1, str2, s1, s2 + 1);
        ans2.first += ans2.second;
    }
    else
    {
        ans2 = func(str1, str2, s1, s2 + 1);
        ans2.second++;
    }
    return dp[s1][s2] = min(ans1, ans2);
}
int main()
{
    // Uncomment for faster I/O
    FAST;
    newint(t);
    range(t)
    {
        newint(n);
        newstring(str);
        newstring(str1);
        dp = V<V<pii>>(1001, V<pii>(1001, {INT_INF, INT_INF}));
        range(i, 1001)
        {
            range(j, 1001)
            {
                dp[i][j].first = INT_INF, dp[i][j].second = INT_INF;
            }
        }
        pii ans = func(str, str1, 0, 0);
        print(ans.first);
    }
}
