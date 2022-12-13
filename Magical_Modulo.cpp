#include <bits/stdc++.h>
// Uncomment them for optimisations
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

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
    newint(n);
    vi vec(n + 1);
    range(i, 1, n + 1)
    {
        cin >> vec[i];
    }
    sort(vec.begin() + 1, vec.end());
    vi nvec(n + 1);
    if (si(vec.begin() + 1, vec.end()).size() != n)
    {
        give("NO");
    }

    range(i, vec.size())
    {
        if (vec[i] <= n)
        {
            nvec[vec[i]] = 1;
        }
    }
    ll con = -1;
    range(i, n, 0, -1)
    {
        if (nvec[i] == 0)
        {
            con = i;
            break;
        }
    }
    if (con == -1)
    {
        give("YES", n + 1);
    }

    nvec[0] = 1;
    vi mvec = nvec;
    ll id = lower_bound(vec.begin() + 1, vec.end(), n + 1) - vec.begin();
    vi conten(vec[id] - (n + 1) + 1);

    range(i, id, n + 1)
    {
        for (ll j = 1; j * j <= vec[i] - con; j++)
        {
            if ((vec[i] - con) % j == 0)
            {
                if (btn(n + 1, j, vec[id]))
                    conten[j - (n + 1)] = 1;
                if (btn(n + 1, (vec[i] - con) / j, vec[id]))
                    conten[(vec[i] - con) / j - (n + 1)] = 1;
            }
        }
    }

    range(i, n + 1, vec[id])
    {
        if (!conten[i - (n + 1)])
            continue;
        bool flag = true;
        range(j, id, n + 1)
        {
            if (vec[j] % i >= mvec.size())
            {
                flag = false;
                break;
            }
            mvec[vec[j] % i]++;
            if (mvec[vec[j] % i] != 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            print("YES", i);
            return;
        }
        range(i, 1, nvec.size())
        {
            mvec[i] = nvec[i];
        }
    }
    print("NO");
}
int main()
{
    // Uncomment for faster I/O
    FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
