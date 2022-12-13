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

// sieve starts here |sieve modified to provide smallest factors of a number|
const ll range = 1000006;
//vi factors(range + 1, 0);
vector<string> composites;
void SieveOfEratosthenes()
{
    composites.push_back("1");
    vi prime(range + 1, 0);
    for (int p = 2; p * p <= range; p++)
    {
        if (prime[p] == false)
        {
            for (int i = p * p; i <= range; i += p)
                if (!prime[i])
                    prime[i] = i / p;
        }
    }
    for (ll i = 0; i < range-5; i++)
    {
        if (prime[i] != 0)
        {
            composites.push_back(to_string(i));
        }
    }
}

ll checker(string &str, string &com)
{
    ll i = 0, j = 0;
    for (; i < com.size() && j < str.size();)
    {
        if (str[j] == com[i])
        {
            i++, j++;
        }
        else
        {
            j++;
        }
    }
    if (i == com.size())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
ll func()
{
    new_int_1(n);
    new_string(str);
    for (ll i = 0; i < composites.size(); i++)
    {
        if (checker(str, composites[i]))
        {
            cout << composites[i].size() << endl
                 << composites[i] << endl;
            break;
        }
    }
    return 0;
}
int main()
{
    // FAST;
    SieveOfEratosthenes();
    testcase(t)
    {
        func();
    }
}