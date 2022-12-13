#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...)                         \
    GET_MACRO(__VA_ARGS__, r4, r3, r2, r1) \
    (__VA_ARGS__)
#define r4(var, start, stop, step) for (auto var = start; start <= stop ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (auto var = start; var != stop; var++)
#define r2(var, stop) for (ll var = 0; var != stop; var++)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 != stop; start_from_0++)
#define newint(...) \
    ll __VA_ARGS__; \
    take_input(__VA_ARGS__)
using namespace std;
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
#define fi first
#define se second
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

ld TLD(ll n) { return TLD(n); }

ll NCR(ll n, ll r)
{

    if (r > n)
        return 0;
    ll m = mod2;
    ll inv[r + 1] = {0};
    inv[0] = 1;
    if (r + 1 >= 2)
        inv[1] = 1;

    // Getting the modular inversion
    // for all the numbers
    // from 2 to r with respect to m
    // here m = 1000000007
    for (ll i = 2; i <= r; i++)
    {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }

    ll ans = 1;

    // for 1/(r!) part
    for (ll i = 2; i <= r; i++)
    {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }

    // for (n)*(n-1)*(n-2)*...*(n-r+1) part
    for (ll i = n; i >= (n - r + 1); i--)
    {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}
ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x) % mod2;

        y = y >> 1;
        x = (x * x) % mod2;
    }
    return res % mod2;
}

ll bruteForce(ll n, ll k)
{
    vi vec(n);

}
ll func(ll n, ll k)
{
    // write your code here
    ll ans = 0;
    range(highestpoints, 1, k + 1)
    {
        range(noofpeoplegettingthat, 2, n + 1)
        {
            ans += (NCR(n, noofpeoplegettingthat) * power(highestpoints - 1, n - noofpeoplegettingthat)) % mod2;
        }
    }
    print(ans);
    return 0;
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    {
        newint(n, k);
        func();
    }
}
