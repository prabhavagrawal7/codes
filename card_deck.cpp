#include <bits/stdc++.h>
using namespace std;

int func()
{
    int n;
    cin >> n;
    vector<int> v;
    vector<int> maxpos;

    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        if (num > largest)
        {
            largest = num;
            maxpos.push_back(v[i]);
        }
    }
    auto k = v.end();
    for (auto i = prev(v.end()); i != prev(v.begin()); i--)
    {

        if (*i == *prev(maxpos.end()))
        {
            for (auto j = i; j != k; j++)
            {
                cout << *j << " ";
            }
            k = i;
            maxpos.pop_back();
        }
    }
    cout << "\n";
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