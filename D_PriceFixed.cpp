#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define ld long long double
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
ll func()
{
    new_int_1(n);
    map<ll, ll> value;
    for (ll i = 0; i < n; i++)
    {
        new_int_2(a, b);
        if (value.find(b) != value.end())
            value[b] += a;
        else
            value[b] = a;
    }
    //input done
    V<pii> vec;
    for (auto i : value)
    {
        vec.push_back(mp(i.second, i.first));
    }
    //sorting done
    ll rubbles = 0;
    ll i = 0, j = value.size() - 1, items = 0;
    while (i != j)
    {
        if (items >= vec[i].second)
        {
            items += vec[i].first;
            rubbles += vec[i].first;
            vec[i].first = 0;
            i++;
        }
        else
        {
            if (vec[j].first > vec[i].second - items)
            {
                rubbles += (vec[i].second - items) * 2;
                vec[j].first = vec[j].first - (vec[i].second - items);
                items += (vec[i].second - items);
            }
            else
            {
                rubbles += vec[j].first * 2;
            zz    items += vec[j].first;
                vec[j].first = 0;
                j--;
            }
        }
    }
    ll mi = min(vec[i].second, items);
    vec[i].second -= mi;
    items -= mi;
    if (items >= vec[i].second)
    {
        rubbles += vec[i].first;
    }
    else
    {
        ll mini = min(vec[i].first, vec[i].second);
        rubbles += mini * 2;
        vec[i].first -= mini;
        vec[i].second -= mini;
        if (vec[i].first > 0)
        {
            rubbles += vec[i].first;
        }
    }

    cout << rubbles << endl;
    return 0;
}
int main()
{
    FAST;
    func();
}