#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)
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
string db_bin(ll n)
{
    string ans;
    while (n)
    {
        ans.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(all(ans));
    return ans;
}
#define newstring(str) \
    string str;        \
    cin >> str;
#define foreach(a, x) for (auto &&a : x)
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
inline ll rs(ll n) { return (n = n % mod) >= 0 ? n : n + mod; }
ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1LL)
            res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res % mod;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
bool checker(string &str, ll a, ll b, ll ab, ll ba)
{
    ll _a = count(all(str), 'A');
    ll _b = str.size() - _a;
    if (_a == a + ab + ba && _b == b + ab + ba)
        return true;
    else
        return false;
}

void func()
{
    newint(a, b, ab, ba);
    newstring(str);
    if (!checker(str, a, b, ab, ba))
    {
        give("NO");
    }
    if (str[0] == 'A')
        str = 'A' + str, a++;
    else if (str[0] == 'B')
        str = 'B' + str, b++;
    if (str[str.size() - 1] == 'A')
        str.push_back('A');
    else if (str[str.size() - 1] == 'B')
        str.push_back('B');
    map<string, vi> save;
    char rstart = str[0];
    ll item = 0;
    range(i, str.size() - 1)
    {
        if (str[i] == str[i + 1])
        {
            save[string(1, rstart) + string(1, str[i])].pb(item + 1);
            item = 0;
            rstart = str[i + 1];
        }
        else
            item++;
    }
    ll cit = 0;
    foreach (i, save["BB"])
        cit += i / 2;
    foreach (i, save["AA"])
        cit += i / 2;
    vi AB = move(save["AB"]);
    vi BA = move(save["BA"]);
    sort(all(AB));
    sort(all(BA), greater<ll>());
    ll _ab = cit, _ba = 0;
    foreach (i, AB)
        _ab += i / 2;
    foreach (i, BA)
        _ab += (i - 1) / 2;
    while (true)
    {
        if (_ab >= ab && _ba >= ba)
        {
            give("YES");
        }
        if (BA.size())
        {
            if (BA[BA.size() - 1] == 2)
            {
                _ba++;
                BA.pop_back();
            }
            else
            {
                BA[BA.size() - 1] -= 2;
                _ab -= 1;
                _ba += 1;
            }
        }
        else if (cit)
        {
            cit--;
            _ba++;
            _ab--;
        }
        else if (AB.size())
        {
            while (AB.size() && AB[AB.size() - 1] <= 2)
            {
                AB.pop_back();
            }
            if (AB.size() == 0)
                break; 
            if (AB[AB.size() - 1] % 2 == 0)
            {
                AB[AB.size() - 1] -= 3;
                _ab -= 2;
                _ba += 1;
            }
            else
            {
                AB[AB.size() - 1] -= 2;
                _ab -= 1;
                _ba += 1;
            }
        }
        else{
            break; 
        }
    }
    if (_ab >= ab && _ba >= ba)
    {
        give("YES");
    }
    give("NO");
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
