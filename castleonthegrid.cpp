#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000000

void getPrimes(vector<bool> &prime)
{
    for (int i = 2; i * i <= SIZE; i++)
        if (prime[i])
            for (int j = i * i; j < SIZE; j += i)
                prime[j] = 0;
}


int getVal(int n)
{
    int res;
    for (int i = sqrt(n); i >= 2; i--)
    {
        if (n % i == 0)
        {
            res = (n / i);
            break;
        }
    }
    return res;
}

int solve(int n, int z, vector<bool> &prime, unordered_map<int, int> &m)
{
    int r = INT_MAX;
    int s, t;

    queue<pair<int, int>> q;

    if (m.find(n) != m.end())
        r = m[n];
    else
    {
        q.push(make_pair(n, 0));
        while (!q.empty())
        {

            pair<int, int> p = q.front();
            q.pop();
            n = p.first;
            s = p.second;

            if (!n)
            {
                r = min(r, s);
                break;
            }
            else if (m.find(n) != m.end())
            {
                r = min(r, s + m[n]);
            }
            else
            {

                //Push (n-1) in queue.
                q.push(make_pair(n - 1, 1 + s));

                //If n is not prime insert 'max(a,b)' in queue.
                if (!prime[n])
                {
                    t = getVal(n);
                    q.push(make_pair(t, s + 1));
                }
            }
        }
    }

    return m[z] = r;
}

int main()
{

    vector<bool> prime(SIZE, true);
    getPrimes(prime);

    unordered_map<int, int> map;
    for (int i = 0; i <= 3; i++)
        map[i] = i;

    int queries, n;
    cin >> queries;
    while (queries--)
    {
        cin >> n;
        cout << solve(n, n, prime, map) << endl;
    }
    return 0;
}