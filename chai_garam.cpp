#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll func()
{
    ll str_len;
    cin >> str_len;
    string str;
    cin >> str;
    map<char, ll> freq1; //maps
    for (ll i = 0; i < str_len; i++)
    {
        char ch = str[i];
        if (freq1.find(ch) == freq1.end())
        {
            freq1[ch] = 1;
            continue;
        }
        freq1[ch] += 1;
    }

    ll queries;
    cin >> queries;

    while (queries--)
    {
        ll l, r;
        cin >> l >> r;
        map<char, ll> freq = freq1;
        ll counter = 0;
        for (ll i = l - 1; i < r; i++)
        {
            for (auto j : freq)
            {
                if (j.first == str[i] || j.second == 0)
                {
                    continue;
                }
                j.second -= 1;
                counter += 1;
                break;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
int main()
{
    //write your code from here
    func();
    return 0;
}
