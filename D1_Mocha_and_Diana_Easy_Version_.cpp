#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...)                         \
    GET_MACRO(__VA_ARGS__, r4, r3, r2, r1) \
    (__VA_ARGS__)
#define r4(var, start, stop, step) for (auto var = start; step >= 0 ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (auto var = start; var != stop; var++)
#define r2(var, stop) for (ll var = 0; var != stop; var++)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 != stop; start_from_0++)
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
#define S string
#define MS multiset
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

UM<ll, ll> p1, p2;
ll get_parent1(ll x)
{
    if (p1[x] == x)
        return x;
    else
        return p1[x] = get_parent1(p1[x]);
}
ll get_parent2(ll x)
{
    if (p2[x] == x)
        return x;
    else
        return p2[x] = get_parent2(p2[x]);
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    V<pii> ans;
    newint(n, j1, j2);
    range(i, 1, n+1)
    {
        p1[i] = i;
        p2[i] = i;
    }
    range(j1)
    {
        newint(a, b);
        ll u = get_parent1(a);
        ll v = get_parent1(b);
        p1[u] = v;
    }
    range(j2)
    {
        newint(a, b);
        ll u = get_parent2(a);
        ll v = get_parent2(b);
        p2[u] = v;
    }

    range(i, 1, n+1)
    {
        range(j, i + 1, n+1)
        {
            ll p1a = get_parent1(i);
            ll p1b = get_parent1(j);

            ll p2a = get_parent2(i);
            ll p2b = get_parent2(j);
            if (p1a != p1b && p2a != p2b)
            {
                p1[p1a] = p1b;
                p2[p2a] = p2b;
                ans.push_back(mp(i, j));
            }
        }
    }
    print(ans.size());
    for (auto i : ans)
        print(i.first, i.second);
}
