#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define endl "\n"
#define ll int
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
#define ld long double
#define clr(s) memset(s, 0, sizeof(s))
#define new_string(str) \
    string str;         \
    stringinput(str);
#define new_int_1(t) \
    ll t;            \
    scanf("%lld", &t);
#define new_int_2(a, b) \
    ll a, b;            \
    scanf("%lld %lld", &a, &b);
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    scanf("%lld %lld %lld", &a, &b, &c);
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
#define new_int_5(a, b, c, d, e) \
    ll a, b, c, d, e;            \
    scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);
#define new_int_6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;            \
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
typedef vector<string> vs;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
typedef vector<set<ll>> vsi;
typedef vector<set<pair<ll, ll>>> vspii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef pair<ll, ll> pii;
typedef pair<ll, pair<ll, ll>> pipii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;
typedef map<char, ll> mci;
typedef map<string, string> mss;
typedef set<ll> si;
typedef set<pair<ll, ll>> spii;
typedef set<pair<string, ll>> spsi;
const ll mod = 1000000007;
const ll mod2 = 998244353;
char s[100005];
void stringinput(string &str)
{
    scanf("%s", s);
    str = s;
}

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
        *(vec.begin() + i) = input();
    }
    return vec;
}
ll func(string &str, char a, ll start, ll stop)
{
    if (start + 1 == stop)
    {
        if (str[start] == a)
            return 0;
        else
            return 1;
    }

    ll n = stop - start;
    ll firsthalf = 0, secondhalf = 0;
    for (ll i = start; i < start + n / 2; i++)
    {
        if (str[i] != a)
        {
            firsthalf++;
        }
    }
    firsthalf += func(str, a + 1, start + n / 2, stop);

    for (ll i = start + n / 2; i < stop; i++)
    {
        if (str[i] != a)
        {
            secondhalf++;
        }
    }
    secondhalf += func(str, a + 1, start, start + n / 2);

    return min(firsthalf, secondhalf);
}

int main()
{
    new_int_1(t);
    rep(i, 0, t)
    {
        new_int_1(n);
        new_string(str);
        ll start = 0, stop = str.length();
        cout << func(str, 'a', start, stop) << endl;
    }
}