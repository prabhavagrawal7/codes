#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define V vector
#define mp make_pair

class SubtangleGameE_2
{

    int l, n, m;
    const int MAX_STORE_IDX = 1505;
    const int MAX_L = 1505;

    vector<vector<int>> memo;
    vector<int> cvar;
    vector<int> a;
    vector<vector<int>> b;

public:
    SubtangleGameE_2(int l, int n, int m, const vector<int> &a, const vector<vector<int>> &b)
        : l(l), n(n), m(m), a(a), b(b), memo(MAX_L, vector<int>(MAX_STORE_IDX, -1)), cvar(MAX_STORE_IDX)
    {
    }
    bool can_win(int i, int storeIdx, const vector<int> &a, const vector<vector<pair<int, int>>> &store)
    {
        if (i >= a.size())
            return false;
        if (memo[i][storeIdx] != -1)
            return memo[i][storeIdx];

        int value = a[i];
        int prevValue = a[i - 1];
        int rowBound = store[prevValue][storeIdx].first;
        int colBound = store[prevValue][storeIdx].second;

        auto it = lower_bound(store[value].begin(), store[value].end(), make_pair(rowBound, (int)INT_MAX));

        for (; it != store[value].end(); ++it)
        {
            int row = it->first, col = it->second;
            if (col <= colBound)
                continue;
            if (!can_win(i + 1, it - store[value].begin(), a, store))
                return memo[i][storeIdx] = true;
        }
        return memo[i][storeIdx] = false;
    }

    vector<pair<int, int>> clearance(vector<pair<int, int>> &v, int max_value)
    {
        vector<int> store;
        for (auto &p : v)
        {
            if (cvar[p.first] == 0)
                store.push_back(p.first);
            cvar[p.first] = max(cvar[p.first], p.second);
        }
        v.clear();
        for (auto &i : store)
        {
            v.push_back({i, cvar[i]});
            cvar[i] = 0;
        }

        return v;
    }
    void solve_subtangle_game()
    {
        cin >> l >> n >> m;
        vector<int> a(l + 1);
        for (int i = 1; i <= l; i++)
            cin >> a[i];
        vector<vector<int>> b(n, vector<int>(m));
        for (auto &v : b)
        {
            for (auto &i : v)
                cin >> i;
        }

        vector<vector<pair<int, int>>> store(n * m + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                auto &cstore = store[b[i][j]];
                cstore.push_back({i, j});
            }
        }

        for (auto &v : store)
            clearance(v, max(n, m));
        store[0].push_back({-1, -1});

        for (int i = 0; i <= l; i++)
        {
            for (int j = 0; j < max(n, m); j++)
            {
                memo[i][j] = -1;
            }
        }

        cout << (can_win(1, 0, a, store) ? "T" : "N") << endl;
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int t;
        cin >> t;
        while (t--)
        {
            solve_subtangle_game();
        }
        return 0;
    }
};

class SubtangleGameE_1
{
private:
    int l, n, m;
    vector<vector<vector<vector<bool>>>> memo;
    vector<vector<vector<vector<bool>>>> visited;
    vector<int> a;
    vector<vector<int>> b;

    bool can_win(int i, int row, int col, bool player)
    {
        if (i == l || row == n || col == m)
            return false;

        if (visited[i][row][col][player])
            return memo[i][row][col][player];

        bool ans = false;
        if (row < n)
            ans |= can_win(i, row + 1, col, player);
        if (col < m)
            ans |= can_win(i, row, col + 1, player);

        if (row < n && col < m && b[row][col] == a[i])
            ans |= !can_win(i + 1, row + 1, col + 1, !player);

        visited[i][row][col][player] = true;
        return memo[i][row][col][player] = ans;
    }

public:
    SubtangleGameE_1(int l, int n, int m, const vector<int> &a, const vector<vector<int>> &b)
        : l(l), n(n), m(m), a(a), b(b)
    {
        // Resize memo and visited arrays dynamically
        memo.resize(l, vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(2, false))));
        visited.resize(l, vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(2, false))));
    }

    bool solve()
    {
        return can_win(0, 0, 0, false);
    }
};

int main()
{
    while (true)
    {
        int l = rand() % 10 + 1; // Random length between 1 and 10
        int n = rand() % 10 + 1; // Random rows between 1 and 10
        int m = rand() % 10 + 1; // Random columns between 1 and 10

        vi a(l + 1);
        for (int i = 1; i <= l; ++i)
        {
            a[i] = rand() % (n * m) + 1; // Random values between 1 and n * m
        }

        vvi b(n, vi(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                b[i][j] = rand() % (n * m) + 1; // Random values between 1 and n * m
            }
        }
        SubtangleGameE_1 game1(l, n, m, a, b);
        SubtangleGameE_2 game2(l, n, m, a, b);
        ll ans1 = game1.solve();
        ll ans2 = game2.solve();
        cout << ans1 << ans2 << endl;
    }
    return 0;
}
