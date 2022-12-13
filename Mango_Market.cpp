#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    vec.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    int ans = -n * (n - 1) / 2;
    for (auto i : vec)
        ans += i;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        ans += 2;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '-' || c == '+')
        {
            int a, b;
            cin >> a >> b;
        }
        if (c == '-')
            ans -= 2;
        else if (c == '+')
            ans += 2;
        else
            cout << ans << endl;
    }
}
