#include <bits/stdc++.h>
using namespace std;

int dense(int a, int b)
{
    int counter = 0;
    int c = min(a, b), d = max(a, b);
    while (c * 2 < d)
    {

        c = c * 2;
        counter += 1;
    }

    return counter;
}

int func()
{
    int n, counter = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        counter += dense(arr[i], arr[i - 1]);
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
