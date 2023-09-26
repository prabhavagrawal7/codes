#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int count(vector<string> arr)
{
    vector<int> mp(26);
    multiset<int> st;
    for (auto &it : arr)
    {
        if (it.size() % 2 == 0)
            st.insert((ll)it.size());
        else
            st.insert((ll)it.size() - 1);
        for (auto &i : it)
            mp[i - 'a']++;
    }
    int cnt = 0;
    for (auto &it : mp)
    {
        if (it % 2 == 0)
            cnt += it;
        else
            cnt += (it - 1);
    }
    int ans = 0, sum = 0;
    for (auto &it : st)
    {
        sum += it;
        if (sum <= cnt)
            ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (auto &it : arr)
        cin >> it;
    cout << count(arr) << endl;
    return 0;
}