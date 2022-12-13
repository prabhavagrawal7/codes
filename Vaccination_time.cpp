#include <bits/stdc++.h>
using namespace std;

int main()
{
    //write your code from here
    int m, n, counter = 0;
    int num;
    cin >> m >> n;
    int arr[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        arr[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        arr[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            scanf("%d", &num);
            if (num & 1 != 0)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }
    int arguments;
    int l1, r1, l2, r2, count = 0;
    scanf("%d", &arguments);

    for (int j = 0; j < arguments; j++)
    {
        count = 0;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        for (int i = l1; i <= l2; i++)
        {
            count += arr[i][r2] - arr[i][r1 - 1];
        }
        printf("%d\n", count);
    }
    return 0;
}