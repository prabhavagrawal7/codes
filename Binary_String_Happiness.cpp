#include "bits/stdc++.h"
using namespace std;
#define ll long long

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

// for segment tree
#define mid (start + end) / 2
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
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
class stree
{
public:
    vi converter(string &str)
    {
        ll suff = 0, pref = 0, tempsuff = 0, temppref = 0, sum = 0;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] == '1')
                tempsuff++;
            else
                tempsuff--;
            suff = max(suff, tempsuff);
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '1')
                temppref++;
            else
                temppref--;
            pref = max(pref, temppref);
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '1')
                sum++;
            else
                sum--;
        }
        return {suff, pref, sum};
    }

    // either be prefix or suffix or inside or none of these
    void challengesuff(vi &suff, vi &challenge)
    {
        if (suff[0] + challenge[2] > challenge[0] + suff[2])
        {
            swap(suff[0], challenge[0]);
            swap(suff[1], challenge[1]);
            swap(suff[2], challenge[2]);
        }
    }

    void challengepref(vi &pref, vi &challenge)
    {
        if (pref[1] + challenge[3] > challenge[5] + pref[2])
        {
            swap(pref[0], challenge[4]);
            swap(pref[1], challenge[5]);
            swap(pref[2], challenge[6]);
        }
    }

    vi opr(vi a, vi b)
    {

        if (a.size() < b.size())
            swap(a, b);
        if (b.size() == 0)
            return a;
        if (a.size() == 1 && b.size() == 1)
        {
            V<vi> contenders = {{a[0], a[1], a[2], 0, b[0], b[1], b[2]},
                                {b[0], b[1], b[2], 0, a[0], a[1], a[2]}};
            if (contenders[0][0] + contenders[0][6] < contenders[1][0] + contenders[1][6])
                return contenders[1];
            else
                return contenders[0];
        }
        else if (a.size() == 1 && b.size() > 1)
        {
            challengepref(a, b);
            challengesuff(a, b);
            if (a[2] < 0)
                return b;
            else
            {
                b[3] += a[2];
                return b;
            }
        }
        else
        {
            vi ans = {0, 0, 0, a[3] + b[3], 0, 0, 0};
            V<vi> challengers = {{a[0], a[1], a[2]},
                                 {a[4], a[5], a[6]},
                                 {b[0], b[1], b[2]},
                                 {b[4], b[5], b[6]}};
            foreach (i, challengers)
            {
                challengepref(i, ans);
                challengesuff(i, ans);
            }
            foreach (i, challengers)
            {
                if (i[2] > 0)
                    ans[3] += i[2];
            }
            return ans;
        }
    }
    V<vi> tree;
    V<string> vstr;
    ll n;
    void buildtree(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = converter(vstr[start]);
            return;
        }
        buildtree(lnode, start, mid);
        buildtree(rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
        return;
    }
    stree(V<string> vstr)
    {
        this->vstr = move(vstr);
        n = this->vstr.size();
        tree.assign(n * 4, vi());
        buildtree(0, 0, n - 1);
    }
    ll rangefind(ll l, ll r)
    {
        auto ans = rangefind(l, r, 0, 0, n - 1);
        if (ans.size() == 7)
            return ans[0] + ans[3] + ans[6];
        else if (ans.size() == 3)
            return ans[0] + ans[1] + ans[2];
    }
    vi rangefind(ll l, ll r, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return vi(0);
        else if (l <= start && end <= r)
        {
            return tree[node];
        }
        else
            return opr(rangefind(l, r, lnode, start, mid),
                       rangefind(l, r, rnode, mid + 1, end));
    }
};
void func()
{
    newint(n, q);
    V<string> vstr;
    range(i, n)
    {
        newstring(str);
        vstr.push_back(str);
    }
    stree seg(vstr);
    range(q)
    {
        newint(l, r);
        print(seg.rangefind(l - 1, r - 1));
    }
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    func();
}
