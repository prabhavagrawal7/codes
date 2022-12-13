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
//      sieve starts here |sieve modified to provide smallest factors of a number|
const ll range = 1000006;
vi prime(range + 1, 0);
void sieveOfEratosthenes()
{
    for (int p = 2; p * p <= range; p++)
    {
        if (prime[p] == false)
        {
            for (int i = p * p; i <= range; i += p)
                if (!prime[i])
                    prime[i] = i / p;
        }
    }
}

ll func()
{
    // write your code here
    newint(n, k);
    vi vec = inputvec(n);
    vi visited(n, 0);
    ll ans = 0;
    range(i, n)
    {
        if (prime[vec[i]] != 0 || visited[i] == true)
            continue;
        vi pms;
        ll end = 0;
        for (ll j = i; j < n; j += k)
        {
            if (prime[vec[j]] != 0)
            {
                break;
            }
            else
            {
                end = j;
                if (vec[j] != 1)
                    pms.push_back(j);
                visited[j] = true;
            }
        }
        if (pms.size())
        {
            ll ps = pms.size();
            for (ll j = 0; j < ps; j++)
            {
                ll left = 1, right = 1;
                if (j - 1 >= 0)
                    left = (pms[j] - pms[j - 1]) / k;
                else
                    left = (pms[j] - i) / k + 1;

                if (j + 1 < ps)
                    right = (pms[j + 1] - pms[j]) / k;
                else
                    right = (end - pms[j]) / k + 1;
                ans += left * right - 1;
            }
        }
    }
    print(ans);
    return 0;
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    sieveOfEratosthenes();
    newint(t);
    range(t)
    {
        func();
    }
}
/* 
k = 1
1 2 1 1 2

1 2
1 2 1
1 2 1 1 
2 1
2 1 1 
1 1 2
1 2

 */
/* 
k = 2
1 2 1 1 2
f(1 1 2)
f(2 1)

 */