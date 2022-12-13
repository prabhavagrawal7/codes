#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
const ll mod = 1000000007;
// const ll mod = 998244353;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const long double pi = acos(-1);

#define object(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) object(__VA_ARGS__, range4, range3, range2, range1)(__VA_ARGS__)
#define range4(var, start, stop, step) for (ll var = start; step >= 0 ? var < stop : var > stop; var = var + step)
#define range2(var, end) for (ll var = 0; var < end; var++)
#define range1(stop) for (ll start_from_0 = 0; start_from_0 < stop; start_from_0++)

#define newinput(...) \
    ll __VA_ARGS__;   \
    take_input(__VA_ARGS__)

#define gvr(...)            \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    }
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define V vector
#define all(a) a.begin(), a.end()
#define newstr(str) \
    string str;     \
    cin >> str;
#define foreach(a, x) for (auto &a : x)

typedef pair<ll, ll> pii;
typedef vector<ll> vr;
typedef vector<vector<ll>> vvr;

template <typename... T>
void take_input(T &&...args) { ((cin >> args), ...); }
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
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
template <typename... T>
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printline(T &&...args) { ((cout << args << " "), ...); }
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T>;

vr inputvector(ll n, ll start = 0)
{
    vr vec(n);
    range(i, start, n, 1) cin >> vec[i];
    return vec;
}
char chart(ll a) { return char(a + 'a'); }
ll intt(char a) { return (a - 'a'); }
ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
}
ll lcm(ll x, ll y)
{
    ll res = x;
    res = res / (gcd(x, y));
    res *= y;
    return res;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

V<set<ll>> g(1e5 + 1), gn(1e5 + 1);
vr subtree(1e5 + 1), par(1e5 + 1), res(1e5 + 1, INT_MAX);
vvr LCA(1e5+5, vr(21, 0));
vr depth(1e5 + 1, 0);

void dfspre(ll node)
{
    stack<ll> s;
    s.push(node);
    vector<int> vis(g.size() + 1);
    while (!s.empty())
    {
        ll cur = s.top();
        s.pop();
        foreach (i, g[cur])
        {
            if (vis[i])
                continue;
            vis[i] = 1;
            s.push(i);
            depth[i] = depth[cur] + 1;
            LCA[i][0] = cur;
            range(j, 1, 21, 1)
            {
                LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
            }
        }
    }
}

ll dfs(ll node, ll parent)
{
    subtree[node] = 1;
    foreach (i, g[node])
    {
        if (i == parent)
            continue;
        subtree[node] += dfs(i, node);
    }
    return subtree[node];
}

ll dfs1(ll node, ll parent, ll subtreesize)
{
    foreach (i, g[node])
    {
        if (i != parent && subtree[i] > subtreesize / 2)
        {
            return dfs1(i, node, subtreesize);
        }
    }
    return node;
}

void decompose(ll node, ll parent)
{
    ll subtreesize = dfs(node, 0);
    ll centroid = dfs1(node, parent, subtreesize);

    par[centroid] = parent;

    foreach (i, g[centroid])
    {
        g[i].erase(centroid);
        decompose(i, centroid);
    }
}

ll lca(ll p, ll q)
{
    if (depth[p] < depth[q])
        swap(p, q);
    ll d = depth[p] - depth[q];

    range(i, 20, -1, -1)
    {
        if ((d >> i) & 1LL)
            p = LCA[p][i];
    }

    if (p == q)
        return p;
    range(i, 20, -1, -1)
    {
        if ((LCA[p][i] != LCA[q][i]))
        {
            p = LCA[p][i];
            q = LCA[q][i];
        }
        // else break;
    }

    return LCA[p][0];
}

ll distance(ll u, ll v)
{
    ll x = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[x];
}

void update(ll node)
{
    ll cur = node;
    while (cur != 0)
    {
        res[cur] = min(res[cur], distance(node, cur));
        cur = par[cur];
    }
}

void solve()
{
    newinput(n, q);
    range(n - 1)
    {
        newinput(u, v);
        g[u].insert(v);
        g[v].insert(u);
    }
    gn = g;
    dfspre(1);
    decompose(1, 0);
    update(1);
    range(q)
    {
        newinput(t, u);

        if (t == 1)
        {
            update(u);
        }
        else
        {
            ll v = u;
            ll ans = INT_MAX;
            while (v != 0)
            {
                ans = min(ans, res[v] + distance(v, u));
                v = par[v];
            }

            print(ans);
        }
    }
}

int main()
{
    solve();
}