#include <bits/stdc++.h>
using namespace std;
// int keyfind(map<string, string> m, string key)
// {
//     if (m.find(key) == m.end())
//         return 0;

//     return 1;
// }

int compare(vector<string> v1, vector<string> v2, map<string, int> numbering)
{
    int counter = 0;
    map<int, int> mapped;
    for (int i = 0; i < v1.size(); i++)
    {
        mapped[numbering[v1[i]]] = 0;
    }
    for (int i = 0; i < v2.size(); i++)
    {
        if (mapped.find(numbering[v2[i]]) != mapped.end())
        {
            mapped[numbering[v2[i]]] = 1;
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
    map<string, vector<string>> word;
    map<string, int> numbering;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        str1 = str.substr(1, str.length());
        string str2 = str.substr(0,1);

        word[str2].push_back(str1);
        numbering[str1] = i;
    }

    for (auto ele1 = word.begin(); ele1 != word.end(); ele1++)
    {
        for (auto ele2 = next(ele1); ele2 != word.end(); ele2++)
        {
            int comp = compare(ele1->second, ele2->second, numbering);
            counter += (((ele1->second).size() - comp) * ((ele2->second).size() - comp)) * 2;
            // cout << "- counter";
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
    // string str = "hello";
    // cout << str.substr(0,1);
    return 0;
}
