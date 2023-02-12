#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 4;
const int M = 1e9 + 7;
ll dist[20][20], a[20][20];
int dp[(1 << 15) + 2][16];
int len;
int n, x, y;
int l;

int fun(int mask, int prev)
{
    if (mask == (1 << len) - 1)
        return a[prev][n + 1];
    int &ans = dp[mask][prev];
    if (ans != -1)
        return ans;
    ans = 1e9;
    for (int i = 0; i < len; i++)
    {
        if (!(mask & (1 << i)))
        {
            ans = min((ll)ans, a[prev][i + l] + fun((mask | (1 << i)), i + l));
        }
    }
    return ans;
}

ll dp2[20];
ll fun2(int pos)
{
    if (pos > n)
        return 0;
    ll &ans = dp2[pos];
    if (ans != -1)
        return ans;
    ans = 1e15;
    for (int i = pos; i <= n; i++)
        ans = min(ans, dist[pos][i] + fun2(i + 1));
    return ans;
}

void solve()
{

    cin >> n >> x >> y;
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
            cin >> a[i][j];
    }

    for (l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            len = r - l + 1;
            for (int i = 0; i <= (1 << len); i++)
                for (int j = 0; j <= 15; j++)
                    dp[i][j] = -1;

            dist[l][r] = (fun(0, 0) * ((ll)2 * y)) + x;
        }
    }
    memset(dp2, -1, sizeof(dp2));
    cout << fun2(1) << "\n";
}
int main()
{
    solve();
    return 0;
}