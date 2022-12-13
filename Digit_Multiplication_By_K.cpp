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
V<vi> unit;
V<vi> mul(V<vi> &m1, V<vi> &m2)
{
    V<vi> ans(10, vi(10));
    range(i, 10)
    {
        range(j, 10)
        {
            ll sum = 0;
            range(k, 10)
            {
                sum = (sum + (m1[i][k] * m2[k][j]) % mod) % mod;
            }
            ans[i][j] = sum;
        }
    }
    return ans;
}

V<vi> power(V<vi> matrix, ll k)
{
    V<vi> res = unit;
    while (k)
    {
        if (k % 2 == 1)
            res = mul(res, matrix);

        k = k >> 1;
        matrix = mul(matrix, matrix);
    }
    return res;
}

void func()
{
    newint(n, m, k);
    newstring(str);
    if (m == 0)
    {
        give(str.size());
    }
    V<vi> matrix(10, vi(10));
    for (ll i = 0; i < 10; i++)
    {
        ll mul = i * m;
        while (mul)
        {
            matrix[mul % 10][i]++;
            matrix[mul % 10][i] %= mod;
            mul /= 10;
        }
    }
    matrix[0][0] = 1;
    V<vi> ans = power(matrix, k);
    // foreach (i, ans)
    //     print(i);
    ll sum = 0;
    foreach (i, str)
    {
        for (ll j = 0; j < 10; j++)
        {
            sum = rs(sum + ans[j][i - '0']);
        }
    }
    print(sum);
}
int main()
{
    // FAST;
    unit = V<vi>(10, vi(10));
    range(i, 10) unit[i][i] = 1;
    newint(t);
    range(t)
    {
        func();
    }
}
