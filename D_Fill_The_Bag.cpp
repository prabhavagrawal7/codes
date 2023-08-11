#include <bits/stdc++.h>
using namespace std;
#define ll long long

void func()
{
    ll t, n;
    cin >> t >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];
    ll tsum = accumulate(vec.begin(), vec.end(), 0LL);
    if (tsum < t)
    {
        cout << -1 << endl;
        return;
    }

    map<ll, ll> freq;
    for (auto i : vec)
    {
        freq[i]++;
    }

    ll ans = 0;
    for (ll i = 0; i < 63; i++)
    {
        if ((t >> i) & 1)
        {
            auto x = freq.lower_bound(1 << i)->first;
            while (x != (1 << i))
            {
                freq[x]--;
                if (freq[x] == 0)
                    freq.erase(x);
                freq[x / 2] += 2;
                x = x / 2;
                ans += 1;
            }
            freq[x]--;
            if (freq[1 << i] >= 2)
            {
                freq[1 << (i + 1)] += freq[1 << i] / 2;
            }
        }
        else
        {
            if (freq[1 << i] >= 2)
            {
                freq[1 << (i + 1)] += freq[1 << i] / 2;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        func();
    }
}
