#include "bits/stdc++.h"
using namespace std;
#define ll int

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
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
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
inline void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
inline void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
const int64_t mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n % mod + mod) % mod; }
ll power(ll x, ll y)
{
    x %= mod;
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
struct seg
{
#define mid ((start + end) / 2)
#define lnode (n->left)
#define rnode (n->right)
    struct Node
    {
        ll lazy, val;
        Node *left, *right;
        Node()
        {
            lazy = 0, val = 0;
            left = nullptr, right = nullptr;
        }
    };
    Node *n = new Node();
    ll smallestright(ll ind)
    {
        return smallestright(ind, n, 0, INT_INF / 2);
    }
    ll smallestleft(ll ind)
    {
        return smallestleft(ind, n, 0, INT_INF / 2);
    }
    void update(ll l, ll r, ll val)
    {
        update(l, r, val, n, 0, INT_INF / 2);
    }
    ll rfind(ll l, ll r)
    {
        return rfind(l, r, n, 0, INT_INF / 2);
    }

    inline void extend(Node *n, ll start, ll end)
    {
        if (lnode == nullptr)
            lnode = new Node();
        if (rnode == nullptr)
            rnode = new Node();
        if (n->lazy)
        {
            n->val += n->lazy * (end - start + 1);
            lnode->lazy += n->lazy;
            rnode->lazy += n->lazy;
            n->lazy = 0;
        }
    }
    void update(ll l, ll r, ll val, Node *n, ll start, ll end)
    {
        if (r < start || end < l)
            return;
        else if (l <= start && end <= r)
        {
            n->lazy += val;
            return;
        }
        extend(n, start, end);
        update(l, r, val, lnode, start, mid);
        update(l, r, val, rnode, mid + 1, end);
        n->val = 0;
        if (lnode != nullptr)
            n->val += lnode->val + lnode->lazy * (mid - start + 1);
        if (rnode != nullptr)
            n->val += rnode->val + rnode->lazy * (end - (mid + 1) + 1);
    }
    ll rfind(ll l, ll r, Node *n, ll start, ll end)
    {
        if (r < start || end < l)
            return 0;
        else if (l <= start && end <= r)
        {
            return n->lazy * (end - start + 1) + n->val;
        }
        extend(n, start, end);
        ll rst = rfind(l, r, lnode, start, mid);
        if (rst)
            return rst;
        return rfind(l, r, rnode, mid + 1, end);
    }
    ll smallestright(ll ind, Node *n, ll start, ll end)
    {
        if (end < ind || n->val + n->lazy == 0)
            return -1;
        if (start == end)
            return start;
        extend(n, start, end);
        ll res = smallestright(ind, n->left, start, mid);
        if (res != -1)
            return res;
        return smallestright(ind, n->right, mid + 1, end);
    }
    ll smallestleft(ll ind, Node *n, ll start, ll end)
    {
        if (ind < start || n->val + n->lazy == 0)
            return -1;
        if (start == end)
            return start;
        extend(n, start, end);
        ll res = smallestleft(ind, n->right, mid + 1, end);
        if (res != -1)
            return res;
        return smallestleft(ind, n->left, start, mid);
    }
    void deletenodes(Node *n)
    {
        if (n == nullptr)
            return;
        auto x1 = n->left;
        auto x2 = n->right;
        delete (n);
        deletenodes(x1), deletenodes(x2);
    }
};
void func()
{
    newint(n);
    V<vi> vec;
    V<map<pii, ll>> color(n);
    seg s;
    range(i, n)
    {
        newint(a, b, c);
        vec.push_back({a, b, c - 1});
        if (color[vec[i][2]].count(pii(vec[i][0], vec[i][1])))
            continue;
        s.update(vec[i][0], vec[i][1], 1);
        color[vec[i][2]][pii(vec[i][0], vec[i][1])] = INT_INF;
    }

    foreach (c, color)
    {
        foreach (p, c)
        {
            s.update(p.first.first, p.first.second, -1);
        }
        foreach (p, c)
        {
            ll &ans = p.second;
            bool u = s.rfind(p.first.first, p.first.second);
            if (u)
            {
                ans = 0;
                continue;
            }
            ll sright = s.smallestright(p.first.second);
            ll sleft = s.smallestleft(p.first.first);
            if (sright != -1)
                ans = min(ans, abs(sright - p.first.second));
            if (sleft != -1)
                ans = min(ans, abs(sleft - p.first.first));
        }
        foreach (p, c)
        {
            s.update(p.first.first, p.first.second, 1);
        }
    }

    vi ans;
    range(i, n)
    {
        ll l = vec[i][0], r = vec[i][1], col = vec[i][2];
        ans.pb(color[col][pii(l, r)]);
    }
    s.deletenodes(s.n);
    print(ans);
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
