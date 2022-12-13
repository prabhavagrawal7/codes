#include <bits/stdc++.h>
using namespace std;
long long divceil(long long p, long long a)
{
    if (p % a == 0)
    {
        return p / a;
    }
    return p / a + 1;
}
long long func()
{
    long long p, a, b, c;
    cin >> p >> a >> b >> c;
    a = divceil(p, a) * a;
    b = divceil(p, b) * b;
    c = divceil(p, c) * c;
    long long arr[3] = {a, b, c};
    cout << *min_element(arr, arr + 3) - p << endl;

    return 0;
}
int main()
{
    //write your code from here
    long long testcases;
    cin >> testcases;
    while (testcases--)
    {
        func();
    }
    return 0;
}
