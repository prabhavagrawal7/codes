#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
const ll mod = 1000000007;
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
int main()
{
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    ll limit = sum / 2;
    vector<vector<ll>> dp(n + 1, vector<ll>(limit + 1, 0));
    dp[0][0] = 1;

    for (ll i = 1; i < n + 1; i++)
    {
        for (ll j = 0; j < limit + 1; j++)
        {
            if (j >= i)
                dp[i][j] += dp[i - 1][j - i];
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }
    cout << (dp[n][limit] * power(2, mod - 2)) % mod << endl;
}