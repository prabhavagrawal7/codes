#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl "\n"
ll gp(ll n, vector<int> &parent)
{
    if (parent[n] == n)
        return n;
    else
        return parent[n] = gp(parent[n], parent);
}
ll merge(ll n1, ll n2, vector<int> &parent)
{
    ll p1 = gp(n1, parent), p2 = gp(n2, parent);
    if (p1 == p2)
        return p1;
    else
    {
        parent[p1] = p2;
        return p2;
    }
}
ll brute(int n, int k, vector<vector<int>> queries)
{
    struct components
    {
        vector<set<int>> comp;
        components()
        {
            comp = vector<set<int>>(3);
        }
        ll find(int x)
        {
            for (int i = 0; i < 3; i++)
            {
                if (comp[i].count(x))
                    return i;
            }
            return -1;
        }
    };
    vector<components> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        v[i].comp[0].insert(i);
    }
    map<int, components *> m;
    for (int i = 1; i <= n; i++)
    {
        m[i] = &v[i];
    }
    ll count_false = 0;
    for (int i = 0; i < k; i++)
    {
        int type, x, y;
        type = queries[i][0], x = queries[i][1], y = queries[i][2];
        if (x > n || y > n)
        {
            count_false++;
            continue;
        }
        if (type == 1)
        {
            if (x == y)
                continue;
            if (m[x] == m[y])
            {
                count_false++;
                continue;
            }
            components *c1 = m[x], *c2 = m[y];
            // merge into c1 itself
            ll id1 = c1->find(x);
            ll id2 = c2->find(y);
            for (int i = 0; i < 3; i++)
            {
                c1->comp[id1].insert(c2->comp[id2].begin(), c2->comp[id2].end());
                id1 = (id1 + 1) % 3;
                id2 = (id2 + 1) % 3;
            }
            m[y] = c1;
        }
        else
        {
            if (m[x] == m[y])
            {
                if ((m[x]->find(x) + 1) % 3 == m[y]->find(y))
                    continue;
                count_false++;
                continue;
            }
            components *c1 = m[x], *c2 = m[y];
            // merge into c1 itself
            ll id1 = (c1->find(x) + 1) % 3;
            ll id2 = c2->find(y);
            for (int i = 0; i < 3; i++)
            {
                c1->comp[id1].insert(c2->comp[id2].begin(), c2->comp[id2].end());
                id1 = (id1 + 1) % 3;
                id2 = (id2 + 1) % 3;
            }
            m[y] = c1;
        }
    }
    return count_false;
}

ll func(int n, int k, vector<vector<int>> queries)
{
    // store every random object to remove redundancy
    // every object will have a component number, and parent component number generated by random
    vector<int> parent(n * 3 + 3);
    for (ll i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
    ll count_false = 0;

    for (int i = 0; i < k; i++)
    {
        int type, x, y;
        type = queries[i][0], x = queries[i][1], y = queries[i][2];
        if (x > n || y > n)
        {
            count_false++;
            continue;
        }
        x *= 3, y *= 3;
        if (type == 1)
        {
            // check if they are already in same component
            if (x == y)
                continue;
            ll x_comp = gp(parent[x], parent), y_comp = gp(parent[y], parent);
            if (x_comp / 3 == y_comp / 3)
            {
                count_false++;
                continue;
            }
            // if they are not in same component, then merge them
            ll componentx = x_comp / 3, componenty = y_comp / 3;
            ll r1 = x_comp % 3, r2 = y_comp % 3;
            for (int i = 0; i < 3; i++)
            {
                ll z1 = (i + r1) % 3, z2 = (i + r2) % 3;
                merge(componentx * 3 + z1, componenty * 3 + z2, parent);
            }
        }
        else
        {
            if (x == y)
            {
                count_false++;
                continue;
            }
            ll x_comp = gp(parent[x], parent), y_comp = gp(parent[y], parent);
            if (x_comp / 3 == y_comp / 3)
            {
                ll r1 = (x_comp + 1) % 3, r2 = y_comp % 3;
                if (r1 == r2)
                    continue;
                else
                {
                    count_false++;
                    continue;
                }
            }
            ll componentx = x_comp / 3, componenty = y_comp / 3;
            ll r1 = x_comp % 3, r2 = y_comp % 3;
            for (int i = 0; i < 3; i++)
            {
                ll z1 = (i + r1 + 1) % 3, z2 = (i + r2) % 3;
                merge(componentx * 3 + z1, componenty * 3 + z2, parent);
            }
        }
    }
    return count_false;
}
int main()
{
    FAST;
    // int t;
    // cin >> t;
    // while(t--)
    // {
    //     int n, k;
    //     vector<vector<int>> queries;
    //     cin >> n >> k;
    //     for (int i = 0; i < k; i++)
    //     {
    //         int type, x, y;
    //         cin >> type >> x >> y;
    //         queries.push_back({type, x, y});
    //     }
    //     ll ans1 = brute(n, k, queries);
    //     cout << ans1 << endl;
    // }
    while(true)
    {
        int n = rand() % 5 + 1, k = rand() % 5 + 1;
        vector<vector<int>> queries;
        for (int i = 0; i < k; i++)
        {
            int type = rand() % 2 + 1, x = rand() % n + 1, y = rand() % n + 1;
            queries.push_back({type, x, y});
        }
        ll ans1 = brute(n, k, queries);
        ll ans2 = func(n, k, queries);
        if(ans1 != ans2)
        {
            cout << n << " " << k << endl;
            for(auto i : queries)
            {
                for(auto j : i)
                {
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << ans1 << " " << ans2 << endl;
            break;
        }
    }
}
