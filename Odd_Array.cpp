#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll int
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
void copyvec(set<vector<int>> &normalvec, vector<vector<int>> &copyvec)
{
    copyvec = vector<vector<int>>(normalvec.size());
    ll j = 0;
    for (auto &i : normalvec)
    {
        copyvec[j] = i;
        j++;
    }
    return;
}
vi joiner(vi v1, ll x, vi v2)
{
    vi c(v1.size() + v2.size() + 1);
    range(i, v1.size())
    {
        c[i] = v1[i];
    }
    c[v1.size()] = x;
    range(i, v2.size())
    {
        c[i + v1.size() + 1] = v2[i];
    }
    return c;
}

int main()
{
    // FAST;
    ll h = 2;
    vi vec = {1};
    while (vec.size() < 10002)
    {
        vec = joiner(vec, h, vec);
        h++;
    }
    testcase(t)
    {
        new_int_1(n);
        for (ll i = 0; i < n; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    
}