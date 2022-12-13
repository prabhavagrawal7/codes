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
// #define all(a) a.begin(), a.end()
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
#define endwith(a) \
    print(a);      \
    return a;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ld pi = acos(-1);
typedef vector<string> vs;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef map<ll, ll> mii;
typedef set<ll> si;

void print(vi x)
{
    for (auto &i : x)
        cout << i << " ";
    cout << endl;
}
void print(ll x)
{
    cout << x << endl;
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
    new_int_2(n, c);
    vi vec = inputvec(n);

    sort(vec.begin(), vec.end());
    ll sum = n - 1 + n - 3;
    if (sum > c)
    {
        print(-1);
        return 0;
    }

    ll cost = 0;
    V<pii> answers;
    for (ll i = 1; i < n; i++)
    {
        answers.push_back(mp(0, i));
        cost += vec[0] + vec[i];
    }
    for (ll i = 3; i < n; i++)
    {
        answers.push_back(mp(1, i));
        cost += vec[1] + vec[i];
    }
    for (ll i = sum; i < c; i++)
    {
        answers.push_back(mp(0, 1));
        cost += vec[0] + vec[1];
    }

    cout << cost << endl;
    range(i, answers.size())
    {
        cout << answers[i].first + 1 << " " << answers[i].second + 1 << endl;
    }

    return 0;
}

int main()
{
    // FAST;
    new_int_1(t);
    range(i, t)
    {
        func();
    }
}
