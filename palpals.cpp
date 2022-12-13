#include <bits/stdc++.h>
#define ll long long
using namespace std;
void inputarr(ll arr[], ll n, ll m = 0)
{
    for (int i = m; i < n; i++)
    {
        cin >> arr[i];
    }
}
int func()
{
    string s;
    map<char, int> alpha;
    cin >> s;
    if(s.length() == 1){
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (alpha.find(s[i]) == alpha.end())
        {
            alpha[s[i]] = 1;
        }
        else
        {
            alpha[s[i]] += 1;
        }
    }
    ll evenstring = 0, oddstring = 0, singlestr = 0;

    for (auto i : alpha)
    {

        if (i.second == 1)
        {
            singlestr += 1;
        }
        else if (i.second % 2 == 0)
        {
            evenstring += i.second;
        }
        else
        {
            oddstring += 1;
        }
        // cout << i.first << "  " << i.second << " ";
    }


    if (evenstring/2 - singlestr >= 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
int main()
{
    //write your code from here
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        func();
    }
    return 0;
}
