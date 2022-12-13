#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
#define cntpop(x) __builtin__popcount(x)
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...)                         \
    GET_MACRO(__VA_ARGS__, r4, r3, r2, r1) \
    (__VA_ARGS__)
#define r4(var, start, stop, step) for (ll var = start; step >= 0 ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (ll var = start; var < stop; var++)
#define r2(var, stop) for (ll var = 0; var < stop; var++)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 < stop; start_from_0++)
#define newint(...) \
    ll __VA_ARGS__; \
    take_input(__VA_ARGS__)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define give(...)           \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    }
#define endl "\n"
#define FULL_INF numeric_limits<double>::infinity()
#define INF LONG_LONG_MAX
#define INT_INF INT_MAX
#define ll long long
#define ld long double
#define V vector
#define P pair
#define S set
#define MS multiset
#define M map
#define UM unordered_map
#define US unordered_set
#define MM multimap
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define pf push_front
const ll mod = 1000000007;
//const ll mod = 998244353;
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define newstring(str) \
    string str;        \
    cin >> str;
#define foreach(a, x) for (auto &a : x)
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef map<ll, ll> mii;
typedef set<ll> si;
template <typename... T>
void take_input(T &&...args) { ((cin >> args), ...); }
ll input()
{
    newint(n);
    return n;
}
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    for (ll i = start; i < n; i++)
    {
        vec[i] = input();
    }
    return vec;
}
template <typename T>
bool btn(T a, T b, T c)
{
    if ((a <= b && b <= c) || (a >= b && b >= c))
        return true;
    return false;
}
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
template <typename... T>
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
inline ll gcd(ll m, ll n) { return __gcd(m, n); }
inline ll rs(ll n) { return n % mod; }

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

char get_parent(char c, vi &parent)
{
    ll c1 = c - 'a';
    if (parent[c1] == c1)
        return c;
    else
        return parent[c1] = get_parent(parent[c1], parent);
}

bool checkcycles(ll x, UM<ll, US<ll>> &g, vi &visited, vi &st)
{
    st[x] = true, visited[x] = true;
    if (g.count(x))
        foreach (i, g[x])
        {
            if (st[i])
                return true;
            if (!visited[i] && checkcycles(i, g, visited, st))
                return true;
        }
    st[x] = false;
    return false;
}
bool dfs(ll a, ll b, UM<ll, US<ll>> &g, vi &visited)
{
    if (a == b)
        return true;
    visited[a] = true;
    if (g.count(a))
    {
        foreach (i, g[a])
        {
            if (!visited[i] && dfs(i, b, g, visited))
                return true;
        }
    }
    return false;
}

void func()
{
    newint(n);
    V<string> vec;
    range(n)
    {
        newstring(str);
        vec.push_back(str);
    }
    UM<ll, US<ll>> g;
    range(i, 1, n)
    {
        string &s1 = vec[i - 1];
        string &s2 = vec[i];
        ll j = 0;
        for (; j < min(s1.size(), s2.size()); j++)
        {
            if (s1[j] != s2[j])
            {
                g[s2[j] - 'a'].insert(s1[j] - 'a');
                break;
            }
        }
        if(j == min(s1.size(), s2.size()) && s1.size() > s2.size()) {
            give("Impossible");
        } 
    }
    vi visited(26);
    vi st(26);
    range(i, 26)
    {
        if (g.find(i) == g.end())
            continue;
        if (!visited[i] && checkcycles(i, g, visited, st))
        {
            give("Impossible");
        }
    }
    vi ans(26);
    range(i, ans.size()) ans[i] = i;
    while (true)
    {
        bool flag = false;

        range(j, 26)
        {
            range(k, j + 1, 26)
            {
                foreach (i, visited)
                    i = 0;
                if (dfs(ans[j], ans[k], g, visited))
                {
                    swap(ans[j], ans[k]);
                    flag = true;
                }
            }
        }
        if (flag == false)
            break;
    }
    foreach (i, ans)
    {
        char c = i + 'a';
        cout << c;
    }
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    {
        func();
    }
}
