#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int vec[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    //tabulation starting here
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    int ans1, ans2;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= k; i++)
        {
            ans1 = 0, ans2 = 0;
            if (vec[j - 1] <= i)
                ans1 = dp[j][i - vec[j - 1]];
            ans2 = dp[j - 1][i];
            dp[j][i] = (ans1 + ans2) % mod;
        }
    }
    cout << dp[n][k];
}
