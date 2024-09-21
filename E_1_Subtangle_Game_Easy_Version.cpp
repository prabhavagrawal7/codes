#include "bits/stdc++.h"
using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, n, m;
        cin >> l >> n >> m;
        vector<int> a(l);
        for (int i = 0; i < l; ++i)
        {
            cin >> a[i];
        }
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> b[i][j];
            }
        }

        SubtangleGameE_2 game(l, n, m, a, b);
        game.solve();
    }
    return 0;
}
