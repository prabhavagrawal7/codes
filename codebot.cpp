#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;
ll func()
{
    ll n;
    cin >> n;
    map<ll, pair<ll, ll>> store;
    for (ll i = 0; i < n; i++)
    {
        ll m;
        cin >> m;
        if (store.find(m) == store.end())
            store[m] = mp(i, 0);
        else
        {
            ll re = store[m].first;
            store[m] = mp(re, i - re);
        }
    }
    ll sum = 0;
    for (auto i : store)
        sum += i.second.second;

    cout << sum << endl;
    return 0;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        func();
}