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
ll onecount = 0;
void func1(ll arr[], ll n, ll num) //the flipper fuction
{
    if (arr[num - 1] == 0)
    {
        arr[num - 1] = 1;
        onecount += 1;
    }
    else
    {
        arr[num - 1] = 0;
        onecount -= 1;
    }
}

void func2(ll arr[], ll n, ll num) //largest function
{
    if (onecount >= num)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
int func()
{
    ll n, m;
    cin >> n >> m;
    ll arr[n];
    inputarr(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            onecount += 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int num, num1;
        cin >> num >> num1;
        if(num == 1){
            func1(arr, n, num1);
        }
        else{
            func2(arr, n, num1);
        }
    }
    


    return 0;
}
int main()
{
    //write your code from here
    func();
    return 0;
}
