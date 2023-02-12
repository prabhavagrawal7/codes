#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

// for segment tree
#define mid (start + end) / 2
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
#define popcount(x) __builtin_popcountll(x)
#define clz(x) (63 - __builtin_clzll(x)) // count leading zeros
#define ctz(x) __builtin_ctzll(x)        // count trailing zeros
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
#define r4(var, start, stop, step) for (ll var = start; step > 0 ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (ll var = start; var < stop; ++var)
#define r2(var, stop) for (ll var = 0; var < stop; ++var)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 < stop; ++start_from_0)
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
#define ppb pop_back
#define pf push_front
#define ppf pop_front
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
inline void take_input(T &&...args) { ((cin >> args), ...); }
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    range(i, start, n) cin >> vec[i];
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
istream &operator>>(istream &is, V<T> &v)
{
    range(i, v.size()) { is >> v[i]; }
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const V<T> &v)
{
    range(i, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); }
    return os;
}
template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}
template <typename... T>
inline void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
inline void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
const ll mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n = n % mod) >= 0 ? n : n + mod; }
ll power(ll x, ll y)
{
    x %= mod, y %= mod - 1;
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
ll inv(ll n) { return power(n, mod - 2); }

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

struct seg
{
#define pref 0
#define suf 1
#define sum 2
#define ans 3
#define change 4
    vvi tree;

    ll n;

    seg(ll n)
    {
        this->n = n;
        tree.assign(4 * n, vi(5, 0));
    }

    vi opr(vi a, vi b)
    {
        vi c(5, INT_INF);
        c[pref] = max(a[pref], a[sum] + b[pref]);
        c[suf] = max(b[sum] + a[suf], b[suf]);
        c[sum] = a[sum] + b[sum];
        c[ans] = max(a[ans], b[ans], a[suf] + b[pref]);
        return c;
    }

    void push(ll node, ll start, ll end)
    {
        if (tree[node][change] == INT_INF)
            return;
        ll p = max(0LL, (mid - start + 1) * tree[node][change]);
        ll q = max(0LL, (end - mid) * tree[node][change]);
        tree[lnode] = {p, p, (mid - start + 1) * tree[node][change], p, tree[node][change]};
        tree[rnode] = {q, q, (end - mid) * tree[node][change], q, tree[node][change]};
        tree[node][change] = INT_INF;
    }

    void update(ll l, ll r, ll val, ll node, ll start, ll end)
    {
        if (start > r || end < l)
            return;
        if (start >= l && end <= r)
        {
            ll r = max(0LL, (end - start + 1) * val);
            tree[node] = {r, r, (end - start + 1) * val, r, val};
            return;
        }
        push(node, start, end);
        update(l, r, val, lnode, start, mid);
        update(l, r, val, rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
    }
    ll rf()
    {
        return tree[0][ans];
    }
};

void func()
{
    newint(n, q);
    seg s(n);
    range(q)
    {
        newint(l, r, v);
        s.update(l, r - 1, v, 0, 0, n - 1);
        print(s.rf());
    }
}
int main()
{
    FAST;
    {
        func();
    }
}
