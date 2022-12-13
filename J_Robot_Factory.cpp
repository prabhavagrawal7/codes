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
#define new_int_1(t) \
    ll t;            \
    cin >> t;
#define new_int_2(a, b) \
    ll a, b;            \
    cin >> a >> b;
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    cin >> a >> b >> c;
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    cin >> a >> b >> c >> d;
#define new_int_5(a, b, c, d, e) \
    ll a, b, c, d, e;            \
    cin >> a >> b >> c >> d >> e;
#define new_int_6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;            \
    cin >> a >> b >> c >> d >> e >> f;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef map<ll, ll> mii;
typedef set<ll> si;
ll input()
{
    new_int_1(n);
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
    for (int i = 0; i < v.size();
         ++i)
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
// # for walls and . for empty

// ***
// ***
// ***

string tobin(ll a)
{
    string s;
    if (a / 8)
    {
        s += '1';
        a = a - 8;
    }
    else
        s += '0';
    if (a / 4)
    {
        s += '1';
        a = a - 4;
    }
    else
        s += '0';
    if (a / 2)
    {
        s += '1';
        a = a - 2;
    }
    else
        s += '0';
    if (a / 1)
    {
        s += '1';
        a = a - 1;
    }
    else
        s += '0';
    return s;
}
vs give(ll x)
{
    string q = tobin(x);
    vector<string> a;
    string u = "...";
    a.push_back(u);
    a.push_back(u);
    a.push_back(u);

    if (q[0] == '1')
    {
        a[0][0] = '#';
        a[0][1] = '#';
        a[0][2] = '#';
    }
    if (q[1] == '1')
    {
        a[0][2] = '#';
        a[1][2] = '#';
        a[2][2] = '#';
    }
    if (q[2] == '1')
    {
        a[2][0] = '#';
        a[2][1] = '#';
        a[2][2] = '#';
    }
    if (q[3] == '1')
    {
        a[0][0] = '#';
        a[1][0] = '#';
        a[2][0] = '#';
    }
    return a;
}
vs func()
{
    // write your code here
    new_int_2(n, m);
    vs process;
    range(i, n)
    {
        process.push_back("");
        process.push_back("");
        process.push_back("");
        vi vec = inputvec(m);
        V<vs> ans;
        range(i, m) ans.push_back(give(vec[i]));
        // for cell 0
        for (auto &j : ans)
        {
            process[process.size() - 3] += j[0];
        }
        for (auto &j : ans)
        {
            process[process.size() - 2] += j[1];
        }
        for (auto &j : ans)
        {
            process[process.size() - 1] += j[2];
        }
    }

    return process;
}

int main()
{
    // Uncomment for faster I/O
    // FAST;
    new_int_1(t);
    range(t)
    {
        func();
    }
}
