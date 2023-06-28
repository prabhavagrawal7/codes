#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

void calculateMinRemovals()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> segments(n);
    for (int i = 0; i < n; i++)
    {
        cin >> segments[i].first >> segments[i].second;
    }


    // Create a set of unique coordinates
    set<ll, less<ll>, allocator<ll>> coordinates;
    for (auto segment : segments)
    {
        coordinates.insert(segment.first);
        coordinates.insert(segment.second);
    }

    // Create a coordinate compression map
    map<ll, int> compress;
    int idx = 0;
    for (ll coordinate : coordinates)
    {
        compress[coordinate] = idx++;
    }

    // Create a modified segment list using compressed coordinates
    vector<pair<int, int>> modifiedSegments(n);
    for (int i = 0; i < n; i++)
    {
        modifiedSegments[i] = {compress[segments[i].first], compress[segments[i].second]};
    }

    // Initialize DP table
    vector<int> dp(idx, 0); // dp[i] represents the maximum number of segments that can be included at coordinate i

    // Recursive function for DP
    function<int(int)> rec = [&](int pos)
    {
        if (pos < 0)
        {
            return 0;
        }
        if (dp[pos] != 0)
        {
            return dp[pos];
        }

        int included = 0;
        int excluded = rec(pos - 1);

        for (auto segment : modifiedSegments)
        {
            if (segment.first <= pos && pos <= segment.second)
            {
                included = max(included, rec(segment.first - 1) + 1);
            }
        }

        dp[pos] = max(included, excluded);
        return dp[pos];
    };

    // Calculate the maximum number of segments using recursion
    int maxSegments = rec(idx - 1);

    // Minimum number of removals is the difference between the total number of segments and the maximum number of segments
    int minRemovals = n - maxSegments;

    cout << minRemovals << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        calculateMinRemovals();
    }
    return 0;
}
