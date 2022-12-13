#include <bits/stdc++.h>
using namespace std;

int func()
{
    int a, b, k;
    cin >> a >> b >> k;
    if (k - (b - 1) < a)
    {
        cout << "Yes\n";
        for (int i = 0; i < b; i++)
        {
            cout << "1";
        }
        for (int i = 0; i < a; i++)
        {
            cout << "0";
        }
        cout << "\n";
        // part 1

        // part 2
        for (int i = 0; i < b - 1; i++)
        {
            cout << "1";
        }
        for (int i = 0; i < k; i++)
        {
            cout << "0";
        }
        cout << "1";
        for (int i = 0; i < (a + b) - k - (b - 1) - 1; i++)
        {
            cout << "0";
        }
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}
int main()
{
    func();
    return 0;
}
