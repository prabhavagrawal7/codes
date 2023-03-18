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
inline ll rs(ll n) { return (n %= mod) >= 0 ? n : n + mod; }
// define rll above this
#ifndef __RLL__
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
#endif
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
struct ordered_set
{
#define mid ((start + end) >> 1)
#define lnode (node->left)
#define rnode (node->right)
#define lval (lnode != nullptr ? lnode->val : 0)
#define rval (rnode != nullptr ? rnode->val : 0)
    struct tree
    {
        tree *left, *right;
        ll val;
        tree() : left(nullptr), right(nullptr), val(0) {}
    };
    tree *node;
    ordered_set() : node(nullptr) {}
    ll __size = 0;
    size_t size()
    {
        return __size;
    };
    ll initstart = 0, initend = 2e5 + 1;
    void insert(ll n)
    {
        insert(n, node, initstart, initend);
    }
    void insert(ll n, tree *&node, ll start, ll end)
    {
        if (node == nullptr)
        {
            node = new tree();
        }
        if (start == end)
        {
            if (node->val == 0)
            {
                node->val = 1;
                __size += 1;
            }
            return;
        }
        if (n <= mid)
            insert(n, lnode, start, mid);
        else
            insert(n, rnode, mid + 1, end);
        node->val = lval + rval;
    }

    void erase(ll n)
    {
        erase(n, node, initstart, initend);
    }
    void erase(ll n, tree *&node, ll start, ll end)
    {
        if (node == nullptr)
            return;
        if (start == end)
        {
            __size -= 1;
            delete node;
            node = nullptr;
            return;
        }
        if (n <= mid)
            erase(n, lnode, start, mid);
        else
            erase(n, rnode, mid + 1, end);
        node->val = lval + rval;
        if (node->val == 0)
        {
            delete node;
            node = nullptr;
        }
    }

    ll operator[](ll n)
    {
        if (n < __size)
            return find_by_order(n + 1, node, initstart, initend);
        else
        {
            print("Bad key exception");
            return INF;
        }
    }
    ll find_by_order(ll n, tree *&node, ll start, ll end)
    {
        if (start == end)
            return start;
        if (n <= lval)
            return find_by_order(n, lnode, start, mid);
        else
            return find_by_order(n - lval, rnode, mid + 1, end);
    }

    ll find_order(ll n)
    {
        return find_order(n, node, initstart, initend);
    }
    ll find_order(ll n, tree *&node, ll start, ll end)
    {
        if (start == end)
            return 0;
        if (n <= mid)
            return find_order(n, lnode, start, mid);
        else
            return lval + find_order(n, rnode, mid + 1, end);
    }
};

void func()
{
    newint(n);
    vi a = inputvec(n);
    vi b = inputvec(n);
    ordered_set s;
    range(i, n) s.insert(i);
    vi facts(n + 1, 0);
    range(i, n)
    {
        ll &val = facts[n - 1 - i];
        ll id = s.find_order(a[i]);
        s.erase(a[i]);
        val += id;
    }
    range(i, n) s.insert(i);
    range(i, n)
    {
        ll &val = facts[n - 1 - i];
        ll id = s.find_order(b[i]);
        s.erase(b[i]);
        val += id;
    }
    range(i, n)
    {
        while (facts[i] > i)
            facts[i] -= i + 1, facts[i + 1] += 1;
    }
    range(i, n) s.insert(i);
    range(i, n - 1, -1, -1)
    {
        ll id = facts[i];
        ll rem = s[id];
        printl(rem);
        s.erase(rem);
        cout.flush();
    }
}
int main()
{
    FAST;
    func();
}
