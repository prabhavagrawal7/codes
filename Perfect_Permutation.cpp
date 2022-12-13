#include <bits/stdc++.h>
using namespace std; 
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

int func()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    k = n - k;

    for (int i = 0; i < n; i++)
    {
        vec[i] = i + 1;
    }
    for (int i = n - 1; i >= 0 && k >= 2; i -= 2)
    {
        swap(vec[i], vec[i - 1]);
        k -= 2;
    }
    if (k)
        swap(vec[0], vec[1]);
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0; 
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    int t; cin >> t; 
    while(t--)
    {
        func();
    }
}
