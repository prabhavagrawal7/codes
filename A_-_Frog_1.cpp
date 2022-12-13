#include "bits/stdc++.h"
using namespace std;
#define ll int64_t

ll func()
{
    ll n; cin >> n; 
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i]; 
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0; 
    for(int i = 0; i < n; i++)
    {
        if (i - 2 >= 0)
            dp[i] = min(dp[i], dp[i - 2] + abs(vec[i] - vec[i - 2]));
        if (i - 1 >= 0)
            dp[i] = min(dp[i], dp[i - 1] + abs(vec[i] - vec[i - 1]));
    }
    return dp[n-1]; 
}
int main()
{
        
    cout << func() << endl;
}