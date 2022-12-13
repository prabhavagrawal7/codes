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

int main()
{
    // FAST;
    new_int_3(n, l, r);
    ll n3, n31, n32;
    ll all = r - l + 1;
    //finding n3
    {
        if (l % 3 == 0)
        {
            n3 = (r / 3 - l / 3) + 1;
        }
        else
        {
            n3 = (r / 3 - l / 3);
        }
    }
    //finding n31
    {
        ll newl = l, newr = r;
        while (newl % 3 != 1)
        {
            newl++;
        }
        while (newr % 3 != 1)
        {
            newr--;
        }
        n31 = (newr - newl) / 3 + 1;
    }
    n32 = all - n3 - n31;

    map<ll, map<ll, ll>> dp;
    dp[1][2] = n32;
    dp[1][3] = n3;

    for (ll i = 2; i <= n; i++)
    {
        dp[i][1] = (dp[i - 1][3] * n31 + dp[i - 1][2] * n32) % mod;
        dp[i][2] = (dp[i - 1][3] * n32 + dp[i - 1][1] * n31) % mod;
        dp[i][3] = (dp[i - 1][3] * n3 + dp[i - 1][1] * n32 + dp[i - 1][2] * n31) % mod;
    }
    cout << dp[n][3] % mod << endl;
}