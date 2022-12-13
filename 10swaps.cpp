#include <iostream>
#include <string>
using namespace std;
int answer(string s, string p)
{
    int zero_s = 0, zero_p = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            zero_s += 1;
        }
        if (s[i] == '0')
        {
            zero_p += 1;
        }
    }
    if (zero_s == zero_p)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    //write your code from here
    int test_case, length;
    string s, p;
    cin >> test_case;
    while (test_case > 0)
    {
        cin >> length;
        cin >> s;
        cin >> p;
        if (answer(s, p) == 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No";
        }
    }

    return 0;
}