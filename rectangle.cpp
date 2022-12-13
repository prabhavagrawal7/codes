#include <bits/stdc++.h>
#define ll long long
using namespace std;

int func()
{
    ll n, m;
    cin >> n >> m;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pair<int, int> points[4];

    bool checker = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '1')
            {
                points[0].first = i;
                points[0].second = j;
                checker = true;
                break;
            }
        }
        if (checker)
        {
            break;
        }
    }
    checker = false;

    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == '1')
            {
                points[1].first = i;
                points[1].second = j;
                checker = true;
                break;
            }
        }
        if (checker)
        {
            break;
        }
    }
    checker = false;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (arr[i][j] == '1')
            {
                points[2].first = i;
                points[2].second = j;
                checker = true;
                break;
            }
        }
        if (checker)
        {
            break;
        }
    }
    checker = false;

    for (int j = 0; j < m; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i][j] == '1')
            {
                points[3].first = i;
                points[3].second = j;
                checker = true;
                break;
            }
        }
        if (checker)
        {
            break;
        }
    }
    checker = false;

    if (points[0].first != points[1].first || points[1].second != points[2].second || points[2].first != points[3].first || points[3].second != points[0].second)
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j < points[0].second || j >  points[1].second || i < points[0].first || i > points[3].first)
            {
                continue;
            }
            if (arr[i][j] == '0')
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
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
