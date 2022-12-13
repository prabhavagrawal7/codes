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
#define clz(x) 63 - __builtin_clzl(x) // count leading zeros
#define ctz(x) __builtin_ctz(x)       // count trailing zeros
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

struct item
{
    vvi g;
    vvi lcav;
    vvi jumpv;
    vi depth;
    vvi dp;
    string str;

    ll jump(ll node, ll till)
    {
        if (depth[node] < till)
            return -1;
        range(i, 11 - 1, -1, -1)
        {
            if ((till >> i) & 1)
                node = jumpv[node][i];
        }
        return node;
    }
    ll lca(ll n, ll m)
    {
        if (depth[n] > depth[m])
            swap(n, m);
        m = jump(m, depth[m] - depth[n]);
        if (n == m)
            return n;
        ll l = 0, r = 2e3 + 1, mid;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (jump(n, mid) == jump(m, mid))
                r = mid;
            else
                l = mid;
        }
        return jump(n, mid);
    }

    V<pii> close(ll node1, ll node2)
    {
        V<pii> ans;
        if (depth[node1] > depth[node2])
            swap(node1, node2);
        ll com = lca(node1, node2);
        if (com == node1)
        {
            ans.push_back({node1, jump(node2, 1)});
            ans.push_back({node2, jump(node2, depth[node2] - depth[node1] - 1)});
        }
        else
        {
            ans.push_back({node1, jump(node2, 1)});
            ans.push_back({jump(node1, 1), node2});
        }
        return ans;
    }
    pii closer(ll node1, ll node2)
    {
        if (depth[node1] > depth[node2])
            swap(node1, node2);
        ll com = lca(node1, node2);
        if (com == node1)
        {
            return {jump(node2, 1), jump(node2, depth[node2] - depth[node1] - 1)};
        }
        else
        {
            return {jump(node1, 1), jump(node2, 1)};
        }
    }
    ll rec(ll start, ll end)
    {
        if (start == end)
            return 1;
        if (start > end)
            swap(start, end);
        if (dp[start][end] != -1)
            return dp[start][end];
        ll ans = 0;
        if (str[start - 1] == str[end - 1])
        {
            ans = max(ans, 2LL);
            auto nxt = closer(start, end);
            if (nxt.first > nxt.second)
                swap(nxt.first, nxt.second);
            if (!(nxt.first == start && nxt.second == end))
            {
                ans = max(ans, 2 + rec(nxt.first, nxt.second));
            }
        }

        auto cont = close(start, end);
        foreach (con, cont)
        {
            ans = max(ans, rec(con.first, con.second));
        }
        return dp[start][end] = ans;
    }
    item()
    {
        newint(n);
        cin >> str;
        g.assign(n + 1, {});
        lcav.assign(n + 1, vi(n + 1));
        jumpv.assign(n + 1, vi(11, -1));
        depth.assign(n + 1, 0);
        dp.assign(n + 1, vi(n + 1, -1));
        range(i, n - 1)
        {
            newint(a, b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        stack<ll> dfs;
        dfs.push(1);
        vi vis(n + 1);
        vis[1] = 1;
        while (dfs.size())
        {
            ll x = dfs.top();
            dfs.pop();
            foreach (i, g[x])
            {
                if (vis[i])
                    continue;
                depth[i] = depth[x] + 1;
                vis[i] = 1;
                dfs.push(i);
                jumpv[i][0] = x;
                range(j, 1, 11)
                {
                    if (jumpv[i][j - 1] == -1)
                        break;
                    if (jumpv[jumpv[i][j - 1]][j - 1] == -1)
                        break;
                    jumpv[i][j] = jumpv[jumpv[i][j - 1]][j - 1];
                }
            }
        }
        ll ans = 0;
        range(i, 1, n + 1)
        {
            range(j, i, n + 1)
            {
                ans = max(ans, rec(i, j));
            }
        }
        print(ans);
    }
};

int main()
{
    // Uncomment for faster I/O
    FAST;
    newint(t);
    range(t)
    {
        item();
    }
}
