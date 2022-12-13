#include <bits/stdc++.h>
using namespace std;
int keyfind(map<string, string> m, string key)
{
    if (m.find(key) == m.end())
        return 0;

    return 1;
}

int compare(string s1, string s2)
{
    int counter = 0;
    map<char, int> mapped;

    for (int i = 0; i < s1.length(); i++)
    {
        mapped[s1[i]] = 0;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (mapped.find(s2[i]) != mapped.end())
        {
            mapped[s2[i]] = 1;
        }
    }
    for (auto letter : mapped)
    {
        if (letter.second != 0)
            counter += 1;
    }
    return counter;
}

int func()
{
    int n, counter = 0;
    cin >> n;
    string str, str1, str2;
    map<string, string> word;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        str1 = str.substr(1, str.length() - 1);
        if (keyfind(word, str1) == 0)
            word[str1] = str[0];
        else
            word[str1] = word[str1] + str[0];
    }
    for (auto ele1 = word.begin(); ele1 != word.end(); ele1++)
    {
        for (auto ele2 = next(ele1); ele2 != word.end(); ele2++)
        {
            int comp = compare(ele1->second, ele2->second);
            counter += (((ele1->second).length() - comp) * ((ele2->second).length() - comp)) * 2;
        }
    }
    cout << counter << endl;
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