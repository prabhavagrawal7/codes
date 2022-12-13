#include <bits/stdc++.h>
using namespace std;
#define ll long long

using namespace std;

vector<ll> inputvec(ll n)
{
    vector<ll> vec(n);
    for (ll i = n - 1; i >= 0; i--)
    {
        ll num;
        scanf("%lld", &num);
        *(vec.begin() + i) = num;
    }
    return vec;
}
bool flip(bool m) { return (m ? false : true); }
ll memo[1001][1001][2];
ll func(ll n, ll vec[], ll k, bool mood)
{
    if (k < 0)
    {
        return INT_MIN;
    }
    if (n == 0 && k != 0)
    {
        return INT_MIN;
    }
    else if (n == 0)
    {
        return 0;
    }
    if (memo[n][k][mood] != INT_MAX)
    {
        return memo[n][k][mood];
    }
    ll ans0 = INT_MIN, ans1 = INT_MIN;
    if (vec[n - 1] % 2 == 0)
    {
        ans0 = func(n - 1, vec, k, flip(mood));
        if (mood)
        {
            ans1 = func(n - 1, vec, k - 1, mood);
        }
        else
        {
            ans1 = 1 + func(n - 1, vec, k - 1, mood);
        }
    }
    else
    {
        if (mood)
        {
            ans0 = func(n - 1, vec, k, mood);
        }
        else
        {
            ans0 = 1 + func(n - 1, vec, k, mood);
        }
        ans1 = func(n - 1, vec, k - 1, flip(mood));
    }
    return memo[n][k][mood] = max(ans1, ans0);
}

int main()
{

    ll t;
    // cin >> t;
    scanf("%lld", &t);
    while(t--)
    {
        for (ll i = 0; i <= 1000; i++)
        {
            for (ll j = 0; j <= 1000; j++)
            {
                for (ll k = 0; k < 2; k++)
                {
                    memo[i][j][k] = INT_MAX;
                }
            }
        }
        // new_int_1(n);
        ll n; scanf("%lld", &n);
        // vi vec = inputvec(n);
        ll vec[n];
        for (ll i = n-1; i >= 0; i--)
        {
            scanf("%lld", &vec[i]);
        }
        
        // new_int_1(k);
        ll k; scanf("%lld", &k);
        bool mood = true;
        ll donate = func(n, vec, k, mood);
        mood = false;
        ll donate1 = func(n, vec, k, mood);
        ll ans = max(max(donate, donate1), 0ll);
        // cout << ans << endl;
        printf("%lld", ans);
    }
}