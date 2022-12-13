#include <bits/stdc++.h>
using namespace std;

bool checker(string str, int lim)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] - 'a' >= lim)
            return false;
        if (i + 1 < str.size() && str[i] == str[i + 1])
            return false;
        if (i + 2 < str.size() && str[i] == str[i + 2])
            return false;
    }
    return true;
}
string ans(string str, int k)
{
    string newstr = str;
    while (true)
    {
        str[str.size() - 1]++;
        int itr = str.size() - 1;
        while (str[itr] - 'a' == k)
        {
            if (itr - 1 < 0)
                return "NO";
            str[itr] = 'a';
            str[itr - 1]++;
            itr--;
        }
        if(checker(str, k)) {
            return str; 
        }
    }
}

int main()
{
    string str; 
    for(int i = 0; i < strlen(input1); i++)
    {
        str.push_back(input1[i]); 
    }
    cout << ans("cba", 3); 
}