#include <bits/stdc++.h>
using namespace std;

int func(int l, int r)
{
    if (l == r)
    {
        return l;
    }
    int num1, num2;
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    cin >> num1;
    if (num1 == l)
    {
        return func(l + 1, r);
    }
    else if (num1 == r)
    {
        return func(l, r - 1);
    }
    else
    {
        cout << "? " << l << " " << num1 << "\n";
        cout.flush();
        cin >> num2;
        if (num2 == num1)
        {
            return func(l, num1 - 1);
        }
        else
        {
            return func(num1 + 1, r);
        }
    }
    return 0;
}
int main()
{
    //write your code from here
    int n;
    cin >> n;
    int ans = func(1, n);
    cout << "! " << ans;
    return 0;
}
