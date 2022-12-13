#include <bits/stdc++.h>

using namespace std;

int func()
{
    string n;
    cin >> n;
    for (int i = 0; i < n.length(); i += 2)
    {

        if (n[i] == 'a')
        {
            n[i] = 'b';
        }
        else
        {
            n[i] = 'a';
        }
    }
    for (int i = 1; i < n.length(); i += 2)
    {
        if (n[i] == 'z')
        {
            n[i] = 'y';
        }
        else
        {
            n[i] = 'z';
        }
    }

    cout << n << "\n";
    return 0;
}

int main()
{
    //write your code from here
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        func();
    }

    return 0;
}