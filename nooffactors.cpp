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
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define ld long double
#define clr(s) memset(s, 0, sizeof(s))
#define new_string(str) \
    string str;         \
    stringinput(str);
#define new_int_1(t) \
    ll t;            \
    scanf("%lld", &t);
#define new_int_2(a, b) \
    ll a, b;            \
    scanf("%lld %lld", &a, &b);
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    scanf("%lld %lld %lld", &a, &b, &c);
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    scanf("%lld %lld %lld %lld ", &a, &b, &c, &d);
#define new_int_5(a, b, c, d, e) \
    ll a, b, c, d, e;            \
    scanf("%lld %lld %lld %lld ", &a, &b, &c, &d, &e);
#define new_int_6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;            \
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
typedef vector<string> vs;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
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
char s[100005];
void stringinput(string &str)
{
    scanf("%s", s);
    str = s;
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
        *(vec.begin() + i) = input();
    }
    return vec;
}
si inputset(ll n)
{
    si myset;
    for (ll i = 0; i < n; i++)
    {
        myset.insert(input());
    }
    return myset;
}
const ll N = 1000006;
void smallestfactorfunction(ll i, vi &breakability, vi &smallestFactorTimes)
{
    smallestFactorTimes[i] = 0;
    ll breakingfactor = breakability[i];
    ll num = i;
    while (num % breakingfactor == 0)
    {
        smallestFactorTimes[i] += 1;
        num = num / breakingfactor;
    }
    // if(breakability[i] != breakingfactor)
    // {
    //     return 1;
    // }
    // if(smallestFactorTimes[i] != 0)
    // {
    //     return smallestFactorTimes[i];
    // }
    // smallestFactorTimes[i] = 1 + smallestfactorfunction(i/breakingfactor, breakingfactor, breakability, smallestFactorTimes);
    // return smallestFactorTimes[i];
}
vi factors(N);
void sievemaker()
{
    ll n = N - 2;
    vi breakability(N, 0);
    //creating a normal breakability sieve
    for (ll i = 2; i <= n; i++)
    {
        if (breakability[i] != 0)
        {
            continue;
        }
        for (ll j = i * i; j <= n; j += i)
        {
            if (breakability[j] != 0)
                continue;
            breakability[j] = i;
        }
    }
    //creating by how much time smallest factor can break the number
    vi smallestFactorTimes(N);
    for (ll i = 2; i < n; i++)
    {
        if (breakability[i] == 0)
        {
            smallestFactorTimes[i] = 1;
            continue;
        }
        smallestFactorTimes[i] = 0;
        ll breakingfactor = breakability[i];
        ll num = i;
        while (num % breakingfactor == 0)
        {
            smallestFactorTimes[i] += 1;
            num = num / breakingfactor;
        }
    }
    // finding the numbers

    for (ll i = 2; i < n; i++)
    {
        if (breakability[i] == 0)
        {
            factors[i] = 2;
        }
        else
        {
            ll nextfactor = i / breakability[i];
            ll partialans = factors[nextfactor];
            ll a = smallestFactorTimes[i];
            factors[i] = partialans * (a + 1) / (a);
        }
    }
}

// ll func()
// {
//
//     return 0;
// }

int main()
{
    sievemaker();
}