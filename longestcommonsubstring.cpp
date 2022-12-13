#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define ld long long double
#define FAST ios_base::sync_with_stdio(false);
const ll mod = 1000000007;
const ll mod2 = 998244353;
const double pi = acos(-1);
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    ll n1 = s1.size(), n2 = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    vector<vi> dp(n1 + 1, vi(n2 + 1, 0));
    ll maxi = 0;
    for (ll i = 1; i <= n1; i++)
    {
        for (ll j = 1; j <= n2; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            maxi = max(maxi, dp[i][j]);
        }
    }
    cout << maxi;
}