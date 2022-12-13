#include <bits/stdc++.h>
using namespace std;

long long func()
{

    long long n, k;
    cin >> n >> k;

    long long point[k];
    for (long long i = 0; i < k; i++)
    {
        cin >> point[i];
    }

    for (long long i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        long long sum = 0;
        for (long long i = 0; i < k; i++)
        {
            if (s[i] == '1')
            {
                sum += point[i];
            }
        }
        cout << sum << endl;
    }

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
