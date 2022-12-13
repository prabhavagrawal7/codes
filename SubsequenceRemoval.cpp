
#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

ll brute(vector<int> num)
{
    int n = num.size();
    map<int, int> frq;
    for (int i = 0; i < n; i++)
    {
        frq[num[i]]++;
    }

    vector<int> v;
    for (auto it : frq)
    {
        int cnt = it.second - 1;
        while (cnt--)
        {
            v.push_back(it.first);
        }
    }

    int o = 0;
    for (int i = 0; i < n; i++)
    {
        if (o == v.size())
        {
            break;
        }

        if (num[i] == v[o])
        {
            o++;
        }
    }

    if (o == v.size())
    {
        return v.size();
    }
    else
    {
        return -1;
    }
}

ll func(vector<int> vec)
{
    map<ll, vector<int>> store;
    for (int i = 0; i < vec.size(); ++i)
    {
        store[vec[i]].push_back(i);
    }
    ll now = -1;
    ll ans = 0;
    for (auto &i : store)
    {
        auto &arr = i.second;
        if (arr.size() == 1)
        continue;
        ans += arr.size() - 1;
        if (now < arr[0])
        now = arr[arr.size() - 2];
        else if (now < arr[1])
        now = arr.back();
        else return -1;
    }
    return ans;
}

int main()
{
    // compare func with brute
    ll count = 0; // count of test cases
    while (1)
    {
        vector<int> vec;
        int n = rand() % 10000 + 1;
        for (int i = 0; i < n; i++)
        {
            vec.push_back(rand() % 10000 + 1);
        }
        ll bruteAns = brute(vec);
        ll funcAns = func(vec);
        count++;
        if (bruteAns != funcAns)
        {
            cout << "bruteAns = " << bruteAns << " funcAns = " << funcAns << endl;
            cout << "n = " << n << endl;
            for (int i = 0; i < n; i++)
            {
                cout << vec[i] << " ";
            }
            cout << endl;
            break;
        }
        if(count == 1000000)
        {
            cout << "Accepted" << endl;
            break;
        }
    }
}


