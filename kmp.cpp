#include "bits/stdc++.h"
using namespace std;
#define ll int64_t
// lps/longest prefix suffix
vector<ll> get_lps(string s)
{
    vector<ll> lps(s.size(), -1);
    ll lptr = -1, rptr = 0;
    while (true)
    {
        if (rptr + 1 == s.size())
            break;
        if (s[lptr + 1] == s[rptr + 1])
        {
            lps[rptr + 1] = lptr + 1;
            lptr++;
            rptr++;
        }
        else if (lptr != -1 && s[lptr + 1] != s[rptr + 1])
            lptr = lps[lptr];
        else
        {
            lps[rptr + 1] = -1;
            rptr++;
        }
    }
    return lps;
}
// string matching algo, requires lps table
bool match(string bigstr, string smallstr)
{
    if (smallstr.size() > bigstr.size())
        return 0;
    ll i = -1, j = -1;
    ll n = bigstr.size(), m = smallstr.size();
    vector<ll> lps = get_lps(smallstr);
    while (i + 1 < n && j + 1 < m)
    {
        if (bigstr[i + 1] == smallstr[j + 1])
            i++, j++;
        else if (j != -1 && bigstr[i + 1] != smallstr[j + 1])
            j = lps[j];
        else
            i++;
    }
    return j == m - 1;
}

string random_string(size_t length)
{
    string charset = "abcdefghijklmnopqrstuvwxyz";
    auto randchar = [charset]() -> char
    {
        return charset[rand() % charset.size()];
    };
    string str(length, 0);
    for (ll i = 0; i < str.size(); i++)
    {
        str[i] = randchar();
    }
    return str;
}

int main()
{
    while (true)
    {
        string bigstr = random_string(100);
        string smallstr = random_string(50);
        bool x = match(bigstr, smallstr);
        if (x != (bigstr.find(smallstr) != string::npos))
        {
            cout << x << endl;
            cout << bigstr << endl;
            cout << smallstr << endl;
            return 0;
        }
    }
}