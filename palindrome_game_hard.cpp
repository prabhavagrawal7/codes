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
    scanf("%lld", &t);
#define new_int_2(a, b) \
    ll a, b;            \
    scanf("%lld %lld", &a, &b);
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    scanf("%lld %lld %lld", &a, &b, &c);
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    scanf("%lld %lld %lld %lld ", &a, &b, &c, &d);
#define new_int_5(a, b, c, d, e) \
    ll a, b, c, d, e;            \
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d, &e);
#define new_int_6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;            \
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
typedef vector<string> vs;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
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

//dynamic approach
ll dp[1001][1001][2];
ll func(ll noofones, ll noofzeros, bool skip)
{
    if (dp[noofones][noofzeros][skip] != INT_MAX)
    {
        return dp[noofones][noofzeros][skip];
    }
    if (noofzeros == 0 && noofones == 0)
    {
        return dp[noofones][noofzeros][skip] = 0;
    }
    if (noofones == 0)
    {
        skip = false;
    }
    vi ans;
    if ((noofones + noofzeros) % 2 == 0)
    {
        if (noofones + 1 <= noofzeros - 1)
        {
            ans.push_back(1 - func(noofones + 1, noofzeros - 1, true));
            if (noofones != 0)
            {
                ans.push_back(1 - func(noofones - 1, noofzeros - 1, true));
            }
        }
        else
        {
            ans.push_back(1 - func(noofones - 1, noofzeros - 1, true));
        }
    }
    else if ((noofones + noofzeros) % 2 == 1)
    {
        ans.push_back(1 - func(noofones, noofzeros - 1, true)); //middle case
        if (noofones + 1 <= noofzeros - 1)
            ans.push_back(1 - func(noofones + 1, noofzeros - 1, true));
        if (noofones != 0)
            ans.push_back(1 - func(noofones - 1, noofzeros - 1, true));
    }

    //if skip == true -> one more case of ans.pushback()
    if (skip == true)
    {
        ans.push_back(-func(noofones, noofzeros, false));
    }
    return dp[noofones][noofzeros][skip] = *min_element(all(ans));
}

int main()
{
    for (ll i = 0; i < 1001; i++)
    {
        for (ll j = 0; j < 1001; j++)
        {
            for (ll k = 0; k < 2; k++)
            {
                dp[i][j][k] = INT_MAX;
            }
        }
    }

    new_int_1(t);
    rep(i, 0, t)
    {
        new_int_1(n);
        new_string(str);
        n = str.length();
        ll noofzeros = 0, noofones = 0;
        rep(i, 0, n)
        {
            if (str[i] == str[n - i - 1] && str[i] == '1')
            {
                continue;
            }
            str[i] - '0' ? noofones++ : noofzeros++;
        }
        ll myfunc = func(noofones, noofzeros, true);
        if (myfunc < 0)
        {
            cout << "ALICE" << endl;
        }
        else if (myfunc > 0)
        {
            cout << "BOB" << endl;
        }
        else
        {
            cout << "DRAW" << endl;
        }
        // cout << func(noofones, noofzeros, true) << endl;
        }
}

// cout << string(noofones, '1') + string(noofzeros, '0') << endl;