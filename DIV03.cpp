#include <bits/stdc++.h>
#define ll long long
using namespace std;
void inputarr(ll arr[], ll n, ll m = 0)
{
    for (int i = m; i < n; i++)
    {
        cin >> arr[i];
    }
}
int func()
{
    ll n;
    ll arr[10];
    inputarr(arr, 10);
    cin >> n;
    for (int i = 9; i >= 0; i--)
    {
        if(n >= arr[i]){
            n = n-arr[i];
            arr[i] = 0;
        }
        else
        {
            cout << i+1 << endl;
            return 0;
        }
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
