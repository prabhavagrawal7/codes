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
#define popcount(x) __builtin_popcount(x)
#define clz(x) (63 - __builtin_clzl(x)) // count leading zeros
#define ctz(x) __builtin_ctz(x)         // count trailing zeros
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
#define mid ((start + end) / 2)
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
    V<vi> tree; // opr, sum of black, count, prefix, suffix
    ll n;
    seg(ll n)
    {
        this->n = n;
        tree.assign(n * 4, {});
    }
    void push(ll node, ll start, ll end)
    {
        // critical
        if (start == end)
            return;
        if (tree[node][0] == 1)
        {
            tree[lnode] = {1, mid - start + 1, 1, 1, 1};
            tree[rnode] = {1, end - (mid + 1) + 1, 1, 1, 1};
        }
        else if (tree[node][0] == 2)
        {
            tree[lnode] = {2, 0, 0, 0, 0};
            tree[rnode] = {2, 0, 0, 0, 0};
        }
        tree[node][0] = 0; 
    }
    vi opr(vi a, vi b)
    {
        // critical
        // opr     sum          count        prefix  suffix
        vi c = {0, a[1] + b[1], a[2] + b[2], a[3],   b[4]};
        if (a[4] && b[3])
            c[2] -= 1;
        return c;
    }
    void update(int op, int l, int r, int node, int start, int end)
    {
        if (r < start || end < l)
            return;
        else if (l <= start && end <= r)
        {
            // critical
            if (op == 1)
                tree[node] = {1, end - start + 1, 1, 1, 1};
            else if (op == 2)
                tree[node] = {2, 0, 0, 0, 0};
            return;
        }
        push(node, start, end);
        update(op, l, r, lnode, start, mid);
        update(op, l, r, rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
    }
};
void func()
{
    newint(q);
    ll n = 1000010;
    seg s(n);
    s.update(2, 0, n - 1, 0, 0, n - 1);
    range(i, q)
    {
        char ch;
        ll start, dis;
        cin >> ch;
        cin >> start >> dis;
        start = start + 500000; 
        ll opr = (ch == 'W' ? 2 : 1);
        s.update(opr, start, start + dis - 1, 0, 0, n - 1);
        auto &x = s.tree[0];
        cout << x[2] << " " << x[1] << endl; 
    }
}
int main()
{
    FAST;
    func();
}