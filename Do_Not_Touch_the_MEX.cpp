#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)
#define popcount(x) __builtin_popcount(x)
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1) \
(__VA_ARGS__)
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
const ll mod = 1000000007;
// const ll mod = 998244353;
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
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
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
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

ll func(vi vec)
{
    ll n = vec.size(); 
    ll tp = 0;
    vi mapped(n);
    range(i, n)
    {
        mapped[vec[i]] = i;
    }
    ll l = mapped[0], r = mapped[0];
    vi truevec(n + 1, 0);
    ll cp = 1;
    truevec[0] = 1;
    while (cp != n)
    {
        // use old cp to find new points
        ll id = mapped[cp];
        truevec[cp] = 1;
        // working on internal distortions..
        // 2 5 1 0 3 6 4
        if (id <= l)
        {
            range(i, l-1, id - 1, -1)
            {
                if (truevec[vec[i]])
                    continue;
                else
                    truevec[vec[i]] = 2;
            }
            l = id;
        }
        else
        {
            range(i, r+1, id + 1, 1)
            {
                if (truevec[vec[i]])
                    continue;
                else
                    truevec[vec[i]] = 2;
            }
            r = id;
        }
        ll t = 0;
        while (truevec[cp])
        {
            if (truevec[cp] == 2)
                truevec[cp] = 1, t++;
            cp++;
        }
        tp += t*(t-1)/2;
    }   
    return tp; 
}
ll mex(vi vf)
{
    sort(all(vf)); 
    ll u = 0; 
    range(i, vf.size())
    {
        if(vf[i] == u) {
            u++; 
        }
        else break; 
    }
    return u; 
}
ll brute(vi vec)
{
    ll n = vec.size(); 
    ll ans = 0; 
    for(ll i = 0; i < n; i++)
    {
        for(ll j = i+1; j < n; j++)
        {
            vi matcher1, matcher2; 
            for(ll k = 0; k < n; k++)
            {
                vi vf; 
                for(ll l = k; l < n; l++)
                {
                    vf.push_back(vec[l]); 
                    matcher1.push_back(mex(vf)); 
                }
            }
            swap(vec[i], vec[j]); 
            for(ll k = 0; k < n; k++)
            {
                vi vf; 
                for(ll l = k; l < n; l++)
                {
                    vf.push_back(vec[l]); 
                    matcher2.push_back(mex(vf)); 
                }
            }
            if(matcher1 == matcher2) {
                ans++; 
            }
            swap(vec[i], vec[j]); 
        }
    }
    return ans; 
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    while(true)
    {
        ll n = rand() % 6 + 1;
        vi vec(n); 
        range(i, n)
        {
            vec[i] = i; 
        }
        // vec = {0, 1, 2, 3};
        shuffle(vec.begin(), vec.end(), default_random_engine(1));  
        ll ans1 = func(vec); 
        ll ans2 = brute(vec); 
        if(ans1 != ans2){
            brute(vec); 
            db(vec); 
            return 0; 
        }
    }
}
