#include <bits/stdc++.h>
using namespace std;
int prime[1000001] = {0};
void sieve()
{
    int n = 1000001;
    for (int i = 2; i < n + 1; i++)
    {
        prime[i] = 1;
    }

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == 1)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }

    for (int i = 2; i < n; i++)
    {
        prime[i] += prime[i - 1];
    }

}
int func()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if (prime[x] <= y)
    {
        printf("Chef\n");
    }
    else
    {
        printf("Divyam\n");
    }
    return 0;
    
}
int main()
{
    sieve();
    int test;
    cin >> test;
    while (test--)
    {
        func();
    }

    return 0;
}