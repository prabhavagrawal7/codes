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
void query(ll a, ll b, ll c)
{
    cout << "? " << a << " " << b << " " << c << endl;
}
void give(ll a, ll b)
{
    cout << "! " << a << " " << b << endl;
}
void func()
{
    newint(n);
    ll a = 1, b = 2, c = 3;
    vi changes = {1, 2, 3};
    query(a, b, c);
    newint(sum);
    ll last = -1, last1 = -1;
    range(i, 4, n + 1)
    {
        query(a, b, i);
        newint(tempsum);
        if (tempsum > sum)
        {
            changes.push_back(i);
            last = c;
            c = i;
            sum = tempsum;
        }
    }
    range(i, 1, n + 1)
    {
        if (i == a || i == b || i == c)
            continue;
        query(a, i, c);
        newint(tempsum);
        if (tempsum > sum)
        {
            changes.push_back(i);
            last1 = b;
            b = i;
            sum = tempsum;
        }
    }
    vi contenders;
    range(i, 1, n + 1)
    {
        if (i == a || i == b || i == c)
            continue;
        query(i, b, c);
        newint(x1);
        if (x1 < sum)
            contenders.push_back(a);
        query(a, i, c);
        newint(x2);
        if (x2 < sum)
            contenders.push_back(b);
        break;
    }
    if (contenders.size() == 2)
    {
        give(contenders[0], contenders[1]);
    }
    else
    {
        contenders.push_back(c);
        if (contenders.size() == 1)
            contenders.push_back(b);
        give(contenders[0], contenders[1]);
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
