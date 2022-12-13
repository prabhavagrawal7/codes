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
#define ll long long int
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

void func()
{
    // write your code here
    new_int_1(n);
    if(n == 0)
    {
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    ll hbit;
    for (hbit = 0;; hbit++)
    {
        ll temp = 1;
        if ((temp << hbit) > n)
        {
            temp = (temp << hbit);
            break;
        }
    }
    hbit -= 1LL;
    vi arr;
    arr.push_back((1LL << (hbit + 1LL)) - 1LL);
    hbit -= 1LL;
    while (hbit >= 0LL)
    {
        if (((n >> hbit) & 1LL) != ((n >> hbit + 1LL) & 1LL))
        {
            ll eans = (1LL << (hbit + 1LL)) - 1LL;
            arr.push_back(eans);
        }
        hbit--;
    }
    cout << arr.size() << endl;
    range(i, arr.size())
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
