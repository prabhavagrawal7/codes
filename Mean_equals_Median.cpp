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

inline ll m(ll n)
{
    if (n % 2 == 0)
        return (n / 2) - 1;
    else
        return ((n + 1) / 2) - 1;
}
ll myceil(ll n, ll m) { return n % m == 0 ? n / m : n / m + 1; }

void func()
{
    newint(n);
    vi vec = inputvec(n);
    sort(all(vec));
    ll tot = 0;
    range(i, n) { tot += vec[i]; }
    ll median = vec[m(n)];
    if (median * n >= tot)
    {
        ll totreq = median * n - tot;
        print(totreq);
    }
    else
    {
        if (n == 2)
        {
            give(vec[1] - vec[0]);
        }
        ll ans = INT_INF;
        UM<ll, ll> prefix;
        prefix[-1] = 0;
        bool flag = false;
        range(i, n)
        {
            prefix[i] = prefix[i - 1] + vec[i];
        }
        for (ll i = m(n); i < n - 1 && !flag; i++)
        {
            ll diff = i - m(n) + 1;
            ll sidelines = prefix[n - 1] - (prefix[i] - prefix[m(n) - 1]);
            ll totnow = sidelines + prefix[i] - prefix[m(n) - 1];
            ll tothighest = sidelines + vec[i + 1] * diff;
            if (!(tothighest <= vec[i + 1] * n))
                /* this is not the moment so*/ continue;
            else
            {
                ll req = myceil(sidelines, (n - diff));
                if (req < vec[i] || req > vec[i + 1])
                    continue;
                ll salt = sidelines % (n - diff);
                if (salt == 0)
                    salt = 0;
                else
                    salt = (n - diff) - salt;
                ll totreq = req * diff - (prefix[i] - prefix[m(n) - 1]) + salt;
                ans = totreq;
                flag = true;
            }
        }
        if (flag)
        {
            give(ans);
        }
        if (!flag)
        {
            vi vec1; foreach(i, vec) vec1.push_back(i); vec1.push_back(INT_INF); 
            ll i = n - 1;
            ll diff = i - m(n) + 1;
            ll sidelines = prefix[n - 1] - (prefix[i] - prefix[m(n) - 1]);
            ll totnow = sidelines + prefix[i] - prefix[m(n) - 1];
            ll tothighest = sidelines + vec[i + 1] * diff;
            ll req = myceil(sidelines, (n - diff));
            ll salt = sidelines % (n - diff);
            if (salt == 0)
                salt = 0;
            else
                salt = (n - diff) - salt;
            ll totreq = req * diff - (prefix[i] - prefix[m(n) - 1]) + salt;
            ans = totreq;
            flag = true;
            print(ans); 
        }
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
