#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
// #define ll long long int
// #define ll int

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// namespace __gnu_pbds{
//           typedef tree<long long
//                        null_type,
//                        less_equal<long long>,
//                        rb_tree_tag,
//                        tree_order_statistics_node_update> ordered_set;
// }
// using namespace __gnu_pbds;
#define popcount(x) __builtin_popcount(x)
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
#define r4(var, start, stop, step) for (ll var = start; step >= 0 ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (ll var = start; var < stop; var++)
#define r2(var, stop) for (ll var = 0; var < stop; var++)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 < stop; start_from_0++)
#define newint(...) \
    ll __VA_ARGS__; \
    take_input(__VA_ARGS__)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define give(...)           \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    }
#define endl "\n"
#define FULL_INF numeric_limits<double>::infinity()
#define INF LONG_LONG_MAX
#define INT_INF INT_MAX
#define ld long double
#define V vector
#define P pair
#define S set
#define MS multiset
#define M map
#define UM unordered_map
#define US unordered_set
#define MM multimap
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll mod3 = 1000000009;
const ll rtt = 31632;
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define newstring(str) \
    string str;        \
    cin >> str;
#define foreach(a, x) for (auto &a : x)
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef set<ll> si;
typedef map<ll, ll> mii;
typedef map<ll, vi> mvi;
typedef map<ll, si> msi;
typedef vector<vector<ll>> vvi;
template <typename... T>
void take_input(T &&...args) { ((cin >> args), ...); }
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    range(i, start, n) cin >> vec[i];
    return vec;
}
template <typename T>
bool btn(T a, T b, T c)
{
    if ((a <= b && b <= c) || (a >= b && b >= c))
        return true;
    return false;
} // between
template <typename T>
ostream &operator<<(ostream &os, const V<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}
template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}
template <typename... T>
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
inline ll rs(ll n) { return n % mod >= 0 ? n % mod : (n % mod) + mod; }
ll powerm(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
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
ll lcm(ll x, ll y)
{
    ll res = x;
    res = res / (gcd(x, y));
    res *= y;
    return res;
}
ll bin_exp(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * 1LL * a) % m;
            b--;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll a, ll m) { return bin_exp(a, m - 2, m); }
ll add(ll a, ll b, ll md)
{
    ll res = a + b;
    if (res >= md)
        res -= md;
    if (res < 0)
        res += md;
    return res;
}
ll mul(ll a, ll b, ll md)
{
    ll res = (a % md) * (b % md);
    res %= md;
    if (res < 0)
        res += md;
    return res;
}
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

ll func(string s)
{
    ll n = s.length();

    ll x = 1;
    ll ans = 0;
    vi v;
    ll j = 0, k = n - 1;
    range(i, n)
    {
        if (s[i] == '1')
        {
            j = i;
            break;
        }
    }
    range(i, n - 1, -1, -1)
    {
        if (s[i] == '0')
        {
            k = i;
            break;
        }
    }

    range(i, j, k)
    {
        if (s[i] == s[i + 1])
        {
            x++;
        }
        else
        {
            v.push_back(x);
            x = 1;
        }
    }
    v.push_back(x);

    vi y = v;
    ll p = 0;
    range(i, v.size())
    {
        if (i != 0 && i % 2 == 0)
        {
            v[i] += v[i - 2];
        }
        if (i % 2 != 0 && i != 1)
        {
            v[i] += v[i - 2];
        }
    }

    // print(v);

    if (v.size() == 1)
    {
        return 0; 
    }
    ll f = 0;

    range(i, v.size() - 1, 0, -1)
    {
        if (i % 2 == ((v.size() - 1) % 2) && (i - 1 >= 0 && v[i - 1] <= v[i] && y[i] == 1 && y[i - 1] == 1))
        {
            ans += (1000000000000);
            if (i - 2 >= 0)
            {
                y[i - 2] += y[i];
                v[i - 2]++;
            }
            f = 1;
            continue;
        }
        if (i % 2 == ((v.size() - 1) % 2))
        {
            if (f)
            {
                ans += (1000000000001) * v[i - 1];
                break;
            }
            else
            // if(v[i-1]>=v[i] || (v[i-1]>y[i]))
            {

                if (v[i - 1] >= v[i])
                    ans += (1000000000001) * (y[i]);
                else
                {
                    ans += (1000000000001) * v[i - 1];
                    break;
                }
            }
            // else
            // // if(v[i-1]<=v[i] && y[i]>1)
            // {
            //     ans+=(1000000000001)*v[i-1];
            //     break;
            // }
            // else
            // {
            //     ans+=(1000000000000);
            //     if(i-2>=0)
            //     {
            //         v[i-2]+=y[i];
            //         y[i-2]+=y[i];
            //     }
            // }
        }
    }

return ans; 
}

ll unit = (ll)(1e12) + 1;
ll brute(string str)
{
    vi ahead = {count(all(str), '0'), count(all(str), '1')};
    vi before = {0, 0};
    ll ans = INT64_MAX;
    range(i, str.size() + 1)
    {
        ans = min(ans, ahead[0] * unit + before[1] * unit);
        if (btn(1LL, i, static_cast<ll>(str.size()) - 1))
        {
            if (str[i - 1] != str[i] && str[i - 1] == '1')
                ans = min(ans, unit - 1 + (ahead[0] - 1) * unit + (before[1] - 1) * unit);
        }
        if (i != str.size())
            ahead[str[i] - '0']--, before[str[i] - '0']++;
    }
    return ans; 
}
int main()
{
    // create a random string generator 
    while(true)
    {
        string s;
        ll n = 7;
        range(i, n)
        {
            ll x = rand() % 2;
            s += (x + '0');
        }
        ll x = func(s);
        ll y = brute(s);
        if(x!=y)
        {
            cout<<s<<endl;
            cout<<x<<" "<<y<<endl;
            break;
        }
    }

}