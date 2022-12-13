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
ll gcd(ll m, ll n)
{
    while (n != 0)
    {
        ll t = m % n;
        m = n;
        n = t;
    }
    return m;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
ll get_parent(vi &parent, ll val)
{
    if (parent[val] == val)
        return val;
    return parent[val] = get_parent(parent, parent[val]);
}

ll func()
{
    // write your code here
    newint(n, k);
    vi vec = inputvec(n);
    V<pii> svec;
    range(i, n) svec.push_back(mp(vec[i], i));
    sort(all(svec));
    vi parent(n);
    range(i, n)
    {
        parent[i] = i;
    }
    V<bool> visit(n, 0);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = k + i; j < n; j++)
        {
            ll a = get_parent(parent, i);
            ll b = get_parent(parent, j);
            parent[b] = a;
            if (visit[j])
                break;
            else
                visit[j] = true;
        }
    }
    map<ll, si> allparents;
    range(i, n)
    {
        allparents[vec[i]].insert(get_parent(parent, i));
    }
    range(i, n)
    {
        ll trueestval = svec[i].first;
        if (vec[i] == trueestval)
            continue;
        if (!binary_search(all(allparents[trueestval]), get_parent(parent, i)))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    range(t)
    {
        if (func())
            print("YES");
        else
            print("NO");
    }
}