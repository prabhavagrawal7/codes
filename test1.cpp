#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pairsVect;
vector<int> pairOrder;

void generateOrder(int pairIndex)
{
    if (pairIndex == -1)
    {
        return;
    }

    generateOrder(pairsVect[pairIndex].first);
    pairOrder.push_back(pairIndex);

    generateOrder(pairsVect[pairIndex].second);
    return;
}
int solve()
{
    int elementCount;
    cin >> elementCount;

    int numbers[elementCount];
    for (int iter = 0; iter < elementCount; iter++)
    {
        cin >> numbers[iter];
    }

    int pairCount, temp;
    cin >> pairCount >> temp;

    for (int iter = 0; iter < elementCount; iter++)
    {
        pairsVect.push_back({-1, -1});
    }

    int x, y;
    for (int iter = 0; iter < pairCount; iter++)
    {
        cin >> x >> y;
        if (pairsVect[x].first == -1)
        {
            pairsVect[x].first = y;
        }
        else
        {
            pairsVect[x].second = y;
        }
    }

    int elementIndex;
    cin >> elementIndex;

    generateOrder(0);

    int arrIndex = pairOrder[elementIndex - 1];

    return numbers[arrIndex];
}
int main()
{
    cout << solve() << '\n';
}