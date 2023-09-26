import pyautogui
import time

# Wait for a moment to switch to the text editor
time.sleep(5)

# Code to be typed
code = """
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
ll rec(string &s1, string &s2, ll i, ll j, vvi &dp)
{
    if (i == s1.size() || j == s2.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + rec(s1, s2, i + 1, j + 1, dp);
    return dp[i][j] = max(rec(s1, s2, i + 1, j, dp), rec(s1, s2, i, j + 1, dp));
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    vvi dp(str1.size(), vi(str2.size(), -1));
    cout << (rec(str1, str2, 0, 0, dp));
}

"""

# Split the code into lines
code = code.replace("    ", "")
lines = code.split("\n")

# Iterate through each line and type it
for line in lines:
    pyautogui.write(line, interval=0.1)
    pyautogui.press("enter")

# You can adjust the sleep time between lines if needed
# time.sleep(1)
