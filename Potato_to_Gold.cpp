#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        vector<int> save(k);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            vec[i] %= k;
            save[vec[i]]++;
        }
        save[0] = min(save[0], 1);
        if (k % 2 == 0)
        {
            save[k / 2] = min(save[k / 2], 1);
        }

        ll mult = 1;
        for (int i = 0; i < k / 2; i++)
        {
            mult *= save[i] + 1;
        }
    }
}