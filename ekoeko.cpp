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
    ll n, m;
    cin >> n >> m;
    ll arr[n + 1] = {};
    inputarr(arr, n + 1, 1);
    sort(arr, arr + n + 1);
    ll sumarr[n + 1] = {0};
    sumarr[0] = arr[0];
    for (int i = 1; i <= n; i++)
    {
        sumarr[i] += arr[i] + sumarr[i - 1];
    }

    //binary search
    ll l = 0, r = arr[n + 1 - 1], mid, ans;
    ll logs;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll *ub = upper_bound(arr, arr + n + 1, mid);
        logs = sumarr[n + 1 - 1] - sumarr[ub - arr - 1] - (n + 1 - (ub - arr)) * mid;
        if (logs == m)
        {
            ans = mid;
            break;
        }
        else if (logs < m)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        ans = mid;
    }

    // ll *extracaseub = upper_bound(arr, arr + n + 1, ans);
    // ll extracaselogs = sumarr[n + 1 - 1] - sumarr[extracaseub - arr - 1] - (n + 1 - (extracaseub - arr)) * ans;
    // if(extracaselogs > m)

    if (logs < m)
    {
        cout << mid - 1;

        return 0;
    }
    cout << ans;

    return 0;
}
int main()
{
    func();
    return 0;
}