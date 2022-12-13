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

void print(ll x)
{
    cout << x << endl;
}
void print(vi x)
{
    for (auto &i : x)
        cout << i << " ";
    cout << endl;
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

ll func()
{
    new_int_1(n);
    UM<ll, ll> dp;
    vi vec = inputvec(n + 1, 1);
    // [score] [i]
    for (ll i = 1; i <= n; i++)
    {
        ll ci = i;
        stack<ll> st;
        ll add;
        while (ci <= n)
        {
            add = vec[ci];
            st.push(ci);
            ci += add;
            if (ci > n)
                st.push(ci);
            if(dp.find(ci) != dp.end()) break;
        }
        ll ni = st.top();
        ll m;
        while (st.size())
        {
            m = st.top();
            if (dp.find(ni) == dp.end())
                dp[ni] = 0;
            dp[m] = dp[ni] + ni - m;
            ni = st.top();
            st.pop();
        }
    }
    ll score = -INT_INF;
    for (ll i = 1; i <= n; i++)
    {
        score = max(dp[i], score);
    }
    cout << score << endl;
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
