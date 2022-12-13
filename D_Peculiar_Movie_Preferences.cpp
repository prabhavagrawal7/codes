#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
#define cntpop(x) __builtin__popcount(x)
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
bool oneletter(V<string> &vec)
{
    foreach (i, vec)
    {
        if (i.size() == 1)
            return true;
    }
    return false;
}
bool twoletter(V<string> &vec)
{
    foreach (i, vec)
    {
        if (i.size() == 2 && i[0] == i[1])
            return true;
    }
    return false;
}
bool threeletter(V<string> &vec)
{
    foreach (i, vec)
    {
        if (i.size() == 3 && i[0] == i[2])
            return true;
    }
    return false;
}
bool fourletter(V<string> &vec)
{
    V<string> nvec;
    range(i, vec.size())
    {
        if (vec[i].size() == 2)
            nvec.push_back(vec[i]);
    }
    sort(all(nvec));
    foreach (i, nvec)
    {
        string u = i;
        reverse(all(u));
        if (binary_search(all(nvec), u))
        {
            return true;
        }
    }
    return false;
}
bool fiveletter(V<string> &vec)
{
    V<pair<string, ll>> nvec;
    range(i, vec.size())
    {
        nvec.push_back({vec[i], i});
    }
    sort(all(nvec));
    range(i, vec.size())
    {
        if (vec[i].size() != 3)
            continue;
        string s = vec[i];
        reverse(all(s));
        string s2 = s.substr(1);
        string s1 = s.substr(0, 2);
        auto u = lower_bound(all(nvec), mp(s1, 0LL));
        if (u != nvec.end() && u->first == s1 && u->second < i)
        {
            return true;
        }
        auto v = lower_bound(all(nvec), mp(s2, i));
        if (v != nvec.end() && v->first == s2 && v->second > i)
        {
            return true;
        }
    }
    return false;
}
bool sixletter(V<string> &vec)
{
    V<string> nvec;
    range(i, vec.size())
    {
        if (vec[i].size() == 3)
            nvec.push_back(vec[i]);
    }
    sort(all(nvec));
    foreach (i, nvec)
    {
        string u = i;
        reverse(all(u));
        if (binary_search(all(nvec), u))
        {
            return true;
        }
    }
    return false;
}

void func()
{
    newint(n);
    V<string> vec;
    range(i, n)
    {
        newstring(str);
        vec.push_back(str);
    }
    if (oneletter(vec) || twoletter(vec) || threeletter(vec) ||
        fourletter(vec) || fiveletter(vec) || sixletter(vec))
    {
        give("YES");
    }
    else
    {
        give("NO");
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
