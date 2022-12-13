#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        ll dp[n + 1][2];
        dp[1][0] = 1;
        dp[1][1] = 1;
        ll ans = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i + 1][0] = 1;
            dp[i + 1][1] = 1;
            if (arr[i] == arr[i - 1])
                dp[i + 1][0] = dp[i][0] + 1;
            if (arr[i] == (arr[i - 1] + 1))
                dp[i + 1][0] = dp[i][1] + 1;
            if ((arr[i] + 1) == arr[i - 1])
                dp[i + 1][1] = dp[i][0] + 1;
            if ((arr[i] + 1) == (arr[i - 1] + 1))
                dp[i + 1][1] = dp[i][1] + 1;
            dp[i + 1][0] = max(dp[i + 1][0], 1LL);
            dp[i + 1][1] = max(dp[i + 1][1], 1LL);
            ans = max({ans, dp[i + 1][0], dp[i + 1][1]});
        }
        cout << ans << endl;
    }
}
