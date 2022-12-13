#include <bits/stdc++.h>
#define ll long long
using namespace std;
void inputarr(ll arr[], ll n, ll m = 0)
{
    for (int i = m; i < n; i++)
    {
        cin >> arr[i];
    }
}
int func()
{
    ll n;
    ll arr[] = {1, 3, 5, 6, 6, 7, 8, 9};
    ll descarr[] =  {9, 8, 7, 6, 6, 5, 3, 1};
//                  {0, 1, 2, 3, 4, 5, 6, 7}
    ll ans = lower_bound(descarr, descarr + 8, 3+1, greater<ll>()) - descarr;
    cout << ans;
    return 0;
}
int main()
{
    //write your code from here
    // int testcases;
    // cin >> testcases;
    // while (testcases--)
    // {
    func();
    // }
    return 0;
}
