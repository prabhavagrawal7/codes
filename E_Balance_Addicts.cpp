#include <bits/stdc++.h>
using namespace std;
char *join(char *s1, char *s2, int k)
{
    char *ans = new char[k];
    for (int i = 0; i < k; i++)
    {
        if (s1[i] == '1' || s2[i] == '1')
            ans[i] = '1';
        else
            ans[i] = '0';
    }
    return ans;
}
int rec(int n, int k, char *s, char *str[], int cost[])
{
    if (n == -1)
    {
        bool u = true;
        for (int i = 0; i < k; i++)
        {
            if (s[i] != '1')
            {
                u = false;
                break;
            }
        }
        if (u == true)
            return 0;
        else
            return -1;
    }
    else
    {
        int ans1 = rec(n - 1, k, join(str[n], s, k), str, cost);
        int ans2 = rec(n - 1, k, s, str, cost);
        if (ans1 == -1 && ans2 == -1)
            return -1;
        else if (ans1 == -1 && ans2 != -1)
            return ans2;
        else if (ans2 == -1 && ans1 != -1)
            return ans1 + cost[n];
        else
            return min(ans1 + cost[n], ans2);
    }
}

int buyCandies(int n, char *str[], int cost[], int k)
{
    char *s = new char[k];
    for (int i = 0; i < k; i++)
        s[i] = '0';
    return rec(n-1, k, s, str, cost);
}

int main()
{
    char *str[] = {"1010", "0100", "0001", "1111", "1011"};
    int cost[] = {5, 5, 5, 10, 2};
    cout << (buyCandies(5, str, cost, 4)); 
}