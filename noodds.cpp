#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
using namespace std;
ll binarysqrt(ll n)
{
    ll l = 0, r = n, mid;
    if(r > 1000000000)
    {
        r = 1000000000;
    }
    while(l <= r)
    {
        mid = (l+r)/2;
        ll ans = mid*mid;
        if(ans == n)
        {
            return mid;
        }
        else if(ans > n)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    while((mid)*(mid) > n)
        mid = mid - 1;
    while((mid+1)*(mid+1) < n)
        mid = mid + 1;
    return mid;
}

ll func()
{
    ll n;
    scanf("%lld", &n);
    ll squareroot = binarysqrt(n);
    // cout << "Squareroot:- " << squareroot << endl;
    printf("%lld\n", n - squareroot);
    return 0;
}
int main()
{
    ll t;
    scanf("%lld", &t);
    while(t--)
    {
        func();
    }
}