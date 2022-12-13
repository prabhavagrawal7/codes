#include <bits/stdc++.h>
using namespace std;
long long arr[1000001] = {0, 1, 1};
void fibo_maker()
{
    for (int i = 3; i < 1000001; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
}
void fibo(int n)
{
    cout << arr[n] << endl;
}
int main()
{
    //write your code from here
    int testcases;
    cin >> testcases;
    fibo_maker();
    while (testcases--)
    {
        int n;
        cin >> n;
        fibo(n);
    }
    return 0;
}
