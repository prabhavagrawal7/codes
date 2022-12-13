#include <bits/stdc++.h>
using namespace std;

int func()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a>> b;
        int c = a / (b * b);
        if (c <= 18)
        {
            cout << 1 << endl;
        }
        else if (c <= 24)
        {
            cout << 2 << endl;
        }
        else if (c <= 29)
        {
            cout << 3 << endl;
        }
        else
        {
            cout << 4 << endl;
        }
    }

    return 0;
}
int main()
{
    //write your code from here
    // int testcases;
    // cin >> testcases;
    // while (testcases--)
    // {
    func();
    // }
    // return 0;
}
