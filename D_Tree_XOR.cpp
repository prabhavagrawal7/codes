#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define ll int64_t
struct store
{
    ll child, subtree, val, sum;
    store() : child(0), subtree(0), val(0), sum(0) {}
    store(ll a, ll b, ll c, ll d) : child(a), subtree(b), val(c), sum(d) {}
};
vector<store> g[200005];
int vec[200005];
int subtree_calc(int parent, int child_idx)
{
    int child = g[parent][child_idx].child;
    auto &val = g[parent][child_idx].subtree;
    if (val != -1)
        return val;
    else
        val = 1;
    for (int i = 0; i < g[child].size(); i++)
    {
        if (g[child][i].child == parent)
            continue;
        val += subtree_calc(child, i);
    }
    return val;
}
ll dfs(int parent, int child_idx)
{
    int child = g[parent][child_idx].child;
    auto &val = g[parent][child_idx].sum;
    if (val != -1)
        return val;
    else if (parent == 0)
        val = 0;
    else
        val = (ll)g[parent][child_idx].subtree * g[parent][child_idx].val;
    for (int i = 0; i < g[child].size(); i++)
    {
        if (g[child][i].child == parent)
            continue;
        val += dfs(child, i);
    }
    return val;
}

void func()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
    }
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back({b, -1, vec[a] ^ vec[b], -1});
        g[b].push_back({a, -1, vec[a] ^ vec[b], -1});
    }
    for (int i = 0; i <= n; i++)
    {
        g[0].push_back({i, -1, -1, -1});
    }
    vector<ll> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        subtree_calc(0, i);
        ans[i] = dfs(0, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }
}
