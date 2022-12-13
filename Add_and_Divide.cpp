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
void print(ll x) { cout << x << endl; }
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
template <typename T>
bool btn(T a, T b, T c)
{
    if ((a <= b && b <= c) || (a >= b && b >= c))
        return true;
    return false;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

const ll range = 1000006;
//vi factors(range + 1, 0);
vi prime(range + 1, 0);
si primefactors;
void SieveOfEratosthenes()
{
    for (int p = 2; p * p <= range; p++)
    {
        if (prime[p] == false)
        {
            for (int i = p * p; i <= range; i += p)
                if (!prime[i])
                    prime[i] = i / p;
        }
    }
    for (ll i = 0; i < range; i++)
    {
    }
}
si factors(ll n)
{
    if (prime[n] == 0)
    {
        si s;
        s.insert(n);
        return s;
    }
    auto i = factors(prime[n]);
    i.insert(n / prime[n]);
    return i;
}


ll func(ll a, ll b)
{
    // write your code here
    if (gcd(a, b) == 1)
    {
        if (a == 1)
            return 1;
        else
            return 0;
    }
    ll bcp = b;
    while (bcp % a != 0 || bcp < INT_INF)
    {
        bcp = bcp * b;
        a = a / gcd(a, bcp);
        bcp = b / gcd(a, bcp);
        if (gcd(a, b) == 1)
        {
            if (a == 1)
                return 1;
            else
                return 0;
        }
    }

    if (b % a != 0)
    {
    }
    return 1;
}

int main()
{
    // FAST;
    // SieveOfEratosthenes();

    new_int_1(t);
    range(i, t)
    {
        new_int_2(a, b);
        if (func(a, b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
