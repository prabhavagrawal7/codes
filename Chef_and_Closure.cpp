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
#define range(i, n) for (ll i = 0; i < n; i++)
#define ranges(i, s, n) for (ll i = s; i < n; i++)
#define sranges(i, start, stop, step) for (ll i = start; i < stop; i = i + step)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define testcase(t) \
    new_int_1(t);   \
    range(i, t)
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
const ld pi = acos(-1);
typedef vector<string> vs;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef pair<string, ll> psi;
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

ll func()
{
    new_int_1(n);
    vi vec = inputvec(n);
    bool one = false;
    bool doubleotherval = false;
    bool minusone = false;
    bool zero = false;
    bool otherval = false;
    mii freq;
    for (auto i : vec)
        freq[i]++;
    for (auto i : vec)
    {
        if (i == 1)
        {
            one = true;
        }
        if (i == 0)
        {
            zero = true;
        }
        if (i == -1)
        {
            minusone = true;
        }
        if (!(i == 0 || i == 1 || i == -1))
        {
            if (otherval)
            {
                doubleotherval = true;
                return 0;
            }
            else
            {
                otherval = true;
            }
        }
    }
    vi newvec;

    for (auto i : freq)
    {
        newvec.push_back(i.first);
    }

    if (freq[-1] > 1)
    {
        if (freq[1] == 0)
            return 0;
    }

    if (freq[-1] != 0 && otherval)
    {
        return 0;
    }

    return 1;
}
int main()
{
    // FAST;
    testcase(t)
    {
        cout << func() << endl;
    }
}