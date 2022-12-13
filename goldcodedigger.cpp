#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define debugp(x)          \
    for (auto element : x) \
    cout << element.first << " " << element.second << endl
#define db(x) cout << #x << " = " << x << "\n"
#define makegraph(adj, num)      \
    for (ll i = 0; i < num; i++) \
    {                            \
        ll u, v;                 \
        cin >> u >> v;           \
        adj[u].push_back(v);     \
        adj[v].push_back(u);     \
    }
#define rep(i, k, n) for (ll i = k; i < n; i++)
#define rept(i, k, n) for (auto i = k; i != n; ++i)
#define drep(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define endl "\n"
#define ld long double
#define clr(s) memset(s, 0, sizeof(s))
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define new_int_1(t) \
    ll t;            \
    cin >> t;
#define new_int_2(a, b) \
    ll a, b;            \
    cin >> a >> b
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    cin >> a >> b >> c
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    cin >> a >> b >> c >> d
#define new_int_6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;            \
    cin >> a >> b >> c >> d >> e >> f
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
typedef pair<ll, ll> ii;
typedef pair<ll, pair<ll, ll>> iii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;
typedef map<char, ll> mci;
typedef set<ll> si;
const ll llmax = 2147483647;
const ll intmin = -2147483648;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll n = 1000000;

ll prime[n + 1];
void SieveOfEratosthenes()
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    memset(prime, false, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == false)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                if (!prime[i])
                    prime[i] = i / p;
        }
    }

    // Print all prime numbers
    // for (int p = 2; p <= 20; p++)
        // if (prime[p])
    //     {
    //         db(p);
    //         db(prime[p]);
    //     }
}

// Driver Code
map<ll, ll> storage;
ll recursiveprime(ll n)
{
    if (storage.find(n) != storage.end())
        return storage[n];
    ll ans = prime[n];
    if (ans == 0)
    {
        return storage[n] = 0;
    }
    return storage[n] = 1 + recursiveprime(ans);
}
vector<ll> randvec(ll n, ll start = 0, ll end = 100)
{
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        arr[i] = rand() % end;
        if (arr[i] < start)
        {
            arr[i] = arr[i] + start;
        }
    }
    return arr;
}
string stringvec(vector<ll> vec, ll start = 0, ll end = INT_MIN)
{
    if (end == INT_MIN)
    {
        end = vec.size();
    }
    string str = "";
    for (ll i = start; i < end; i++)
    {
        str += to_string(vec[i]) + " ";
    }
    str += "\n";
    return str;
}
vector<ll> inputvec(ll n, ll start = 0)
{
    vector<ll> vec(n);
    for (ll i = start; i < n; i++)
    {
        ll num;
        scanf("%lld", &num);
        *(vec.begin() + i) = num;
    }
    return vec;
}

ll func()
{
    new_int_1(n);
    vi vec = inputvec(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += recursiveprime(vec[i]);
    }
    if (sum % 2 == 1)
    {
        cout << "Gold Digger" << endl;
    }
    else
    {
        cout << "Code Digger" << endl;
    }
    return 0;
}
int main()
{
    new_int_1(t);
    SieveOfEratosthenes();
    while (t--)
        func();
}