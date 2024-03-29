#include "bits/stdc++.h"
using namespace std;

string func(string str)
{
    vector<int> freq(26, 0);
    for (char c : str)
    {
        freq[c - 'a']++;
    }
    int n = str.size();
    for (int i = 0; i < 26; i++)
    {
        for (int j = 25; j >= 0; j--)
        {
            if (freq[i] % 2 != 0 && freq[j] % 2 != 0)
            {
                freq[i]++;
                freq[j]--;
            }
        }
    }
    string ans;
    for (int i = 0; i < 26; i++)
    {
        ans += string(freq[i] / 2, i + 'a');
    }
    string rev = ans;
    reverse(rev.begin(), rev.end());
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 != 0)
        {
            ans += string(1, i + 'a');
            break;
        }
    }
    return ans + rev;
}
int main()
{
    string str;
    cin >> str;
    cout << func(str) << endl;
    return 0;
}
