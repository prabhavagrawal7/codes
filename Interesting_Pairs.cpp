#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
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
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
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

// const ll range = 1000006;
// //vi factors(range + 1, 0);
// vi prime(range + 1, 0);
// void SieveOfEratosthenes()
// {
//     for (int p = 2; p * p <= range; p++)
//     {
//         if (prime[p] == false)
//         {
//             for (int i = p * p; i <= range; i += p)
//                 if (!prime[i])
//                     prime[i] = i / p;
//         }
//     }
// }
vi factors(ll n)
{
    vi ans;
    for (ll i = 2; i * i < sqrt(n); i++)
    {
        if (n % i == 0)
            ans.push_back(i);
    }
    return ans;
}

ll func()
{
    // write your code here
    new_int_1(n);
    
    vi vec = inputvec(n + 1, 1);
    for (ll i = 1; i <= n; i++)
    {
        if (vec[i] % i != 0)
            continue;
        auto checker = factors(n / i);
    }
    return 0;
}
ll trivial()
{
    new_int_1(n);
    V<_Float128> vec(n + 1);
    sranges(i, 1, n + 1, 1)
    {
        cin >> vec[i];
        vec[i] = vec[i] / ((_Float128)(i));
    }
    ll ans = 0;
    sranges(i, 1, n + 1, 1)
    {
        sranges(j, i + 1, n + 1, 1)
        {
            if ((vec[i] * vec[j]) == ((ll)(vec[i] * vec[j])))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    FAST;
    new_int_1(t);
    range(i, t)
    {
        trivial();
    }
}
