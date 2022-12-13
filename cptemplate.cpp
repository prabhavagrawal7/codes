#include <bits/stdc++.h>
using namespace std;
#define ll long long

int func()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        if (pos.find(vec[i]) == pos.end())
            pos[vec[i]].push_back(0);
        pos[vec[i]].push_back(i + 1);
    }
    ll ans = 0, num;
    for (auto &i : pos)
    {
        num = i.first;
        i.second.push_back(vec.size() + 1);
        int l = 1, r = num;
        while (i.second.size() > r + 1)
        {
            ans += (i.second[l] - i.second[l - 1]) * (i.second[r + 1] - i.second[r]) * (num);
            ++l;
            ++r;
        }
    }
    cout << ans << endl;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        func();
}
