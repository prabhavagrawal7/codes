#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define debug(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define debugp(x)          \
    for (auto element : x) \
    cout << element.first << " " << element.second << endl
#define db(x) cout << #x << " = " << x << "\n"
#define rep(i, k, n) for (ll i = k; i < n; i++)
#define rept(i, k, n) for (auto i = k; i != n; ++i)
#define drep(i, k, n) for (ll i = k; i >= n; i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define ld long double
#define clr(s) memset(s, 0, sizeof(s))
#define new_string(str) \
    string str;         \
    stringinput(str);
#define ll1(t) \
    ll t;      \
    cin >> t;
#define ll2(a, b) \
    ll a, b;      \
    cin >> a >> b;
#define ll3(a, b, c) \
    ll a, b, c;      \
    cin >> a >> b >> c;
#define ll4(a, b, c, d) \
    ll a, b, c, d;      \
    cin >> a >> b >> c >> d;
#define ll5(a, b, c, d, e) \
    ll a, b, c, d, e;      \
    cin >> a >> b >> c >> d >> e;
#define ll6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;      \
    cin >> a >> b >> c >> d >> e;
typedef vector<string> vs;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
typedef vector<set<ll>> vsi;
typedef vector<set<pair<ll, ll>>> vspii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef pair<ll, ll> pii;
typedef pair<ll, pair<ll, ll>> pipii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;
typedef map<char, ll> mci;
typedef map<string, string> mss;
typedef set<ll> si;
typedef set<pair<ll, ll>> spii;
typedef set<pair<string, ll>> spsi;
const ll mod = 1000000007;
const ll mod2 = 998244353;
void stringinput(string &str)
{
    cin >> str;
}
ll input()
{
    ll1(n);
    return n;
}
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    for (ll i = start; i < n; i++)
    {
        *(vec.begin() + i) = input();
    }
    return vec;
}
int factors1(int n)
{
    int ans = 0; // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        ans++;
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            ans++;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        ans++;
    return ans;
}

//sieve starts here
//(sieve modified to provide smallest factors of a number)

const ll limit = 1000006;

vi prime(limit + 1, 0);
void SieveOfEratosthenes()
{
    for (int p = 2; p * p <= limit; p++)
    {
        if (prime[p] == false)
        {
            for (int i = p * p; i <= limit; i += p)
                if (!prime[i])
                    prime[i] = i / p;
        }
    }
}
// sieve ends here
mii factors;
ll nooffactors(ll n)
{

    if (n > limit - 10)
    {
        for (ll i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return 1 + nooffactors(n / i);
            }
        }
        return 1;
    }
    else if (factors.find(n) != factors.end())
    {
        return factors[n];
    }
    else
    {
        if (prime[n] == 0)
        {
            return factors[n] = 1;
        }
        else
        {
            return factors[n] = 1 + nooffactors(prime[n]);
        }
    }
}
ll gfg(ll n)
{
    ll ans = 0; // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        ans++;
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i * i <= n; i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            ans++;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        ans++;
    return ans;
}
ll func(ll i, ll j)
{
    while (i != j)
    {
        i++;
        if (gfg(i) != nooffactors(i))
        {
            cout << i << endl;
            db(gfg(i));
            db(nooffactors(i));
            break;
        }
    }
    cout << i << endl;
    return i;
}

int main()
{
    cout << nooffactors(1) << endl;
}