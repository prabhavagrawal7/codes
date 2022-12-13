#include <bits/stdc++.h>
using namespace std;
int func1(int a, int b, int c, int n)
{
    n = n/3;
    int counter = 0;
    if(a > n){
        b += a-n;
        counter += a-n;
        a = n;
    }
    if(b > n){
        c += b-n;
        counter += b-n;
        b = n;
    }
    if(c > n){
        a += c-n;
        counter += c-n;
        c = n;
    }
    if(a > n){
        b += a-n;
        counter += a-n;
        a = n;
    }
    if(b > n){
        c += b-n;
        counter += b-n;
        b = n;
    }
    cout << counter << endl;
    return 0;
}
int func()
{
    int n, a = 0, b = 0, c = 0, counter = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num % 3 == 0)
        {
            a += 1;
        }
        else if (num % 3 == 1)
        {
            b += 1;
        }
        else
        {
            c += 1;
        }
    }
    func1(a, b, c, n);
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
