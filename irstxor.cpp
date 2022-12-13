#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll func()
{
    ll n, m;
    cin >> n;
    m = n;
    ll ans = 0;
    ll i = 1;
    while (m)
    {
        ans = ans * 2;
        if (m % 2 == 0)
        {
            ans = ans + 1;
        }
        else
        {
            ans = ans + (i % 2);
            ++i;
        }
        m = m / 2;
    }
    cout << ans << endl;
    //reverser
    m = ans;
    ll nans = 0;
    while (ans)
    {
        nans = nans * 2;
        nans = nans+  ans %2;
        ans = ans/2;
    }
    // cout << (n^nans)*(nans);
    cout << nans;

    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }
}