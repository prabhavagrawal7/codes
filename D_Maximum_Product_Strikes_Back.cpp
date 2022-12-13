#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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
#define INF INT64_MAX
#define INT_INF INT32_MAX
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
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os << "[" << p.first << ", " << p.second << "]";
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
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
inline ll rs(ll n) { return n % mod >= 0 ? n % mod : (n % mod) + mod; }

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
void func()
{
    newint(n);
    vi vec = inputvec(n + 1, 1);
    V<pair<ll, deque<ll>>> pvec;
    ll ans = 0, lrem = n, rrem = 0;
    range(i, vec.size())
    {
        if (vec[i] == 0)
        {
            pvec.push_back({i + 1, deque<ll>(0)});
        }
        else
        {
            auto x = prev(pvec.end());
            x->second.push_back(vec[i]);
        }
    }
    // handle -1 vale cases rn
    foreach (pld, pvec)
    {
        if (pld.second.size() == 0)
            continue;
        ll negative = 0;
        ll mulc = 0;
        range(i, pld.second.size())
        {
            if (pld.second[i] < 0)
                negative++;
            if (abs(pld.second[i]) == 2)
                mulc++;
        }
        if (negative % 2 == 0)
        {
            // pura multiply kar do
            // good case
            if (ans < mulc)
            {
                ans = mulc;
                lrem = pld.first - 1;
                rrem = n - lrem - pld.second.size();
            }
        }
        else
        {
            // first negative from left
            ll fleft = 0;
            range(i, pld.second.size())
            {
                if (pld.second[i] < 0)
                {
                    fleft = i;
                    break;
                }
            }
            // first negative from right
            ll fright = pld.second.size() - 1;
            range(i, pld.second.size() - 1, -1, -1)
            {
                if (pld.second[i] < 0)
                {
                    fright = i;
                    break;
                }
            }
            ll u = 0, v = 0;
            range(i, fleft + 1, pld.second.size())
            {
                if (abs(pld.second[i]) == 2)
                    u++;
            }
            range(i, 0, fright)
            {
                if (abs(pld.second[i]) == 2)
                    v++;
            }
            if (v > ans)
            {
                ans = v;
                lrem = pld.first - 1;
                rrem = n - (pld.first + fright) + 1;
            }
            if (u > ans)
            {
                ans = u;
                lrem = pld.first + fleft;
                rrem = n - (pld.first + pld.second.size()-1); 
            }
        }
    }
    print(lrem, rrem);
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
