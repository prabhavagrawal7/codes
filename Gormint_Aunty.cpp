#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

void func()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < k; i++)
    {
        vec[i] = i + 1;
    }
    for (int i = k; i < n; i++)
    {
        vec[i] = vec[i - k];
    }
    if (n % k == 0)
    {
        cout << k << endl;
        for (int i = 0; i < n; i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    else
    {
        cout << k + n % k << endl;
        int count = k + 1;
        for (int i = n - n % k; i < n; i++)
        {
            vec[i] = count;
            count++;
        }
        for (int i = 0; i < n; i++)
            cout << vec[i] << " ";
        cout << endl;
    }
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }
}
