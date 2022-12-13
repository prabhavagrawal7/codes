#include <bits/stdc++.h>
using namespace std;

int func()
{
    int n, m;
    cin >> n >> m;
    string arr[n];
    int arr1[m] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr1[j] += (i + 1) * (i + 1) * (i + 1) * (arr[i][j] - '0');
        }
    }

    sort(arr1, arr1 + m);
    if (arr1[0] == arr1[m - 1])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

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
