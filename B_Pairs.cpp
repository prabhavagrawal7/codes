#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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
ll common(pii a, pii b)
{

    if (a.first == b.first)
        return a.first;
    else if (a.first == b.second)
        return a.first;
    else if (a.second == b.first)
        return a.second;
    else if (a.second == b.second)
        return a.second;
    return 0;
}
ll _func(V<pii> vec, ll cmn)
{
    ll a = vec[0].first == cmn ? vec[0].second : vec[0].first;
    ll b = vec[1].first == cmn ? vec[1].second : vec[1].first;
    pii u = {a, b};
    range(i, vec.size())
    {
        if (common(u, vec[i]))
            continue;
        else
            return 0;
    }
    return 1;
}
ll func()
{
    // write your code here
    newint(n, k);
    set<pii> svec;
    range(k)
    {
        newint(a, b);
        if (a > b)
            swap(a, b);
        svec.insert({a, b});
    }
    V<pii> vec(all(svec));
    k = vec.size();
    if (k == 1)
        return 1;
    ll cmn = common(vec[0], vec[1]);
    if (_func(vec, cmn))
        return 1;

    V<pii> extracted;
    range(i, k)
    {
        if (vec[i].first == cmn || vec[i].second == cmn)
            continue;
        else
        {
            extracted.push_back(vec[i]);
        }
    }
    if (extracted.size() < 2)
        return 1;
    ll cmn2 = common(extracted[0], extracted[1]);
    if (cmn2 == 0)
        return 0;
    range(i, extracted.size())
    {
        if (extracted[i].first == cmn2 || extracted[i].second == cmn2)
            continue;
        else
            return 0;
    }
    return 1;
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    if (func())
        print("YES");
    else
        print("NO");
}
