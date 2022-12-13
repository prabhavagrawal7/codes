#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
#define cntpop(x) __builtin__popcount(x)
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...)                         \
    GET_MACRO(__VA_ARGS__, r4, r3, r2, r1) \
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
#define INF LONG_LONG_MAX
#define INT_INF INT_MAX
#define ll long long
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
//const ll mod = 998244353;
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
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
typedef map<ll, ll> mii;
typedef set<ll> si;
template <typename... T>
void take_input(T &&...args) { ((cin >> args), ...); }
ll input()
{
    newint(n);
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
template <typename... T>
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
inline ll gcd(ll m, ll n) { return __gcd(m, n); }
inline ll rs(ll n) { return n % mod; }

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
vi vectorize(V<ld> &vec)
{
    ll n = vec.size();
    V<pair<ld, ll>> vec1(vec.size());
    range(i, vec.size())
    {
        vec1[i] = mp(vec[i], i);
    }
    map<ld, ld> s;

    sort(all(vec1));

    vi ans(n);
    range(i, n)
    {
        ans[vec1[i].second] = i + 1;
    }
    return ans;
}
vi func(ll n, ll k, vi ivec)
{
    vi safevec;
    V<ld> vec;
    range(i, n)
    {
        ll x = ivec[i];
        safevec.push_back(x);
        vec.push_back(x);
    }
    map<ld, ll> freq;
    range(i, n)
    {
        ll lot_big = 0, comp_big = 0, lot_small = 0;
        range(j, 1, k + 1)
        {
            ll p = (i + j) % n;
            if (vec[i] > vec[p] + 0.5)
                lot_small++;
            else if (vec[i] + 0.5 < vec[p])
                lot_big++;
            else
                comp_big++;
        }
        if (lot_small + comp_big < safevec[i] || lot_small > safevec[i])
        {
            return vi(1, -1);
        }
        range(j, 1, k + 1)
        {
            ll p = (i + j) % n;
            if (safevec[i] == safevec[p])
            {
                if (safevec[i] - lot_small >= comp_big)
                    vec[p] -= 0.000001, comp_big--;
                else
                    vec[p] += 0.000001;
            }
        }
    }
    auto Nvec = vectorize(vec);
    range(i, n)
    {
        ll tot = 0;
        range(j, 1, k + 1)
        {
            ll p = (i + j) % n;
            if (Nvec[p] < Nvec[i])
                tot++;
        }
        if (tot != safevec[i])
        {
            return vi(1, -1);
        }
    }
    return Nvec;
}
vi conv(vi vec, ll k)
{
    ll n = vec.size();
    vi ans(vec.size());
    range(i, n)
    {
        range(j, 1, k + 1)
        {
            ll p = (i + j) % n;
            if (vec[p] < vec[i])
                ans[i]++;
        }
    }
    return ans;
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    // newint(t);
    // range(t)
    vi vec = {1, 2, 3, 4, 5, 6};

    while (true)
    {
        auto newvec = conv(vec, 4);
        auto v = func(vec.size(), 4, newvec);
        if (v != vec)
        {
            func(vec.size(), 4, newvec); 
            db(v);
            db(vec);
            db(newvec);
            break;
        }
        next_permutation(all(vec));
        if (is_sorted(all(vec)))
            vec.push_back(vec.size() + 1);
    }
}
