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
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define print(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define db(x) cout << #x << " = " << x << "\n"
#define range(i, n) for (ll i = 0; i < n; i++)
#define ranges(i, s, n) for (ll i = s; i < n; i++)
#define sranges(i, start, stop, step) for (ll i = start; i != stop; i = i + step)
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

vector<ll> muleach(vi vec, ll k)
{
    for (ll i = 0; i < vec.size(); i++)
    {
        vec[i] = vec[i] * k;
    }
    return vec;
}
vector<ll> join(vi x, vi y)
{
    V<ll> v;
    copy(x.begin(), x.end(), back_inserter(v));
    copy(y.begin(), y.end(), back_inserter(v));
    return v;
}
ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x);

        y = y >> 1;
        x = (x * x);
    }
    return res;
}
vector<ll> populateFactors(V<pii> &factors, ll size = -1)
{
    if (size == -1)
        size = factors.size();
    if (size == 0)
    {
        vector<ll> r;
        r.push_back(1);
        return r;
    }
    vi sans = populateFactors(factors, size - 1);
    vi ans;
    vi addToAns;
    for (ll i = 0; i <= factors[size - 1].second; i++)
    {
        // sans*pow(factors[size-1].first,i)
        addToAns = muleach(sans, power(factors[size - 1].first, i));
        ans = join(ans, addToAns);
    }
    return ans;
}

vi primes;
void SieveOfEratosthenes()
{
    ll range = 31700;
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
    for (ll i = 2; i < range; i++)
    {
        if (prime[i] == 0)
        {
            primes.push_back(i);
        }
    }
}
V<pii> primefactors(ll n)
{
    V<pii> ans;
    bool nIsPrime = true;
    map<ll, ll> nrans;
    for (auto i : primes)
    {
        while (n % i == 0)
        {
            nIsPrime = false;
            nrans[i]++;
            n = n / i;
        }
        if (n == 1)
            break;
    }
    if (nIsPrime)
        return vector<pii>(1, mp(n, 1));
    for (auto i : nrans)
        ans.push_back(i);
    return ans;
}

int main()
{
    // FAST;
    SieveOfEratosthenes();
    auto factors = primefactors(mod);
    print(populateFactors(factors));
    factors = primefactors(mod2);
    print(populateFactors(factors));
}
