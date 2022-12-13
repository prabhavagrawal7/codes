#include <bits/stdc++.h>
using namespace std;

int func()
{
    int n;
    cin >> n;
    int arr[n], copyarr[n];
    map<int, int> index;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
        copyarr[i] = num;
    }
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (index.find(arr[i]) == index.end())
        {
            index[arr[i]] = i+1 ;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << index[copyarr[i]] << " ";
        index[copyarr[i]] += 1;
    }
    cout << "\n";
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
