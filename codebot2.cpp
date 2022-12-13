#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    if (s[0] > 3)
        ans = 1;
    else if (s[0] > 6)
        ans = 2;
    cout << pow(2, s.length() - 1) + ans;
}