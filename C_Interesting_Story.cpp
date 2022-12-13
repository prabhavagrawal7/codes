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

ll otherfunc(vi &ave)
{
    sort(ave.begin(), ave.end());
    ll ans = 0;
    ll totala = 0;
    ll itr = 0;

    while (itr != ave.size())
    {
        totala -= ave[itr];
        itr++;
        if (totala > 0)
            ans++;
        else
            break;
    }
    return ans;
}

ll func()
{
    new_int_1(n);
    vi avec(n);
    vi bvec(n);
    vi cvec(n);
    vi dvec(n);
    vi evec(n);
    range(i, n)
    {
        map<char, ll> charmap;
        new_string(str);
        range(i, str.size())
        {
            charmap[str[i]]++;
        }
        avec[i] = str.size() - 2*charmap['a'];
        bvec[i] = str.size() - 2*charmap['b'];
        cvec[i] = str.size() - 2*charmap['c'];
        dvec[i] = str.size() - 2*charmap['d'];
        evec[i] = str.size() - 2*charmap['e'];
    }
    ll ans = 0;
    ans = max(otherfunc(avec), ans);
    ans = max(otherfunc(bvec), ans);
    ans = max(otherfunc(cvec), ans);
    ans = max(otherfunc(dvec), ans);
    ans = max(otherfunc(evec), ans);

    cout << ans << endl;
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