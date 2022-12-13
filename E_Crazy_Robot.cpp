#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
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
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define new_string(str) \
    string str;         \
    cin >> str;
const ll mod = 1000000007;
const ll mod2 = 998244353;
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
template <typename... T, typename Q>
Q max(Q arg1, T &&...args)
{
    Q ans = arg1;
    ((ans = (args > ans ? args : ans)), ...);
    return ans;
}
template <typename... T, typename Q>
Q min(Q arg1, T &&...args)
{
    Q ans = arg1;
    ((ans = (args < ans ? args : ans)), ...);
    return ans;
}
ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n)
{
    while (__n != 0)
    {
        ll __t = __m % __n;
        __m = __n;
        __n = __t;
    }
    return __m;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

V<pii> vals(pii a)
{
    pii aup = a, adown = a, aleft = a, aright = a;
    aup.first++;
    adown.first--;
    aleft.second--;
    aright.second++;
    V<pii> ans = {aup, adown, aleft, aright};
    return ans;
}

ll func()
{
    // write your code here
    newint(n, m);
    V<V<char>> g(n + 2, V<char>(m + 2));
    V<V<bool>> vstd(n + 2, V<bool>(m + 2, 0));
    V<V<bool>> walls(n + 2, V<bool>(m + 2, 0));
    pii lpos;
    range(i, 1, n + 1)
    {
        range(j, 1, m + 1)
        {
            cin >> g[i][j];
        }
    }
    range(i, 0, n + 2)
    {
        range(j, 0, m + 2)
        {
            if ('L' == g[i][j])
                lpos.first = i, lpos.second = j;
            if ('#' == g[i][j] || i == 0 || i == n + 1 || j == 0 || j == m + 1)
                walls[i][j] = 1;
        }
    }
    stack<pii> dfs;
    dfs.push(lpos);
    while (dfs.size())
    {
        auto x = dfs.top();
        dfs.pop();
        vstd[x.first][x.second] = true;
        auto nitr = vals(x);
        for (auto i : nitr)
        {
            if (walls[i.first][i.second] || vstd[i.first][i.second])
                continue;
            ll u = 0;
            ll v = 0;
            if (walls[i.first + 1][i.second])
                u++;
            if (vstd[i.first + 1][i.second])
                v++;

            if (walls[i.first - 1][i.second])
                u++;
            if (vstd[i.first - 1][i.second])
                v++;

            if (walls[i.first][i.second + 1])
                u++;
            if (vstd[i.first][i.second + 1])
                v++;

            if (walls[i.first][i.second - 1])
                u++;
            if (vstd[i.first][i.second - 1])
                v++;

            if (v > 0 && u + v >= 3)
            {
                dfs.push(i);
            }
        }
    }
    range(i, 1, n + 1)
    {
        range(j, 1, m + 1)
        {
            if (vstd[i][j] && g[i][j] != 'L')
            {
                g[i][j] = '+';
            }
            cout << g[i][j];
        }
        cout << '\n';
    }
    return 0;
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
