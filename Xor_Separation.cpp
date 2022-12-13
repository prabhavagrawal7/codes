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
const ll high = 10000000000000001;
vi debugvec;
void substrvec(vi vec, ll start = 0, ll end = -1)
{
    if (end == -1)
        end = vec.size();
    vi newvec(end - start);
    for (ll i = start; i < end; i++)
    {
        newvec[i] = vec[i];
    }
    debugvec = newvec;
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
        vec[i] = input();
    }
    return vec;
}

map<ll, map<ll, ll>> dp;

ll func(vi &vec, ll start, ll div, ll zor)
{
    if (zor % div != 0)
        return 0;
    
    if(dp[start].find(zor) != dp[start].end())
    {
        return dp[start][zor];
    }
    
    ll ans = 1;
    for (ll i = start + 1; i < vec.size(); i++)
    {
        zor = zor ^ vec[i - 1];
        if (zor % (div * 2) == 0)
        {
            ans = (ans + func(vec, i, div * 2, zor))%mod;
        }
        else if(div*2 > high)
        {
            break;
        }
    }
    return dp[start][zor] = ans%mod;
}
int main()
{
    FAST;
    testcase(t)
    {
        new_int_1(n);
        vi vec = inputvec(n);
        ll zor = 0;
        range(i, n)
        {
            zor = zor ^ vec[i];
        }
        ll ans = func(vec, 0, 1, zor);
        cout << ans << endl;
        dp.clear(); 
    }
}