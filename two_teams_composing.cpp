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
    cin >> ncc;
    ll arr[n];
    inputarr(arr, n);
    map<int, int> frequency;
    for (ll i = 0; i < n; i++)
    {
        if (frequency.find(arr[i]) == frequency.end()){frequency[arr[i]] = 1; continue;} 
        frequency[arr[i]] += 1;
    }
    pair<ll, ll> highestf(0, 0);
    ll allf = 0;

    for (auto i : frequency)
    {
        if (highestf.second <= i.second)
        {
            highestf.first = i.first;
            highestf.second = i.second;
        }
        allf += 1;
    }
    allf -= 1; //adjustment


    if (allf >= highestf.second)
    {
        cout << highestf.second << endl;
    }
    else
    {
        cout << min(allf + 1, highestf.second-1) << endl;
    }

    return 0;
}
int main()
{
    //write your code from here
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        func();
    }
    return 0;
}
