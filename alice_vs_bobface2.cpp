#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define INF LONG_LONG_MAX
#define INT_INF INT_MAX
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
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define range(i, stop) for (ll i = 0; i != stop; i++)
#define ranges(i, start, stop) for (ll i = start; i != stop; i++)
#define sranges(i, start, stop, step) for (ll i = start; i != stop; i = i + step)
#define iterate(i, start, end) for (auto i = start; i != end; i++)
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
typedef map<ll, ll> mii;
typedef set<ll> si;
void print(ll x) { cout << x << endl; }
void print(vi x)
{
    for (auto &i : x)
        cout << i << " ";
    cout << endl;
}
void print(string x) { cout << x << endl; }
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
template <typename T>
bool btn(T a, T b, T c)
{
    if ((a <= b && b <= c) || (a >= b && b >= c))
        return true;
    return false;
}
set<ll> twon;
UM<ll, bool> dp;
ll func(ll n)
{
    // write your code here
    if (dp.find(n) != dp.end())
        return dp[n];
    if (n == 0)
        return 0;
    if (n % 2 == 1)
        return (1 + func(n - 1)) % 2;
    ll ans = 0;
    for (auto i : twon)
    {
        if (n % i != 0)
            break;
        if ((1 + func(n / i)) % 2 == 1)
        {
            ans = 1;
            break;
        }
    }
    return dp[n] = ans % 2;
}

ll process(ll n)
{
    string st;
    for (ll i = n; i > 0;)
    {
        if (i % 2)
        {
            st = '1' + st;
        }
        else
        {
            st = '0' + st;
        }
        i = i / 2;
    }
    ll flag = true;

    string newst = "";
    for (ll i = 0; i < st.size();i++)
    {
        if (i + 1 < st.size() && st[i] == '1' && st[i + 1] == '1')
        {
            continue;
        }
        if (i + 1 < st.size() && i + 2 < st.size() && st[i] == '0' && st[i + 1] == '0' && st[i + 2] == '0')
        {
            continue;
        }
        newst += st[i];
        
    }
    st = newst;
    ll ans = 0;
    ll base = 1;

    for (ll i = st.size() - 1; i >= 0; i--)
    {
        if (st[i] == '1')
            ans += base;
        base = base * 2;
    }
    return ans;
}
int main()
{
    FAST;
    for (ll i = 2; i < INF / 4; i = i * 2)
    {
        twon.insert(i);
    }
    new_int_1(t);
    range(i, t)
    {
        new_int_1(n);
        n = process(n);
        ll ans = func(n);
        if (ans)
            print("Alice");
        else
            print("Bob");
    }
}
