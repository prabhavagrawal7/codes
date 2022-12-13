#include <bits/stdc++.h>
using namespace std;

int read(int *p, int k)
{
    int nrt = 0;
    while (k > 0)
    {
        nrt += p[k];
        k -= (k & (-k));
    }
    return nrt;
}

void upd(int *p, int k)
{
    while (k <= 10000000)
    {
        p[k]++;
        k += (k & (-k));
    }
}

int ass(int k, int *p, int exist)
{
    int n = read(p, k);
    upd(p, k);
    return exist - n;
}
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        long count = 0l;
        cin >> n;
        int *p = new int[10000001];
        for (int j = 0; j < 10000001; j++)
        {
            p[j] = 0;
        }

        for (int j = 0; j < n; j++)
        {
            int k = 0;
            cin >> k;
            count += ass(k, p, j);
        }
        cout << count << endl;

        delete[] p;
    }
    return 0;
}