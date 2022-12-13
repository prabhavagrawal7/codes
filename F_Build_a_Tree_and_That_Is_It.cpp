#include "bits/stdc++.h"
using namespace std;
#define ll int64_t

// ordered set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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
class rll
{
private:
    int64_t val = 0;

public:
    rll power(rll y)
    {
        rll x = *this;
        rll res = 1;
        while (y)
        {
            if (y % 2 == 1)
                res = (res * x);
            y = y >> 1;
            x = (x * x);
        }
        return res;
    }
    operator int64_t() const { return this->val; }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    rll(T val) { this->val = val; }

    // arithmetic operators
    inline rll operator+(rll a)
    {
        a.val = (this->val + a.val) % mod;
        return a;
    }
    inline rll operator-(rll a)
    {
        a.val = ((this->val - a.val) % mod + mod) % mod;
        return a;
    }
    inline rll operator*(rll a)
    {
        a.val = (a.val * this->val) % mod;
        return a;
    }
    inline rll operator/(rll a) { return a.power(mod - 2) * (*this); }
    inline rll operator%(rll a)
    {
        a.val = (this->val % a.val) % mod;
        return a;
    }
    inline rll operator>>(rll a)
    {
        a.val = (this->val >> a.val) % mod;
        return a;
    }
    inline rll operator<<(rll a)
    {
        a.val = (this->val << a.val) % mod;
        return a;
    }

    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator+(T a) { return *this + rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator-(T a) { return *this - rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator*(T a) { return *this * rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator/(T a) { return *this / rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator%(T a) { return *this % rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator>>(T a) { return *this >> rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator<<(T a) { return *this << rll(a); }

    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator+=(T a) { return *this = *this + rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator-=(T a) { return *this = *this - rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator*=(T a) { return *this = *this * rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator/=(T a) { return *this = *this / rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator>>=(T a) { return *this = *this >> rll(a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline rll operator<<=(T a) { return *this = *this << rll(a); }

    // logical operators
    inline bool operator<(rll a) { return (this->val < a.val); }
    inline bool operator>(rll a) { return (this->val > a.val); }
    inline bool operator<=(rll a) { return (this->val <= a.val); }
    inline bool operator>=(rll a) { return (this->val >= a.val); }
    inline bool operator!() { return !this->val; }

    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline bool operator<(T a) { return (this->val < a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline bool operator>(T a) { return (this->val > a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline bool operator<=(T a) { return (this->val <= a); }
    template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
    inline bool operator>=(T a) { return (this->val >= a); }
};
rll power(rll x, rll y)
{
    rll res = 1;
    while (y)
    {
        if (y & 1LL)
            res = (res * x);
        y = y / 2;
        x = (x * x);
    }
    return res;
}
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
void print_graph(vvi &g)
{
    print("YES"); 
    stack<ll> dfs;
    vi vis (g.size()); 
    dfs.push(1); 
    vis[1] = true; 
    while(dfs.size()) 
    {
        ll x= dfs.top(); 
        dfs.pop(); 
        foreach(i, g[x])
        {
            if(vis[i]) continue;
            print(x, i); 
            dfs.push(i); 
            vis[i] = true; 
        }
    }
    return; 
}
void func()
{
    newint(n, x1, x3, x2);
    vi check = {x1, x2, x3};
    sort(all(check));
    if (check[0] + check[1] < check[2])
    {
        give("NO");
    }
    if ((x1 + x2 - x3) % 2 || (x1 + x3 - x2) % 2 || (x2 + x3 - x1) % 2)
    {
        give("NO");
    }
    ll u = (x1 + x2 - x3) / 2;
    ll v = (x1 + x3 - x2) / 2;
    ll w = (x2 + x3 - x1) / 2;
    set<pii> nodes = {{u, 1}, {v, 2}, {w, 3}};
    if(nodes.begin()->first == 0 && next(nodes.begin())->first == 0) {give("NO"); }
    vi vis(n + 1);
    ll cnode = -1;
    if (nodes.begin()->first == 0)
    {
        cnode = nodes.begin()->second;
        nodes.erase(nodes.begin());
        vis[cnode] = 1;
    }
    else if (n >= 4)
    {
        cnode = 4;
        vis[cnode] = 1;
    }
    else
    {
        give("NO");
    }

    vvi g(n + 1);
    si contenders;
    range(i, 4, n + 1)
    {
        if (vis[i] == 0)
            contenders.insert(i);
    }
    foreach (node, nodes)
    {
        ll depth = 0;
        auto ccnode = cnode;
        while (depth + 1 != node.first && contenders.size())
        {
            ll con = *contenders.begin();
            g[ccnode].push_back(con);
            g[con].push_back(ccnode);
            vis[con] = 1;
            contenders.erase(con);
            ccnode = con;
            depth++;
        }
        if (depth + 1 == node.first)
        {
            vis[node.second] = 1;
            g[ccnode].pb(node.second);
            g[node.second].pb(ccnode);
        }
    }

    if (vis[1] == 0 || vis[2] == 0 || vis[3] == 0)
    {
        give("NO");
    }

    vis.assign(n + 1, 0);
    
    while(contenders.size())
    {
        ll ncnode = *contenders.begin(); 
        g[cnode].pb(ncnode); 
        g[ncnode].pb(cnode); 
        cnode = ncnode; 
        contenders.erase(ncnode); 
    }
    print_graph(g); 

}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    range(t)
    {
        func();
    }
}


/* 
9
5 1 2 1
5 2 2 2
5 2 2 3
5 2 2 4
5 3 2 3
4 2 1 1
4 3 1 1
4 1 2 3
7 1 4 1
 */