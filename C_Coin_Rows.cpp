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
ll summ(vi &vec)
{
    return accumulate(vec.begin(), vec.end(), 0LL);
}
ll func()
{
    new_int_1(col);
    vi fc = inputvec(col);
    vi sc = inputvec(col);
    //preprocessing
    vi pfc(col, 0);
    pfc[col - 1] = fc[col - 1];
    for (ll i = col - 2; i >= 0; i--)
    {
        pfc[i] = pfc[i + 1] + fc[i];
    }

    vi psc(col, 0);
    psc[col - 1] = sc[col - 1];
    for (ll i = col - 2; i >= 0; i--)
    {
        psc[i] = psc[i + 1] + sc[i];
    }

    bool flag = false;
    ll sum = 0;
    for (ll i = 0; i < col; i++)
    {

        if (!flag)
        {
            sum += fc[i];
        }
        if (pfc[i] <= psc[i])
            flag = true;
        if (i == col - 1)
            flag = true;
        if (flag)
        {
            sum += sc[i];
        }
    }
    cout << pfc[0] + psc[0] - sum << endl;
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