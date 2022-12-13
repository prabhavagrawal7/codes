#include <bits/stdc++.h>
using namespace std;

int func()
{
    int n, sum1 = 0, sum2 = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i = i+2)
    {
        sum1 += arr[i];
    }
    for (int j = 1; j < n; j = j+ 2)
    {
        sum2 += arr[j];
    }
    if(sum2 > sum1){
        
    }
    
    
    
    return 0;
}
int main()
{
    //write your code from here
    func();
    return 0;
}
