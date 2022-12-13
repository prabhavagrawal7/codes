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
#define newstring(str) \
    string str;        \
    cin >> str;
#define foreach(a, x) for (auto &a : x)
const ll mod = 1000000007;
const ll mod2 = 998244353;
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

inline ll LCM(ll n, ll m)
{
    return n * m / gcd(n, m);
}
const ll range = 10000007;
V<int> prime(range + 1, 0);
void sieveOfEratosthenes()
{
    for (int p = 2; p * p <= range; p++)
    {
        if (prime[p] == false)
        {
            for (int i = p * p; i <= range; i += p)
                if (!prime[i])
                    prime[i] = i / p;
        }
    }
}
V<ll> lcmfromprime(V<pii> vec)
{
    ll lcm = INT_INF;
    ll l = 0, r = 0;
    V<int> index(range, -1);
    ll n = vec.size();
    range(i, n) index[(vec[i].first)] = vec[i].second;

    range(i, n)
    {
        ll val = vec[i].first;
        ll val1 = 1;
        while (prime[val] != 0)
        {
            if (index[val1] != -1 && lcm > vec[i].first && vec[i].second != index[val1])
            {
                lcm = vec[i].first;
                l = vec[i].second, r = index[val1];
            }
            val1 *= val / prime[val];
            val = prime[val];
        }   
    }
    return {lcm, l, r};
}
void func()
{
    newint(n);
    V<pii> vec(n);
    range(i, n)
    {
        vec[i] = {input(), i};
    }
    sort(all(vec));
    V<pii> dif;
    ll val = -1;
    ll lcm = LONG_LONG_MAX;
    ll l = 0, r = 0;
    range(i, n - 1)
    {
        if (vec[i].first == vec[i + 1].first)
        {
            lcm = vec[i].first;
            l = vec[i].second, r = vec[i + 1].second;
            break;
        }
    }
    range(i, n)
    {
        if (val != vec[i].first)
            val = vec[i].first, dif.push_back(vec[i]);
        else
            continue;
    }
    auto opt1 = lcmfromprime(dif);
    if (opt1[0] < lcm)
    {
        lcm = opt1[0], l = opt1[1], r = opt1[2];
    }

    n = dif.size();

    range(i, n)
    {
        if (dif[i].first >= lcm)
            break;
        range(j, i + 1, n)
        {
            if (dif[j].first >= lcm)
                break;
            ll nlcm = LCM(dif[i].first, dif[j].first);
            if (lcm > nlcm)
            {
                lcm = nlcm;
                l = dif[i].second, r = dif[j].second;
            }
        }
    }
    if (l > r)
        swap(l, r);
    print(l + 1, 1 + r);
}
int main()
{
    // Uncomment for faster I/O
    sieveOfEratosthenes();
    FAST;
    {
        func();
    }
}
