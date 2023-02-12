#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        map<char, int> left, right;
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            left[s[i]]++; 
        }
        answer = left.size();
        for(int i = n-1; i >= 0; i--)
        {
            right[s[i]]++; 
            left[s[i]]--; 
            if(left[s[i]] == 0) left.erase(s[i]); 
            answer = max(answer, (int)(left.size() + right.size())); 
        }
        cout << answer << endl;
    }
    return 0;
}