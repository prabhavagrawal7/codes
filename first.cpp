#include <bits/stdc++.h>

using namespace std;

int func()
{
    int n;
    long max = LONG_MIN, min = LONG_MAX;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    cout << 2 * (max - min) << endl;
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
