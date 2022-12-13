#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC optimization ("unroll-loops")
using namespace std;
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
#define ll long long
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

void func()
{
    newint(n, k);
    vi vec = inputvec(n);
    ll b = 0;
    map<ll, vi> ind;
    range(i, vec.size())
    {
        ind[vec[i]].push_back(i);
    }
    vi nvec(n + 1);
    range(i, 1, n + 1)
    {
        nvec[i] = ind[i].size() + nvec[i - 1];
    }
    ll L = 1, R = n;
    for (ll l = 1; l <= n; l++)
    {
        ll left = l, right = n, mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            ll u = nvec[n] - (nvec[mid] - nvec[l - 1]);
            ll v = nvec[n] - (nvec[mid - 1] - nvec[l - 1]);
            if ((u * 2 == n - k && v * 2 != n - k) || (u * 2 < n - k && v * 2 > n - k))
            {
                break;
            }
            else if (u * 2 <= n - k)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // ll tu = nvec[n] - (nvec[mid] - nvec[l - 1]);
        if (left <= right)
        {
            if (R - L > mid - l)
            {
                L = l, R = mid;
            }
        }
    }

    vi color(n, 1);
    range(i, L)
    {
        ll u = ind[i].size();
        foreach (j, ind[i])
            color[j] = -1;
    }
    range(i, n, R, -1)
    {
        ll u = ind[i].size();
        foreach (j, ind[i])
            color[j] = -1;
    }

    V<vi> limits;
    range(i, n)
    {
        if (color[i] == -1)
        {
            limits.push_back({i, i, -1});
            while (limits[limits.size() - 1][2] <= 0 && limits.size() > 1)
            {
                limits[limits.size() - 2][2] += limits[limits.size() - 1][2];
                limits[limits.size() - 2][1] = limits[limits.size() - 1][1];
                limits.pop_back();
            }
        }
        else
        {
            if (limits.size() && limits[limits.size() - 1][2] <= 0)
            {
                limits[limits.size() - 1][1] = i;
                limits[limits.size() - 1][2]++;
            }
            else
            {
                limits.push_back({i, i, 1});
            }
        }
    }
    print(L, R);
    while (limits.size() != k)
    {
        limits[limits.size() - 2][1] = limits[limits.size() - 1][1];
        limits.pop_back();
    }
    foreach (i, limits)
    {
        print(i[0] + 1, i[1] + 1);
    }
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
