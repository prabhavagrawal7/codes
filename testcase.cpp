c#include "bits/stdc++.h"
using namespace std;
#define ll int64_t

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define INF 1000000
ll rec(ll n, vector<vector<ll>> &pref,
       vector<vector<ll>> &rpref, vector<ll> &dp)
{
    if (n == pref.size())
        return 0;
    if (dp[n] != -1)
        return dp[n];
    ll ans = 0;
    for (int i = 1; i < pref.size() - n + 1; i++)
    {
        ll tempans = rec(n + i, pref, rpref, dp) +
                     max(pref[n][i], rpref[n][i]);
        ans = max(ans, tempans);
    }
    dp[n] = ans;
    return ans;
}
ll func(ll n, vector<ll> a, vector<ll> b)
{
    // start and size
    vector<vector<ll>> rpref(n, vector<ll>(n + 1));
    vector<vector<ll>> pref(n, vector<ll>(n + 1));
    for (int i = 0; i < n; i++)
    {
        rpref[i][1] = a[i] * b[i];
        pref[i][1] = a[i] * b[i];
        if (i + 1 < n)
        {
            rpref[i][2] = a[i] * b[i + 1] + b[i] * a[i + 1];
            pref[i][2] = a[i] * b[i] + a[i + 1] * b[i + 1];
        }
    }

    for (int s = 3; s < n + 1; s++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i + s - 1 >= n)
                break;
            rpref[i][s] = rpref[i + 1][s - 2];
            rpref[i][s] += a[i] * b[i + s - 1] + b[i] * a[i + s - 1];

            pref[i][s] = pref[i + 1][s - 2];
            pref[i][s] += a[i] * b[i] + b[i + s - 1] * a[i + s - 1];
        }
    }
    vector<ll> dp(n + 1, -1);
    return rec(0, pref, rpref, dp);
}
int main()
{
    srand(time(0));
    // freopen("input02.txt", "w", stdout);

    freopen("input02.txt", "r", stdin);
    freopen("output02.txt", "w", stdout);
    ll n; cin >> n; 
    vector<ll> a(n), b(n);
    for(int i = 0; i < n ; i++) cin >> a[i]; 
    for(int i = 0; i < n ; i++) cin >> b[i]; 
    // for (int i = 0; i < n; i++)
    // {
    //     ll x = rand() % INF;
    //     cout << x << " ";
    //     a.push_back(x);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     ll x = rand() % INF;
    //     cout << x << " ";
    //     b.push_back(x);
    // }
    
    cout << (func(n, a, b)) << endl;
}
