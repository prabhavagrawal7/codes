
#include <bits/stdc++.h>
using namespace std;

int func()
{

    int n, counter = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > arr[0])
        {
            counter += 1;
            
        }
        else
        {
            break;
        }
    }
    cout << counter << endl;

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
