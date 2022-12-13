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
ll driver(string &str, ll pos, ll g1, ll g2)
{
    if (pos > 10)
    {
        return 10;
    }
    //check for g1 win
    ll chances_left_g1 = pos % 2 == 0 ? 5 - pos / 2 : 5 - (pos / 2 + 1);
    ll chances_left_g2 = pos % 2 == 0 ? chances_left_g1 : chances_left_g1 + 1;
    if (g1 + chances_left_g1 < g2)
    {
        return pos;
    }
    else if (g2 + chances_left_g2 < g1)
    {
        return pos;
    }

    //check for g2 win

    if (str[pos] == '0')
    {
        return driver(str, pos + 1, g1, g2);
    }
    else
    {
        if (pos % 2 == 0)
            return driver(str, pos + 1, g1 + 1, g2);
        else
            return driver(str, pos + 1, g1, g2 + 1);
    }
    return 0;
}
ll func()
{
    new_string(str);
    auto str1 = str;
    auto str2 = str;

    for (ll i = 0; i < str.length(); i += 2)
    {
        if (str[i] == '?')
        {
            str1[i] = '1';
            str2[i] = '0';
        }
    }

    for (ll i = 1; i < str.length(); i += 2)
    {
        if (str[i] == '?')
        {
            str1[i] = '0';
            str2[i] = '1';
        }
    }
    cout << min(driver(str1, 0, 0, 0), driver(str2, 0, 0, 0)) << endl;

    return 0;
}
int main()
{
    // FAST;
    testcase(t)
    {
        func();
    }
}