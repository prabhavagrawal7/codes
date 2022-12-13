#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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
const ll mod = 998244353;
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
inline ll rs(ll n) { return (mod + n % mod) % mod; }
 
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x) % mod;
 
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
}
vi f(6000);
void facmaker()
{
    f[0] = 1;
    range(i, 1, f.size())
    {
        f[i] = (f[i - 1] * i) % mod;
    }
}
inline ll ncr(ll n, ll r)
{
    if (n == 0 || r > n || r <= -1)
        return 0;
    return rs(rs(f[n] * power(f[r], mod - 2)) * power(f[n - r], mod - 2));
}
void func()
{
    newint(n, k);
    newstring(str);
    if (k == 0)
    {
        give(1);
    }
    if (k == 1)
    {
        if(string(n, '0') == str){
            give(1); 
        }
        deque<char> str1(all(str));
        ll ans = 0;
        while (str1.size() != 0 && str1[0] == '0')
            ans += 1, str1.pop_front();
        while (str1.size() != 0 && *prev(str1.end()) == '0')
            ans += 1, str1.pop_back();
        ans += 2*count(str1.begin(), str1.end(), '0'); 
        give(ans+1);
    }
    if(count(all(str), '1') < k){
        give(1); 
    }
    ll l = 0, r = 0;
    ll extrar = 0, extrasum = 0;
    ll sum = 0;
    ll ans = 0;
    while (true)
    {
        if ((sum < k || (sum == k && !(str[r] - '0'))) && r != n)
        {
            sum += str[r] - '0';
            extrasum += str[r] - '0';
            extrar++;
            r++;
            continue;
        }
        if (r == n && sum != k)
            break;
        // successful condition
        ans = rs(ans + (ncr(r - l, k) - ncr(r - l - extrar, k - extrasum)));
        extrasum = 0, extrar = 0;
        while (sum == k)
        {
            sum -= str[l] - '0';
            l++;
        }
    }
    print(ans);
}
ll fac(ll k)
{
    ll ans = 1;
    range(i, 1, k + 1)
    {
        ans = (ans * k) % mod;
    }
    return ans;
}
 
int main()
{
    facmaker();
    // Uncomment for faster I/O
    // FAST;
    func();
    // bruty();
}