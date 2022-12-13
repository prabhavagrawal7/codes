#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

int func()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (str[0] != '1' || str[1] != '1')
    {
        cout << "No" << endl;
        return 0;
    }
    vector<int> myans, storage;
    for (int i = 1; i < n + 1; i++)
    {
        if (str[i] == '1')
        {
            myans.push_back(i - 1);
            while (storage.size())
            {
                myans.push_back(*prev(storage.end()));
                storage.pop_back();
            }
        }
        else
            storage.push_back(i - 1);
    }
    if (storage.size() != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    else
    {
        cout << "Yes" << endl;
        for (int i = 0; i < myans.size(); i++)
            cout << myans[i] << " ";
        cout << endl;
    }
    return 0; 
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }
}
