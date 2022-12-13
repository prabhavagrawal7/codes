#include "bits/stdc++.h"
using namespace std;
#define ll int

void func()
{
    ll n, lead_nead, meet_len, timeline;
    cin >> n >> lead_nead >> meet_len >> timeline;
    vector<vector<vector<ll>>> table(n, vector<vector<ll>>(timeline));
    ll m;
    cin >> m;
    for (ll I = 0; I < m; I++)
    {
        ll lead, l, r;
        cin >> lead >> l >> r;
        for (ll i = l; i < r; i++)
            table[lead - 1][i].push_back(I);
    }

    ll ans = INT_MAX;
    for (ll i = 0; i <= timeline - meet_len; i++)
    {
        vector<ll> schedules;
        for (ll k = 0; k < n; k++)
        {
            set<ll> u; 
            for (ll j = i; j < i + meet_len; j++)
            {
                for(auto &meow: table[k][j])
                    u.insert(meow); 
            }
            schedules.push_back(u.size());
        }
        sort(schedules.begin(), schedules.end());
        ans = min(ans,
                  accumulate(schedules.begin(), schedules.begin() + lead_nead, 0));
    }
    cout << ans << endl;
}

int main()
{
    // Uncomment for faster I/O
    // FAST;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << 1 + i << ": ";
        func();
    }
}
