#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, int> values = {{'A', 1}, {'B', 10}, {'C', 100}, {'D', 1000}, {'E', 10000}};

int calculateRanomValue(string& str) {
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(6, 0));

    // Fill the DP table
    for (int i = n - 1; i >= 0; i--) {
        for (char j = 'A'; j <= 'E'; j++) {
            if (i == n - 1) {
                dp[i][j - 'A'] = (str[i] >= j) ? values[str[i]] : -values[str[i]];
            } else {
                dp[i][j - 'A'] = max(dp[i + 1][j - 'A'], dp[i][j - 'A']);
                dp[i][j - 'A'] = max(dp[i][j - 'A'], dp[i + 1][j - 'A'] + ((str[i] >= j) ? values[str[i]] : -values[str[i]]));
            }
        }
    }

    return dp[0][0];
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        string ranom;
        cout << "Enter the Ranom number: ";
        cin >> ranom;

        int value = calculateRanomValue(ranom);
        cout << "The maximum possible value is: " << value << endl;
    }

    return 0;
}
