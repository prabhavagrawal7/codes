#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
typedef long long ll;
const ll N = 300005, S = 1e6;
ll n, d[S + 5], a[N], m, bit[N], id[N];
void update(ll id, ll v)
{
    for (; id <= n; id += id & -id)
        bit[id] += v;
}
ll query(ll id)
{
    ll ret = 0;
    for (; id; id -= id & -id)
        ret += bit[id];
    return ret;
}
ll find(ll x) { return id[x] == x ? x : id[x] = find(id[x]); }
int main()
{
    for (int i = 1; i <= S; i++)
        for (int j = i; j <= S; j += i)
            d[j]++;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m; 
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]), id[i] = i, update(i, a[i]);
    id[n + 1] = n + 1;
    for (ll k, l, r; m--;)
    {
        scanf("%lld%lld%lld", &k, &l, &r);
        if (l > r)
            swap(l, r);
        if (k == 2)
            cout << query(r) - query(l - 1) << endl;
        else
            for (ll i = id[l], v; i <= r; i = id[i + 1])
                v = d[a[i]], update(i, v - a[i]), a[i] = v, id[i] = (a[i] <= 2 ? find(i + 1) : id[i]);
    }
    return 0;
}