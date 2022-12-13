#include <bits/stdc++.h>
using namespace std;
int func()
{
    int arr_len, hasher[5] = {0}, l_hasher[5] = {0}, operations = 0;
    cin >> arr_len;
    int arr[arr_len + 1] = {0};
    // hasher[1] = 5; hasher[2] = 1; hasher[3] = 2;
    for (int i = 1; i <= arr_len; i++)
    {
        int num;
        cin >> arr[i];
        hasher[arr[i]] = i;
    }
    for (int i = 1; i <= arr_len; i++)
    {
        int num;
        cin >> num;
        l_hasher[arr[i]] = num;
    }
    // cout << "executed";

    for (int i = 1; i < 5; i++)
    {
        if (hasher[i] == 0)
            continue;
        for (int j = i + 1; j <= 5; j++)
        {
            if (hasher[j] == 0)
                continue;
            while (hasher[i] >= hasher[j])
            {
                hasher[j] += l_hasher[j];
                operations++;
            }
        }
    }
    cout << operations << endl;
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