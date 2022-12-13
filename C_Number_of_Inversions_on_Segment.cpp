#include <bits/stdc++.h>
using namespace std;
#define mid (start + end) / 2
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)

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
// typedef pair<ll, vector<int>> pivi;
struct pivi
{
    ll first;
    vector<int> second;
};
struct stree
{
public:
    vi vec;
    V<pivi> tree;
    ll n;
    inline pivi opr(pivi &a, pivi &b)
    {
        pivi c = {0LL, vector<int>(41, 0)};
        c.first = a.first + b.first;
        range(i, 1, 41)
        {
            range(j, 1, i)
            {
                if (a.second[i] * b.second[j])
                    c.first += 1LL * a.second[i] * b.second[j];
            }
        }
        range(i, 1, 41)
            c.second[i] += b.second[i] + a.second[i];
        return c;
    }
    stree(vi v)
    {
        vec = v;
        ll N = 1;
        while (N < vec.size())
        {
            N = N * 2;
        }
        tree.assign(2 * N, {0LL, vector<int>(41, 0)});
        n = vec.size();
        buildtree(0, 0, n - 1);
    }
    void buildtree(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node].second[vec[start]] = 1;
            return;
        }
        buildtree(lnode, start, mid);
        buildtree(rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
        return;
    }
    ll rangefind(ll l, ll r)
    {
        return rangefind(l, r, 0, 0, n - 1).first;
    }
    pivi rangefind(ll l, ll r, ll node, ll start, ll end)
    {
        // l-r-start-end | start-end-l-r
        // critical
        if (r < start || end < l)
            return {-1LL, vector<int>(1, 0)};
        // l-start-end-r
        if (l <= start && end <= r)
            return tree[node];
        else
        {
            pivi a = rangefind(l, r, lnode, start, mid);
            pivi b = rangefind(l, r, rnode, mid + 1, end);
            if (a.first == -1)
                return b;
            if (b.first == -1)
                return a;
            return opr(a, b);
        }
    }
    void update(ll ind, ll val)
    {
        update(ind, val, 0, 0, n - 1);
    }
    void update(ll ind, ll val, ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node].second[vec[start]] = 0;
            vec[start] = val;
            tree[node].second[vec[start]] = 1;
            return;
        }
        if (ind <= mid)
            update(ind, val, lnode, start, mid);
        else
            update(ind, val, rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
    }
};

void func()
{
    newint(n, q);
    vi vec = inputvec(n);
    stree seg(vec);
    range(q)
    {
        newint(_, u, v);
        if (_ == 1)
        {
            print(seg.rangefind(u - 1, v - 1));
        }
        else
        {
            seg.update(u - 1, v);
        }
    }
}
int main()
{
    // Uncomment for faster I/O
    FAST;
    func();
}
