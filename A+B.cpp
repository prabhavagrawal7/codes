#include <bits/stdc++.h>
using namespace std;

int main()
{

    //write your code from here
    while (true)
    {
        string s, s1;

        cin >> s >> s1;
        if (cin.fail())
        {
            return 0;
        }
        string s2 = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        if (s.length() > s1.length())
        {
            s1 = s2.substr(0, s.length() - s1.length()) + s1;
        }
        if (s.length() < s1.length())
        {
            s = s2.substr(0, s1.length() - s.length()) + s;
        }
        for (int i = s.length() - 1; i >= 0; i--)
        {
            int num = (s[i] - '0') + (s1[i] - '0');
            s[i - 1] += num / 10;
            s[i] = num % 10 + '0';
        }
        cout << s << endl;
    }
    return 0;
}