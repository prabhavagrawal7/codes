#define ll long long
#define vvi vector<vector<int>>
#define vi vector<int>
const ll range = 100005;
vi prime(range + 1, 1);
void sieve()
{
    for (int p = 2; p * p <= range; ++p)
    {
        if (prime[p] == 1)
        {
            for (int i = p * p; i <= range; i += p)
                if (prime[i] == 1)
                    prime[i] = p;
        }
    }
}
class Solution
{
public:
    struct store
    {
        ll prime, composite, ans;
        store() : prime(0), composite(0), ans(0) {}
    };
    store dfs(ll n, ll par, vvi &g)
    {
        store ans;
        vector<store> temp;
        for (auto &i : g[n])
        {
            if (i == par)
                continue;
            temp.push_back(dfs(i, n, g));
        }
        for (auto &i : temp)
            ans.ans += i.ans;
        if (prime[n] != 1) // number is composite
        {
            for (auto i : temp)
                ans.composite += i.composite;
            ans.composite++;
            for (auto i : temp)
                ans.prime += i.prime;
            ans.ans += ans.prime; // number of single prime nodes
        }
        else
        {
            for (auto i : temp)
                ans.prime += i.composite;
            ans.prime += 1; 
            ans.ans = ans.prime; // number of single prime nodes
        }
        return ans;
    }
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        sieve();
        prime[1] = 0;
        vvi g(n + 1);
        for (auto &i : edges)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        store ans = dfs(1, 0, g);
        return ans.ans;
    }
};