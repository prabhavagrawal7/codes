#include <bits/stdc++.h>
using namespace std;
#define ll int

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)
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
struct segtree
{
    // critical
    const ll initstart = 0;
    const ll initend = (1 << (clz(1e5) + 2));
#define mid ((start + end) >> 1)
#define lnode (node->left)
#define rnode (node->right)
#define neutral_element vi(1, -1)
    struct SegNode
    {
        SegNode *left, *right;
        vi val;
        SegNode() : left(nullptr), right(nullptr), val(neutral_element) {}
    };
    SegNode *node;
    segtree()
    {
        node = new SegNode();
    }
    void push(SegNode *&node, ll start, ll end)
    {
        if (lnode == nullptr)
            lnode = new SegNode();
        if (rnode == nullptr)
            rnode = new SegNode();
        // critical
        if (node->val[0] == -1)
            return;
        lnode->val = node->val;
        rnode->val = node->val;
        node->val = {-1};
    }

    vi opr(vi a, vi b)
    {
        // critical;
        if (a == neutral_element)
            return b;
        if (b == neutral_element)
            return a;
        return a;
    }
    void rangeupdate(ll l, ll r, ll val)
    {
        rangeupdate(l, r, val, node, initstart, initend);
    }
    vi rangefind(ll l, ll r)
    {
        return rangefind(l, r, node, initstart, initend);
    }
    void rangeupdate(ll l, ll r, ll val, SegNode *&node, ll start, ll end)
    {
        if (r < start || end < l)
            return;
        if (node == nullptr)
            node = new SegNode();
        if (l <= start && end <= r)
        {
            // critical
            node->val[0] = val;
            return;
        }
        push(node, start, end);
        rangeupdate(l, r, val, lnode, start, mid);
        rangeupdate(l, r, val, rnode, mid + 1, end);
    }
    vi rangefind(ll l, ll r, SegNode *&node, ll start, ll end)
    {
        if (r < start || end < l)
            return neutral_element;
        if (l <= start && end <= r)
            return node->val;

        push(node, start, end);
        return opr(rangefind(l, r, lnode, start, mid),
                   rangefind(l, r, rnode, mid + 1, end));
    }
};
void func()
{
    newint(n, k);
    segtree s;
    s.rangeupdate(0, n - 1, 0);
    range(i, k)
    {
        newint(x);
        if (x == 1)
        {
            newint(a, b, c);
            s.rangeupdate(a, b - 1, c);
        }
        else
        {
            newint(ind);
            print(s.rangefind(ind, ind));
        }
    }
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    func();
}
