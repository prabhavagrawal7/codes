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
class al
{
public:
    vi v;
    al()
    {
        v = vi(26, 0);
    }
    al operator-(al a)
    {
        al ans;
        range(i, 26)
            ans.v[i] = this->v[i] - a.v[i];
        return ans;
    }
    al operator+(char a)
    {
        al ans = *this;
        ans.v[a - 'a']++;
        return ans;
    }
    ll val()
    {
        ll u = 0;
        range(i, 26)
        {
            if (v[i])
                u++;
        }
        return u;
    }
};
set<pair<ll, pair<ll, ll>>> dp;
ll frange(ll l, ll r)
{
    if (l == r)
        return 1;
    auto f = dp.lower_bound({l, {r, -INT_INF * 1LL}});
    if (f->first == l && f->second.first == r)
        return f->second.second;
    else
    {
        cout << "? 2 " << l << " " << r << endl;
        ll a;
        cin >> a;
        dp.insert({l, {r, a}});
        return a;
    }
}
void func()
{
    newint(n);
    string ans(n, '\0');
    V<al> v(n + 1);
    ll tval = frange(1, n), uval = 0;
    V<pair<ll, char>> lastvalid;
    ll cntfnd = 0;
    range(i, n)
    {
        sort(all(lastvalid));
        ll l = 0, r = size(lastvalid), mid;
        if (lastvalid.size() + 1 == frange(1, i + 1))
        {
            cout << "? 1 " << i + 1 << endl;
            cin >> ans[i];
            v[i + 1] = v[i] + ans[i];
            lastvalid.emplace_back(i, ans[i]);
            continue;
        }
        set<pii> iterated;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            auto index = lastvalid[mid].first;
            ll ff = (v[i] - v[index]).val(); 
            ll f = frange(index + 1, i + 1);
            if(ff == f) l = mid; 
            else r = mid; 
        }
        ans[i] = lastvalid[l].second;
        v[i + 1] = v[i] + ans[i];
        lastvalid.erase(lastvalid.begin() + l);
        lastvalid.emplace_back(i, ans[i]);
    }
    cout << "! " << ans << endl;
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    func();
}
