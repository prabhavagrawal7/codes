#include <bits/stdc++.h>
using namespace std;
void func()
{
    int n, k;
    cin >> n >> k;
    if (k > n)
    {
        int buffer = k / n;
        buffer = buffer % (n - 1);
        cout << n - buffer << endl;
    }
    else
    {
        if (n % 2 == 0)
        {
            if (k >= n / 2)
            {
                cout << n - k - 1 << endl;
            }
            else
            {
                cout << n - k << endl;
            }
        }
        else
        {
            if (k > n / 2)
            {
                cout << n - k - 1 << endl;
            }
            else
            {
                cout << n - k << endl;
            }
        }
    }
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
