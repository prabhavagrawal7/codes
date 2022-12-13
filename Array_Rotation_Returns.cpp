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
ll func()
{
    new_int_1(n);
    vi A = inputvec(n);
    vi B = inputvec(n);
    vi index;
    ll min = INT_MAX;
    for (ll i = 0; i < n; i++)
    {
        ll c = (A[0] + B[i]) % n;
        if (c <= min)
        {
            min = c;
            index.push_back(i);
        }
    }

    ll ind1 = -1;
    ll ind2 = -1;

    if (index.size() > 1)
    {
        ind1 = index[index.size() - 1];
        ind2 = index[index.size() - 2];
    }
    else
    {
        ind1 = index[index.size() - 1];
    }

    //only 1 found
    if (ind2 == -1)
    {
        vi ans;
        
        for (ll i = ind1, j = 0; j < n; i++, j++)
        {
            ll k = i % n;
            ans.push_back((A[j] + B[k]) % n);
        }
        print(ans);
    }


    //if both are found
    else
    {
        vi ans1;
        vi ans2;
        
        for (ll i = ind1, j = 0; j < n; i++, j++)
        {
            ll k = i % n;
            ans1.push_back((A[j] + B[k]) % n);
        }

        for (ll i = ind2, j = 0; j < n; i++, j++)
        {
            ll k = i % n;
            ans2.push_back((A[j] + B[k]) % n);
        }

        if (ans1 < ans2)
        {
            print(ans1);
        }
        else
        {
            print(ans2);
        }
    }

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