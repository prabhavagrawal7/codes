#include <bits/stdc++.h>
#define ll long long
using namespace std;
void inputarr(ll arr[], ll n, ll m = 0)
{
    for (int i = m; i < n; i++)
    {
        cin >> arr[i];
    }
}
bool checker(string s)
{
    ll counter = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            counter += 1;
        }
        else
        {
            counter -= 1;
        }
        if (counter < 0)
        {
            return false;
        }
    }
    if(counter != 0){
        return false;
    }
    return true;
}

int func()
{
    string str;
    string str1 = "", str2 = "";
    cin >> str;
    if(str[0] == str[str.length()-1]){
        cout << "NO" << endl;
        return 0;
    }
    char A = str[0];
    char B = str[str.length()-1];
    
    for (ll i = 0; i < str.length(); i++)
    {
        if (str[i] == A)
        {
            str1 += '(';
            str2 += '(';
        }
        else if (str[i] == B)
        {
            str1 += ')';
            str2 += ')';
        }
        else
        {
            str1 += ')';
            str2 += '(';
        }
    }
    if (checker(str1) || checker(str2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

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
