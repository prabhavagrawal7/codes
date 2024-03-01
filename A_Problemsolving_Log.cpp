// t = int(input())

// for _ in range(t):
//     n = int(input())
//     s = input()
//     solved_problems = sum(ord(char) - ord('A') + 1 for char in s)
//     print(solved_problems)

// converted to c++
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s; 
        int solved_problems = 0;
        for (auto ch : s)
        {
            solved_problems += ch - 'A' + 1;
        }
        cout << solved_problems << endl;
    }
}
