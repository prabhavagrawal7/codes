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

ll func()
{
    // write your code here
    newstring(str);
    ll ans = 0;
    ll n = str.size();
    ll np = 0, p = 0;
    range(i, n - 1)
    {
        if (str[i] == 'N' && str[i + 1] == 'P')
        {
            np += 1;
            str[i] = 'X', str[i + 1] = 'X';
        }
    }
    range(i, n)
    {
        if (str[i] == 'P')
        {
            p += 1;
            str[i] = 'X';
        }
    }

    range(i, n - 1)
    {
        if (str[i] == 'N')
        {
            ll len = 0;
            ll j = i;
            for (j = i; j < n; j++)
            {
                if (str[j] != 'N')
                {
                    break;
                }
                else
                {
                    len++;
                }
            }
            i = j - 1;
            if (len % 2 == 0)
            {
                np += len / 2;
                ans += len / 2;
            }
            else
            {
                np += len / 2;
                p += 1;
                ans += len / 2 + 1;
            }
        }
    }

    if (np > p)
        ans += (np - p) / 3;
    else if (p > np)
        ans += (p - np) / 3;
    print(ans);
    return 0;
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
