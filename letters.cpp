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
    ll arr[n + 1] = {0};
    ll letters[m];
    ll sumarr[n + 1] = {0};

    inputarr(arr, n + 1, 1);
    inputarr(letters, m);

    for (int i = 1; i < n + 1; i++)
    {
        sumarr[i] += sumarr[i - 1] + arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        long give;
        int l = 0, r = n, mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (sumarr[mid] == letters[i])
            {
                give = mid;
                break;
            }
            else if (sumarr[mid] < letters[i])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        mid = (l+r)/2;
        if (sumarr[mid] == letters[i])
        {
            cout << mid << " " << letters[i] - sumarr[mid - 1] << endl;
        }
        else
        {
            cout << mid + 1 << " " << letters[i] - sumarr[mid] << endl;
        }
        int index = lower_bound(sumarr, sumarr + n + 1, letters[i]) - sumarr;
        if (sumarr[index] == letters[i])
        {
            cout << index << " " << letters[i] - sumarr[index - 1] << endl;
        }
        else
        {
            cout << index << " " << letters[i] - sumarr[index - 1] << endl;
        }
    }

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
