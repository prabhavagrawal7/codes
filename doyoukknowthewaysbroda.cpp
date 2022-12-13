#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define debugp(x)          \
    for (auto element : x) \
    cout << element.first << " " << element.second << endl
#define db(x) cout << #x << " = " << x << "\n"
#define rep(i, k, n) for (ll i = k; i < n; i++)
#define rept(i, k, n) for (auto i = k; i != n; ++i)
#define drep(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define endl "\n"
#define ld long double
#define clr(s) memset(s, 0, sizeof(s))
#define new_int_1(t) \
    ll t;            \
    cin >> t;
#define new_int_2(a, b) \
    ll a, b;            \
    cin >> a >> b
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    cin >> a >> b >> c
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    cin >> a >> b >> c >> d
#define new_int_6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;            \
    cin >> a >> b >> c >> d >> e >> f
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
typedef pair<ll, ll> ii;
typedef pair<ll, pair<ll, ll>> iii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;
typedef map<char, ll> mci;
typedef set<ll> si;
const ll mod = 1000000007;
const ll mod2 = 998244353;
using namespace std;
// map<string, ll> 
ll func(ll x, ll y)
{
    if (x == 1 && y == 1)
        return 1;
    if (x < 1 && y < 1)
        return 0;
    ll path1 = func(x - 1, y - 2);
    ll path2 = func(x - 2, y - 1);
    ll ans = 0;
    if (path1 != -1)
        ans += path1;
    if (path2 != -1)
        ans += path2;
    return ans;
}

int main()
{
    ll t;
    cin >> t;
    rep(i, 0, t)
    {
        new_int_2(x, y);
        cout << func(x, y) << endl;
    }
}