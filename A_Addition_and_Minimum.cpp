#include "bits/stdc++.h"
using namespace std;
#define ll int64_t

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

// for segment tree

#define popcount(x) __builtin_popcount(x)
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
#define r4(var, start, stop, step) for (int var = start; step >= 0 ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (int var = start; var < stop; var++)
#define r2(var, stop) for (int var = 0; var < stop; var++)
#define r1(stop) for (int start_from_0 = 0; start_from_0 < stop; start_from_0++)
#define newint(...)  \
    int __VA_ARGS__; \
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
#define aint(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
string db_bin(int n)
{
    string ans;
    while (n)
    {
        ans.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(aint(ans));
    return ans;
}
#define newstring(str) \
    string str;        \
    cin >> str;
#define foreach(a, x) for (auto &&a : x)
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef set<int> si;
typedef vector<vector<int>> vvi;
template <typename... T>
inline void take_input(T &&...args) { ((cin >> args), ...); }
vi inputvec(int n, int start = 0)
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
inline ld TLD(int n) { return n; }
int gcd(int __m, int __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
const int64_t mod = 1000000007;
// const int mod = 998244353;
inline int rs(int n) { return (n = n % mod) >= 0 ? n : n + mod; }
int power(int x, int y)
{
    int res = 1;
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
#define mid (start + end) / 2
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
    int n;
    V<pii> tree;
    // min, sum
    seg(int n)
    {
        int n1 = 1;
        while (n1 < n)
            n1 <<= 1;
        tree.assign(n1 * 2, pii());
    }
    void rupdate(int l, int r, int val, int node, int start, int end)
    {
        if (r < start || end < l)
            return;
        if (l <= start && end <= r)
        {
            tree[node].second += val;
            return;
        }
        tree[node].first += tree[node].second;
        tree[lnode].second += tree[node].second;
        tree[rnode].second += tree[node].second;
        tree[node].second = 0;
        rupdate(l, r, val, lnode, start, mid);
        rupdate(l, r, val, rnode, mid + 1, end);
        tree[node].first = min(tree[lnode].first + tree[lnode].second,
                               tree[rnode].first + tree[rnode].second);
    }

    ll rfind(int l, int r, int node, int start, int end)
    {
        if (r < start || end < l)
            return INF;
        if (l <= start && end <= r)
        {
            return tree[node].first + tree[node].second;
        }
        tree[node].first += tree[node].second;
        tree[lnode].second += tree[node].second;
        tree[rnode].second += tree[node].second;
        tree[node].second = 0;
        return min(rfind(l, r, lnode, start, mid),
                   rfind(l, r, rnode, mid + 1, end));
    }
};
void func()
{
    newint(n, m);
    seg s(n);
    range(m)
    {
        newint(a);
        if (a == 1)
        {
            newint(x, y, z);
            s.rupdate(x, y - 1, z, 0, 0, n - 1);
        }
        else
        {
            newint(x, y);
            print(s.rfind(x, y - 1, 0, 0, n - 1));
        }
    }
}
int main()
{
    // Uncomment for faster I/O
    FAST;
    func();
}
