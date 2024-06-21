#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
const ll mod = 1000000007;
// const ll mod = 998244353;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;

#define object(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) object(__VA_ARGS__, range4, range3, range2, range1)(__VA_ARGS__)
#define range4(var, start, stop, step) for (ll var = start; step >= 0 ? var < stop : var > stop; var = var + step)
#define range2(var, end) for (ll var = 0; var < end; var++)
#define range1(stop) for (ll start_from_0 = 0; start_from_0 < stop; start_from_0++)

#define newinput(...) \
    ll __VA_ARGS__;   \
    take_input(__VA_ARGS__)

#define gvr(...)            \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    }
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define V vector
#define all(a) a.begin(), a.end()
#define newstr(str) \
    string str;     \
    cin >> str;
#define foreach(a, x) for (auto &a : x)

typedef pair<ll, ll> pii;
typedef vector<ll> vr;
typedef vector<vector<ll>> vvr;

template <typename... T>
void take_input(T &&...args) { ((cin >> args), ...); }
template <typename T>
ostream &operator<<(ostream &os, const V<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}
template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
template <typename... T>
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printline(T &&...args) { ((cout << args << " "), ...); }
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T>;

vr inputvector(ll n, ll start = 0)
{
    vr vec(n);
    range(i, start, n, 1) cin >> vec[i];
    return vec;
}
char chart(ll a) { return char(a + 'a'); }
ll intt(char a) { return (a - 'a'); }
ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
}
ll lcm(ll x, ll y)
{
    ll res = x;
    res = res / (gcd(x, y));
    res *= y;
    return res;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

// ordered set

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

void compress(vr &a, vr &b)
{

    vr c = a;
    c.insert(c.end(), b.begin(), b.end());

    sort(c.begin(), c.end());

    c.erase(unique(c.begin(), c.end()), c.end());
    map<int, int> m;

    for (int i = 0; i < c.size(); i++)
        m[c[i]] = i;

    for (int i = 0; i < a.size(); i++)
        a[i] = m[a[i]];
    for (int i = 0; i < b.size(); i++)
        b[i] = m[b[i]];
}
void func()
{
    newinput(n, m, k);
    vr vec = inputvector(n);
    vr mvec = inputvector(m);

    map<ll, pair<ll, ll>> store;
    for (int i = 0; i < m; i++)
    {
        ll val = mvec[i];
        store[val].first++; // capacity
    }

    ll count = 0;
    for (int i = 0; i < m; i++)
    {
        ll val = vec[i];
        if (store.count(val))
        {
            store[val].second++;
            if (store[val].second <= store[val].first)
                count++;
        }
    }

    ll ans = count >= k ? 1 : 0;
    for (int i = m; i < n; i++)
    {
        ll prev = i - m;
        if (store.count(vec[prev]))
        {
            store[vec[prev]].second--;
            if (store[vec[prev]].second < store[vec[prev]].first)
                count--;
        }
        if (store.count(vec[i]))
        {
            store[vec[i]].second++;
            if (store[vec[i]].second <= store[vec[i]].first)
                count++;
        }
        ans += count >= k ? 1 : 0;
    }

    gvr(ans);
}
int main()
{
    FAST;
    newinput(t);
    range(t)
    {
        func();
    }
}
