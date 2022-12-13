#include <bits/stdc++.h>

using namespace std;

int func()
{
    int x, y, rx_counter = 0, lx_counter = 0, uy_counter = 0, dy_counter = 0;
    cin >> x >> y;
    string str;
    cin >> str;
    int str_len = str.length();
    for (int i = 0; i < str_len; i++)
    {
        if (str[i] == 'R')
        {
            rx_counter += 1;
        }
        else if (str[i] == 'L')
        {
            lx_counter += 1;
        }
        else if (str[i] == 'U')
        {
            uy_counter += 1;
        }
        else
        {
            dy_counter += 1;
        }
    }
    bool a = false, b = false;
    if (x >= 0 && rx_counter >= x)
    {
        a = true;
    }
    if (x < 0 && lx_counter >= abs(x))
    {
        a = true;
    }
    if (y >= 0 && uy_counter >= y)
    {
        b = true;
    }
    if (y < 0 && dy_counter >= abs(y))
    {
        b = true;
    }

    if (a && b)
    {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
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