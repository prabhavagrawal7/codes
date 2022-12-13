#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define ld long double
#define print(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define db(x) cout << #x << " = " << x << "\n"
#define range(i, n) for (ll i = 0; i < n; i++)
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define loopr(i, a, b) for (ll i = a; i >= b; i--)
#define loops(i, a, b, step) for (ll i = a; i < b; i += step)
#define looprs(i, a, b, step) for (ll i = a; i >= b; i -= step)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
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
#define V vector
#define P pair
#define MS multiset
#define UM unordered_map
#define US unordered_set
#define MM multimap
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define FAST ios_base::sync_with_stdio(false);
#define all(a) a.begin(), a.end()
const ll mod = 1000000007;
const ll mod2 = 998244353;
const double pi = acos(-1);
typedef vector<string> vs;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef pair<string, ll> psi;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;
typedef map<char, ll> mci;
typedef map<string, string> mss;
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
bool between(ld a, ld b, ld c)
{
    if (a >= b && b >= c)
        return 1;
    if (a <= b && b <= c)
        return 1;
    return 0;
}
ll func()
{
    new_int_1(n);
    V<pair<ld, ld>> answers;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        ld l, r;
        cin >> t >> l >> r;
        if (t == 2)
            r = r - 0.1;
        else if (t == 3)
            l = l + 0.1;
        else if (t == 4)
            r = r - 0.1, l = l + 0.1;
        answers.push_back(mp(l, r));
    }
    ll ans = 0;
    for (ll i = 0; i < answers.size(); i++)
    {
        for (ll j = i + 1; j < answers.size(); j++)
        {

            ld l1 = answers[i].first;
            ld r1 = answers[i].second;
            ld l2 = answers[j].first;
            ld r2 = answers[j].second;
            if (between(l1, l2, r1))
                ans++;
            else if (between(l1, r2, r1))
                ans++;
            else if (between(l2, l1, r2))
                ans++;
            else if (between(l2, r1, r2))
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
int main()
{
    FAST;
    func();
}