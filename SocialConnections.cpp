#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll int64_t
// Function to perform depth-first search (DFS)

void dfs(ll n, vector<ll> &vis, vector<vector<ll>> &g, vector<ll> &path)
{
    vis[n] = 1;
    path.push_back(n);
    for (auto i : g[n])
    {
        if (vis[i] == 0)
            dfs(i, vis, g, path);
    }
}

// Main function for the first problem
vector<int> func(int connection_nodes, vector<int> connection_from, vector<int> connection_to, vector<int> queries)
{
    vector<vector<ll>> adj(connection_nodes + 1);
    for (ll i = 0; i < connection_from.size(); i++)
    {
        ll u = connection_from[i];
        ll v = connection_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> treesize(connection_nodes + 1, 0);
    vector<ll> vis(connection_nodes + 1, 0);
    for(int i = 1; i < adj.size(); i++)
    {
        if(vis[i] == 0)
        {
            vector<ll> path;
            dfs(i, vis, adj, path);
            for(auto j : path)
            {
                treesize[j] = path.size();
            }
        }
    }
    vector<int> ans; 
    for(auto x: queries)
    {
        ans.push_back(treesize[x]);
    }
    return ans; 
}

// Function to solve the second problem
void solve()
{
    int v, e;
    cin >> v >> e;
    vector<int> from(e), to(e);
    for (int i = 0; i < e; i++)
    {
        cin >> from[i];
        from[i]--;
    }
    for (int i = 0; i < e; i++)
    {
        cin >> to[i];
        to[i]--;
    }

    vector<vector<int>> edg(v);
    for (int i = 0; i < e; i++)
    {
        edg[from[i]].push_back(to[i]);
        edg[to[i]].push_back(from[i]);
    }

    vector<int> vis(v, 0), par(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (vis[i] > 0)
            continue;

        queue<int> q;
        q.push(i);
        vis[i] = 1;
        int cnt = 0;

        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            par[ele] = i;
            cnt++;

            for (auto it : edg[ele])
            {
                if (vis[it] == 0)
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        vis[i] = cnt;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        x--;
        cout << vis[par[x]] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // Call the appropriate function here
        // For the first problem, call func()
        // For the second problem, call solve()
    }
    return 0;
}
