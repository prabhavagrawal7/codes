#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
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
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL);

#define all(a) a.begin(), a.end()
#define print(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define db(x) cout << #x << " = " << x << "\n"
#define brange(i, start, end, step) for (ll i = start; i < end; i = i + step)
#define ranges(i, start, end) for (ll i = start; i < end; i = i + 1)
#define range(i, end) for (ll i = 0; i < end; i = i + 1)
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
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    for (ll i = start; i < n; i++)
    {
        vec[i] = input();
    }
    return vec;
}
ll func()
{
    new_int_3(n, a, b);
    if (a == 1)
        if ((n - 1) % b == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }

    ll i = 0;
    ll num = n - pow(a, i);
    while (num >= 0)
    {
        if (num % b == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
        i++;
        num = n - pow(a, i);
    }
    cout << "No" << endl;
    return 0;
}
int main()
{
    FAST;
    new_int_1(t);
    range(i, t)
    {
        func();
    }
}