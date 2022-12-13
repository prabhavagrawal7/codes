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
void stringinput(string &str)
{
    cin >> str;
}
vector<ll> randvec(ll n, ll start = 0, ll end = 100)
{
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        arr[i] = rand() % end;
        if (arr[i] < start)
        {
            arr[i] = arr[i] + start;
        }
    }
    return arr;
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
si inputset(ll n)
{
    si myset;
    for (ll i = 0; i < n; i++)
    {
        myset.insert(input());
    }
    return myset;
}
ll func()
{
    new_int_2(n, m);
    vi station = inputvec(n);
    vi pass = inputvec(m);
    si right, left;
    for (ll i = 0; i < n; i++)
    {
        if (station[i] == 0)
            continue;
        if (station[i] == 1)
            right.insert(i);
        else
            left.insert(i);
    }
    /* storing answers here */
    vi ans;
    for (ll i = 0; i < m; i++)
    {
        ll key = pass[i]-1;
        //checking for equality
        if (left.find(key) != left.end() || right.find(key) != right.end() || key == 0)
        {
            ans.push_back(0);
            continue;
        }
        ll pans = INT_MAX;
        //checking for right
        if(right.size() == 0){}
        else if (!(*right.begin() > key))
        {
            ll firstans = *prev(right.lower_bound(key)) - key;
            pans = min(pans, abs(firstans));
        }
        //checking for left
        if(left.size() == 0){}
        else if (!(*(left.rbegin()) < key))
        {
            ll secondans = *left.lower_bound(key) - key;
            pans = min(pans, abs(secondans));
        }
        pans == INT_MAX ? ans.push_back(-1) : ans.push_back(pans);
    }
    debug(ans);
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    new_int_1(t);
    rep(i, 0, t)
    {
        func();
    }
}