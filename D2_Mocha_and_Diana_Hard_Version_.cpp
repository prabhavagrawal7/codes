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
#define max(...) max({__VA_ARGS__})
#define min(...) min({__VA_ARGS__})
#define foreach(a, x) for (auto &a : x)
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
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define newstring(s) \
    string s;        \
    cin >> s;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ld pi = acos(-1);
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
        cin >> vec[i];
    }
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
inline ll gcd(ll m, ll n) { return __gcd(m, n); }
inline ld TLD(ll n) { return n; }
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
ll gp(ll n, vi &p)
{
    if (n == p[n])
    {
        return n;
    }
    else
        return p[n] = gp(p[n], p);
}
vi p1, p2;

ll func()
{
    // write your code here
    newint(n, q1, q2);
    p1 = vi(n + 1), p2 = vi(n + 1);
    range(i, p1.size()) p1[i] = i;
    range(i, p2.size()) p2[i] = i;
    V<pii> ansvec;
    range(i, q1)
    {
        newint(a, b);
        if (a < b)
            swap(a, b);
        a = gp(a, p1);
        b = gp(b, p1);
        p1[a] = b;
    }
    range(i, q2)
    {
        newint(a, b);
        if (a < b)
            swap(a, b);
        a = gp(a, p2);
        b = gp(b, p2);
        p2[a] = b;
    }
    vi visited(n + 1, 0);
    set<ll> parents1, parents2;
    range(i, 1, n)
    {
        parents1.insert(gp(i, p1));
        parents2.insert(gp(i, p2));
    }
    while (true)
    {
        bool flag = false;
    }
    print(ansvec.size());
    foreach (i, ansvec)
        print(i.first, i.second);
    return 0;
}
int main()
{
    // Uncomment for faster I/O
    FAST;
    func();
}
