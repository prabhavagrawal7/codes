#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
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
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define ld long double
#define clr(s) memset(s, 0, sizeof(s))
#define new_string(str) \
    string str;         \
    cin >> str;
#define ll1(t) \
    ll t;      \
    cin >> t;
#define ll2(a, b) \
    ll a, b;      \
    cin >> a >> b;
#define ll3(a, b, c) \
    ll a, b, c;      \
    cin >> a >> b >> c;
#define ll4(a, b, c, d) \
    ll a, b, c, d;      \
    cin >> a >> b >> c >> d;
#define ll5(a, b, c, d, e) \
    ll a, b, c, d, e;      \
    cin >> a >> b >> c >> d >> e;
#define ll6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;      \
    cin >> a >> b >> c >> d >> e;
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

string input()
{
    new_string(str);
    return str;
}
vs inputvec(ll n, ll start = 0)
{
    vs vec(n);
    for (ll i = start; i < n; i++)
    {
        vec[i] = input();
    }
    return vec;
}
ll func()
{
    ll2(n, m);
    vs vec = inputvec(n);
    char odd = '.';
    char even = '.';
    vs vec1 = vec;
    bool flag = false;
    bool flag1 = false;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (vec[i][j] == '.')
            {
                if ((i + j) % 2 == 0)
                {
                    vec[i][j] = 'R';
                }
                else
                {
                    vec[i][j] = 'W';
                }
                if ((i + j) % 2 == 0)
                {
                    vec1[i][j] = 'W';
                }
                else
                {
                    vec1[i][j] = 'R';
                }
            }
            else
            {
                if ((i + j) % 2 == 0)
                {
                    vec[i][j] != 'R' ? flag = true : true;
                }
                else
                {
                    vec[i][j] != 'W' ? flag = true : true;
                }
                if ((i + j) % 2 == 0)
                {
                    vec1[i][j] != 'W' ? flag1 = true : true;
                }
                else
                {
                    vec1[i][j] != 'R' ? flag1 = true : true;
                }
            }
        }
    }

    if (!flag)
    {
        cout << "YES" << endl;
        for (ll i = 0; i < n; i++)
        {
            cout << vec[i] << endl;
        }
        return 0;
    }
    if (!flag1)
    {
        cout << "YES" << endl;
        for (ll i = 0; i < n; i++)
        {
            cout << vec1[i] << endl;
        }
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll1(t);
    rep(i, 0, t)
    {
        func();
    }
}
