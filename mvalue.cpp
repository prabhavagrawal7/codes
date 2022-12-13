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
    cin >> n;
    ll arr[n];
    inputarr(arr, n);
    ll large = INT_MIN, slarge = INT_MIN, small = INT_MAX, ssmall = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] >= large){
            slarge = large;
            large = arr[i];
        }
        else if(arr[i] >= slarge){
            slarge = arr[i];
        }

        if(arr[i] <= small){
            ssmall = small;
            small = arr[i];
        }
        else if(arr[i] <= ssmall){
            ssmall = arr[i];
        }   
    }
    
    cout << max(large*slarge + large-slarge, small*ssmall + ssmall - small) << endl;
    
    
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
