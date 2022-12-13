#include <bits/stdc++.h>
using namespace std;

string Encircular(string str)
{
    int n = str.size();
    vector<vector<int>> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int d = 0;
    vector<int> coordinate = {0, 0};
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == 'L')
            d--;
        else if (str[i] == 'R')
            d++;
        else
        {
            d = (d % 4 + 4) % 4;
            coordinate[0] += dirs[d][0];
            coordinate[1] += dirs[d][1];
        }
    }
    if (d % 4 != 0 || coordinate == vector<int>{0, 0})
        return "YES";
    else
        return "NO";
}
string doesCircleExist(string j)
{
    int x = 0, y = 0;
    char l = 'N';
    for (auto i : j)
    {
        if (i == 'G')
        {
            if (l == 'N')
                y++;
            else if (l == 'E')
                x++;
            else if (l == 'S')
                y--;
            else
                x--;
        }
        else if (i == 'L')
        {
            if (l == 'N')
                l = 'W';
            else if (l == 'E')
                l = 'N';
            else if (l == 'S')
                l = 'E';
            else
                l = 'S';
        }
        else
        {
            if (l == 'N')
                l = 'E';
            else if (l == 'E')
                l = 'S';
            else if (l == 'S')
                l = 'W';
            else
                l = 'N';
        }
    }
    string anss;
    if (x == 0 && y == 0 || l != 'N')
        anss = "YES";
    else
        anss = "NO";
    return anss;
}
int main()
{
    // create a counter too
    int counter = 0;
    while (1)
    {
        // create a random string that contains only L, R, G
        string str;
        int n = rand() % 1000 + 1;
        for (int i = 0; i < n; ++i)
        {
            int x = rand() % 3;
            if (x == 0)
                str += 'L';
            else if (x == 1)
                str += 'R';
            else
                str += 'G';
        }
        // compare both functions
        string ans1 = Encircular(str);
        string ans2 = doesCircleExist(str);
        if (ans1 != ans2)
        {
            cout << "Wrong Answer" << endl;
            cout << "Input: " << str << endl;
            cout << "Expected Output: " << ans1 << endl;
            cout << "Your Output: " << ans2 << endl;
            break;
        }
        else
            counter++;
        if (counter == 1000000)
        {
            cout << "Accepted" << endl;
            break;
        }
    }
}

// g++ -std=c++17 -Ofast Encircular.cpp -o Encircular && ./Encircular