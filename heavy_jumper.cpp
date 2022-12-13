#include <bits/stdc++.h>
using namespace std;

int func()
{
    int n;
    cin >> n;
    int arr2[n];
    set<long> arr1;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr1.insert(num);
    }
    arr1.insert(INT_MAX);
    arr1.insert(INT_MIN);
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < n; i++)
    {
        auto itr = arr1.lower_bound(arr2[i]);
        auto prev_itr = prev(itr);

        if (arr2[i] - *prev_itr <= *itr - arr2[i])
        {
            cout << *prev_itr << " ";
            arr1.erase(*prev_itr);
        }
        else
        {
            cout << *itr << " ";
            arr1.erase(*itr);
        }
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
