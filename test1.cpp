#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int add(int x, int y)
{
    return (x + y) % mod;
}

int mul(int x, int y)
{
    return (x * y) % mod;
}

int dp[101][101][101];
int solver(int i, int maxm, int n, int m, int totalCost)
{
    if (i == n)
    {
        if (totalCost == 0)
            return 1;
        else
            return 0;
    }
    if (dp[i][maxm][totalCost] != -1)
    {
        return dp[i][maxm][totalCost];
    }

    int temp = 0;
    for (int j = 1; j <= m; j++)
    {
        if (j > maxm)
            temp = add(temp, solver(i + 1, j, n, m, totalCost - 1));
        else
            temp = add(temp, solver(i + 1, maxm, n, m, totalCost));
    }
    return dp[i][maxm][totalCost] = temp;
}

int solve(int N, int M, int Tot)
{
    int answer;
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= M; i++)
    {
        ans = add(ans, solver(1, i, N, M, Tot));
    }
    return ans; 
}

int main()
{

    int q;
    cin >> q;

    vector<int> n(q);
    vector<int> m(q);
    vector<int> totalCost(q);
    for (int i = 0; i < q; i++)
    {
        cin >> n[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> m[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> totalCost[i];
    }

    solve(n, m, totalCost);
}