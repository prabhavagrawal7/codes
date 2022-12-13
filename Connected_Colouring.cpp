#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll N = 100005;
ll dp[N][5];
const ll mod = 1e9 + 7;
ll rs(ll n)
{
    return ((n % mod) + mod) % mod;
}
ll solve(ll i, ll state, ll num)
{
    if (i == num + 1)
    {
        if (state == 1)
            return 0;
        else
            return 1;
    }

    if (dp[i][state] != -1)
    {
        return dp[i][state];
    }

    ll ans = 0;
    if (state == 1)
    {
        ans = rs(1 + ((solve(i + 1, 1, num) + solve(i + 1, 2, num)) % mod + solve(i + 1, 3, num)));
    }
    else if (state == 2)
        ans = rs(2 + solve(i + 1, 2, num)); 
    else
        ans = (2 + solve(i + 1, 3, num)) % mod;

    return dp[i][state] = ans;
}

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);  // --> for taking input output from .txt

    // initialise_fact();
    // final_seive();

    ll tt = 1;
    cin >> tt;

    f1(ic, 1, tt)
    {

        ll num;
        cin >> num;

        f1(i, 0, num + 1)
        {
            f0(j, 0, 5)
            {
                dp[i][j] = -1;
            }
        }
        // 1 1
        // 0 1
        // 1 0
        ll ans = (solve(2, 1, num) + solve(2, 2, num)) % mod;
        // + solve(2,3,num))%mod;

        ans = (ans * 2) % mod;

        cout << ans << endl;
    }
    return 0;
}