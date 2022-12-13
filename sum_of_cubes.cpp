#include <bits/stdc++.h>
using namespace std;
long long arr[10002];
void arr_maker()
{
    for (long long i = 0; i < 10002; i++)
    {
        arr[i] = i * i * i;
    }
}
void arr_maker();
long func()
{
    long long n, counter = 0, mid;
    cin >> n;
    for (long long i = 1; i < 10002; i++)
    {
        if(*upper_bound(arr, arr+10002, n-arr[i]) != arr[10001]){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}
int main()
{
    //write your code from here
    long long testcases;
    cin >> testcases;
    arr_maker();
    while (testcases--)
    {
        func();
    }
}
