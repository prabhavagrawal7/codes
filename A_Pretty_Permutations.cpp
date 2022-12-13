#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define ld long long double
#define print(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define db(x) cout << #x << " = " << x << "\n"
#define range(i, n) for (ll i = 0; i < n; i++)
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define loopr(i, a, b) for (ll i = a; i >= b; i--)
#define loops(i, a, b, step) for (ll i = a; i < b; i += step)
#define looprs(i, a, b, step) for (ll i = a; i >= b; i -= step)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
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
#define V vector
#define P pair
#define MS multiset
#define UM unordered_map
#define US unordered_set
#define MM multimap
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define FAST ios_base::sync_with_stdio(false);
#define all(a) a.begin(), a.end()
const ll mod = 1000000007;
const ll mod2 = 998244353;
const double pi = acos(-1);
typedef vector<string> vs;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef pair<string, ll> psi;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;
typedef map<char, ll> mci;
typedef map<string, string> mss;
typedef set<ll> si;

ll input()
{
    new_int_1(n);
    return n;
}

ll func()
{
    new_int_1(n);
    vi vec(n);
    if (n % 2 == 0)
    {
        loop(i, 0, n)
        {
            vec[i] = i + 1;
        }
        loops(i, 0, n, 2)
        {
            swap(vec[i], vec[i + 1]);
        }
    }
    else
    {
        loop(i, 0, n)
        {
            vec[i] = i + 1;
        }
        loops(i, 0, n - 1, 2)
        {
            swap(vec[i], vec[i + 1]);
        }
        swap(vec[n - 2], vec[n - 1]);
    }

    print(vec);
    return 0;
}
int main()
{
    FAST;
    new_int_1(t);
    while (t--)
    {
        func();
    }
}