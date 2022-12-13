#include "bits/stdc++.h"
using namespace std;
#define ll int64_t

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)
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
#define INF INT64_MAX
#define INT_INF INT32_MAX
#define ld long double
#define V vector
#define P pair
#define S set
#define MS multiset
#define M map
#define UM unordered_map
#define US unordered_set
#define MM multimap
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define pf push_front
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
string db_bin(ll n)
{
    string ans;
    while (n)
    {
        ans.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(all(ans));
    return ans;
}
#define newstring(str) \
    string str;        \
    cin >> str;
#define foreach(a, x) for (auto &&a : x)
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef map<ll, ll> mii;
typedef set<ll> si;
typedef vector<vector<ll>> vvi;
template <typename... T>
inline void take_input(T &&...args) { ((cin >> args), ...); }
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    range(i, start, n) cin >> vec[i];
    return vec;
}
template <typename T>
inline bool btn(T a, T b, T c)
{
    if ((a <= b && b <= c) || (a >= b && b >= c))
        return true;
    return false;
}
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
inline void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
inline void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
const int64_t mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n = n % mod) >= 0 ? n : n + mod; }
ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1LL)
            res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res % mod;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

void func(vi &vec)
{
    ll n = vec.size();
    if (n == 0)
    {
        give(1);
    }
    vi index(n);
    range(i, n)
    {
        index[vec[i]] = i;
    }

    ll l = index[0];
    ll r = index[0] + 1;
    V<bool> mex(n + 1);
    mex[0] = true;
    ll mexnow = 1;
    ll ans = 1;
    while (mexnow < n)
    {
        ll ind = index[mexnow];
        ll safedis1 = l;
        ll safedis2 = n - r;
        if (ind < l)
            safedis1 = min(safedis1, l - ind - 1);
        else
            safedis2 = min(safedis2, ind - r);
        // chalne ka range
        ll ckr = mexnow * 2 - (r - l);
        if (safedis1 > safedis2)
            swap(safedis1, safedis2);
        ckr = min(ckr, safedis1 + safedis2);
        // swap this with faster function
        ll tempans = 0, fans = 0;
        // range(s, 1, ckr + 1)
        // {
        //     // excess
        //     if (safedis1 + safedis2 < s)
        //         break;
        //     // chote me sara bharo
        //     ll bmb = max(0LL, s - safedis1);
        //     ll cmb = s - bmb;
        //     tempans += min(cmb, safedis2 - bmb) + 1;
        // }
        // faster func
        if (ckr >= 0)
        {
            if (ckr > safedis1)
            {
                fans += (safedis1 + 1) * (safedis1 + 2) / 2 - 1;
                if (ckr >= safedis2)
                {
                    fans += (safedis1 + 1) * (safedis2 - safedis1);
                    ll moves = ckr - safedis2;
                    fans += moves * (2 * (safedis1) + 1 - moves) / 2;
                }
                else
                {
                    fans += (safedis1 + 1) * (ckr - safedis1);
                }
            }
            else
            {
                fans += (ckr + 1) * (ckr + 2) / 2 - 1;
            }
        }
        // assert(tempans == fans && (cout << vec << endl));
        ans += fans;

        // update mex
        while (ind < l && l - 1 >= 0)
        {
            l--;
            mex[vec[l]] = 1;
            while (mex[mexnow] != 0)
                mexnow++;
        }
        while (ind >= r && r < n)
        {
            mex[vec[r]] = 1;
            r++;
            while (mex[mexnow] != 0)
                mexnow++;
        }
        ckr = mexnow * 2 - (r - l);
        if (ckr >= 0)
            ans++;
    }
    print(ans);
}

int getNum(vector<int> &v)
{

    // Size of the vector
    int n = v.size();

    // Generate a random number
    srand(time(NULL));

    // Make sure the number is within
    // the index range
    int index = rand() % n;

    // Get random number from the vector
    int num = v[index];

    // Remove the number from the vector
    swap(v[index], v[n - 1]);
    v.pop_back();

    // Return the removed number
    return num;
}
vi generateRandom(int n)
{
    vector<int> v(n);

    // Fill the vector with the values
    // 1, 2, 3, ..., n
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
    vi ans;
    // While vector has elements
    // get a random number from the vector and print it
    while (v.size())
        ans.pb(getNum(v) - 1);

    return ans;
}
int main()
{
    // Uncomment for faster I/O
    FAST;
    newint(t);
    range(t)
    {
        newint(n);
        vi vec = inputvec(n);
        func(vec);
    }
    // while (true)
    // {
    //     auto vec = generateRandom(20);
    //     func(vec);
    // }
}
