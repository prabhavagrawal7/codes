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
#define mid ((start + end) >> 1)
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
    V<vi> tree;
    vi vec;
    ll n;
    void collapse(ll node)
    {
        while (tree[node][1])
        {
            ll sumofall = 0;
            while (tree[node][0])
            {
                sumofall += tree[node][0] % 10;
                tree[node][0] /= 10;
            }
            tree[node][0] = sumofall;
            tree[node][1]--;
            if (tree[node][0] < 10)
            {
                tree[node][1] = 0;
                break;
            }
        }
    }
    seg(vi vec)
    {
        this->n = vec.size();
        tree.assign(1LL << (clz(n) + 2), {-1, 0});
        this->vec = move(vec);
    }
    void push(ll node, ll start, ll end)
    {
        // critical
        if (tree[node][1] == 0)
            return;
        tree[lnode][1] += tree[node][1];
        tree[rnode][1] += tree[node][1];
        tree[node][1] = 0;
    }

    void update(ll l, ll r, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return;
        else if (l <= start && end <= r)
        {
            // critical
            tree[node][1]++;
            if (start == end)
            {
                if (tree[node][0] == -1)
                    tree[node][0] = vec[start];
                collapse(node);
            }
            return;
        }
        push(node, start, end);
        update(l, r, lnode, start, mid);
        update(l, r, rnode, mid + 1, end);
    }
    ll rfind(ll ind, ll node, ll start, ll end)
    {
        if (start == end)
        {
            if (tree[node][0] == -1)
                tree[node][0] = vec[start];
            collapse(node);
            return tree[node][0];
        }
        push(node, start, end);
        if (ind <= mid)
            return rfind(ind, lnode, start, mid);
        else
            return rfind(ind, rnode, mid + 1, end);
    }
};
void func()
{
    newint(n, q);
    auto vec = inputvec(n);
    seg s(vec);
    range(i, q)
    {
        newint(opr);
        if (opr == 1)
        {
            newint(l, r);
            s.update(l - 1, r - 1, 0, 0, n - 1);
        }
        else
        {
            newint(x);
            print(s.rfind(x - 1, 0, 0, n - 1));
        }
    }
}
int main()
{
    FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
