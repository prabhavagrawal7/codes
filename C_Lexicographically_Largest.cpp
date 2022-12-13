// #include "bits/stdc++.h"
// using namespace std;
// #define ll int64_t

// // Uncomment them for optimisations
// // #pragma GCC optimize("Ofast")
// // #pragma GCC target("avx2")

// // for segment tree
// // #define mid (start+end)/2
// // #define lnode (node*2+1)
// // #define rnode (node*2+2)

// #define print(...) cout << __VA_ARGS__ << endl

// #define popcount(x) __builtin_popcountll(x)
// #define clz(x) (63 - __builtin_clzll(x)) // count leading zeros
// #define ctz(x) __builtin_ctzll(x)        // count trailing zeros
// #define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
// #define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
// #define r4(var, start, stop, step) for (ll var = start; step > 0 ? var < stop : var > stop; var = var + step)
// #define r3(var, start, stop) for (ll var = start; var < stop; ++var)
// #define r2(var, stop) for (ll var = 0; var < stop; ++var)
// #define r1(stop) for (ll start_from_0 = 0; start_from_0 < stop; ++start_from_0)
// #define newint(...) \
//     ll __VA_ARGS__; \
//     take_input(__VA_ARGS__)
// #define min(...) min({__VA_ARGS__})
// #define max(...) max({__VA_ARGS__})
// #define give(...)           \
//     do                      \
//     {                       \
//         print(__VA_ARGS__); \
//         return;             \
//     } while (false)
// #define endl "\n"
// #define FULL_INF numeric_limits<double>::infinity()
// #define INF INT64_MAX
// #define INT_INF INT32_MAX
// #define ld long double
// #define V vector
// #define P pair
// #define S set
// #define MS multiset
// #define M map
// #define UM unordered_map
// #define US unordered_set
// #define MM multimap
// #define mt make_tuple
// #define mp make_pair
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define all(a) a.begin(), a.end()
// #define db(x) cout << #x << " = " << x << "\n"
// string db_bin(ll n)
// {
//     string ans;
//     while (n)
//     {
//         ans.push_back((n & 1) + '0');
//         n >>= 1;
//     }
//     reverse(all(ans));
//     return ans;
// }
// #define newstring(str) \
//     string str;        \
//     cin >> str;
// #define foreach(a, x) for (auto &&a : x)
// const ld pi = acos(-1);
// typedef vector<string> vs;
// typedef pair<ll, ll> pii;
// typedef vector<ll> vi;
// typedef map<ll, ll> mii;
// typedef set<ll> si;
// typedef vector<vector<ll>> vvi;
// template <typename... T>
// inline void take_input(T &&...args) { ((cin >> args), ...); }
// vi inputvec(ll n, ll start = 0)
// {
//     vi vec(n);
//     range(i, start, n) cin >> vec[i];
//     return vec;
// }
// template <typename T>
// inline bool btn(T a, T b, T c)
// {
//     if ((a <= b && b <= c) || (a >= b && b >= c))
//         return true;
//     return false;
// }
// template <typename T>
// istream &operator>>(istream &is, V<T> &v)
// {
//     range(i, v.size()) { is >> v[i]; }
//     return is;
// }
// inline ld TLD(ll n) { return n; }
// ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
// const ll mod = 1000000007;
// // const ll mod = 998244353;
// inline ll rs(ll n) { return (n %= mod) >= 0 ? n : n + mod; }
// // define rll above this
// #ifndef __RLL__
// ll power(ll x, ll y)
// {
//     x %= mod, y %= mod - 1;
//     ll res = 1;
//     while (y)
//     {
//         if (y & 1LL)
//             res = (res * x) % mod;
//         y >>= 1;
//         x = (x * x) % mod;
//     }
//     return res % mod;
// }
// ll inv(ll n) { return power(n, mod - 2); }
// #endif
// /* ----------------------------------------------------------------------------------------------*/
// struct seg
// {
// #define mid ((start + end) >> 1)
// #define lnode (node * 2 + 1)
// #define rnode (node * 2 + 2)
//     struct store
//     {
//         ll maxi, lazy;
//         store(ll a = 0, ll b = 0) : maxi(a), lazy(b) {}
//     };
//     V<store> tree;
//     ll n;
//     seg(ll n)
//     {
//         this->n = n;
//         tree.assign(1LL << (clz(n) + 2), {0, 0});
//     }
//     void push(ll node, ll start, ll end)
//     {
//         // critical
//         tree[lnode].lazy += tree[node].lazy;
//         tree[rnode].lazy += tree[node].lazy;
//         tree[lnode].maxi += tree[node].lazy;
//         tree[rnode].maxi += tree[node].lazy;
//         tree[node].lazy = 0;
//     }
//     store opr(store &a, store &b)
//     {
//         // critical
//         return store{max(a.maxi, b.maxi), 0};
//     }
//     void update(ll l, ll r, ll val, ll node, ll start, ll end)
//     {
//         if (r < start || end < l)
//             return;
//         else if (l <= start && end <= r)
//         {
//             // critical
//             tree[node].maxi += val;
//             tree[node].lazy += val;
//             return;
//         }
//         push(node, start, end);
//         update(l, r, val, lnode, start, mid);
//         update(l, r, val, rnode, mid + 1, end);
//         tree[node] = opr(tree[lnode], tree[rnode]);
//     }
//     ll findMaximumValueIndex(ll value, ll node, ll start, ll end)
//     {
//         if (start == end)
//         {
//             return start;
//         }
//         push(node, start, end);
//         if (tree[lnode].maxi == value)
//         {
//             return findMaximumValueIndex(value, lnode, start, mid);
//         }
//         else
//         {
//             return findMaximumValueIndex(value, rnode, mid + 1, end);
//         }
//     }
//     ll findValueonidx(ll idx, ll node, ll start, ll end)
//     {
//         if (start == end)
//         {
//             return tree[node].maxi;
//         }
//         push(node, start, end);
//         if (idx <= mid)
//         {
//             return findValueonidx(idx, lnode, start, mid);
//         }
//         else
//         {
//             return findValueonidx(idx, rnode, mid + 1, end);
//         }
//     }
// };
// void func()
// {
//     newint(n);
//     vi vec = inputvec(n);
//     seg tree(n);
//     vi ans;
//     range(i, n)
//     {
//         tree.update(i, i, vec[i] + i + 1, 0, 0, n - 1);
//     }
//     range(i, n)
//     {
//         ll idx = tree.findMaximumValueIndex(tree.tree[0].maxi, 0, 0, n - 1);
//         range(j, idx, n)
//         {
//             ll temp = tree.findValueonidx(j, 0, 0, n - 1);
//             ans.push_back(temp);
//             tree.update(j, j, -temp, 0, 0, n - 1);
//             tree.update(j, n-1, -1, 0, 0, n - 1);
//         }
//     }
//     range(i, n)
//     {
//         cout << ans[i] << " ";
//     }
// }
// int main()
// {
//     FAST;
//     newint(t);
//     range(t)
//     {
//         func();
//     }
// }


#include "bits/stdc++.h"
using namespace std;
#define ll int64_t

// Uncomment them for optimisations
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)

#define print(...) cout << __VA_ARGS__ << endl

#define popcount(x) __builtin_popcountll(x)
#define clz(x) (63 - __builtin_clzll(x)) // count leading zeros
#define ctz(x) __builtin_ctzll(x)        // count trailing zeros
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
#define r4(var, start, stop, step) for (ll var = start; step > 0 ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (ll var = start; var < stop; ++var)
#define r2(var, stop) for (ll var = 0; var < stop; ++var)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 < stop; ++start_from_0)
#define newint(...) \
    ll __VA_ARGS__; \
    take_input(__VA_ARGS__)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define give(...)           \
    do                      \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    } while (false)
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
#define ppb pop_back
#define pf push_front
#define ppf pop_front
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
istream &operator>>(istream &is, V<T> &v)
{
    range(i, v.size()) { is >> v[i]; }
    return is;
}
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
const ll mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n %= mod) >= 0 ? n : n + mod; }
// define rll above this
#ifndef __RLL__
ll power(ll x, ll y)
{
    x %= mod, y %= mod - 1;
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
ll inv(ll n) { return power(n, mod - 2); }
#endif
/* ----------------------------------------------------------------------------------------------*/
struct seg
{
#define mid ((start + end) >> 1)
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
    struct store
    {
        ll maxi, lazy;
        store(ll a = 0, ll b = 0) : maxi(a), lazy(b) {}
    };
    V<store> tree;
    ll n;
    seg(ll n)
    {
        this->n = n;
        tree.assign(1LL << (clz(n) + 2), {0, 0});
    }
    void push(ll node, ll start, ll end)
    {
        // critical
        tree[lnode].lazy += tree[node].lazy;
        tree[rnode].lazy += tree[node].lazy;
        tree[lnode].maxi += tree[node].lazy;
        tree[rnode].maxi += tree[node].lazy;
        tree[node].lazy = 0;
    }
    store opr(store &a, store &b)
    {
        // critical
        return store{max(a.maxi, b.maxi), 0};
    }
    void update(ll l, ll r, ll val, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return;
        else if (l <= start && end <= r)
        {
            // critical
            tree[node].maxi += val;
            tree[node].lazy += val;
            return;
        }
        push(node, start, end);
        update(l, r, val, lnode, start, mid);
        update(l, r, val, rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
    }
    ll findMaximumValueIndex(ll value, ll node, ll start, ll end)
    {
        if (start == end)
        {
            return start;
        }
        push(node, start, end);
        if (tree[lnode].maxi == value)
        {
            return findMaximumValueIndex(value, lnode, start, mid);
        }
        else
        {
            return findMaximumValueIndex(value, rnode, mid + 1, end);
        }
    }
    ll findValueonidx(ll idx, ll node, ll start, ll end)
    {
        if (start == end)
        {
            return tree[node].maxi;
        }
        push(node, start, end);
        if (idx <= mid)
        {
            return findValueonidx(idx, lnode, start, mid);
        }
        else
        {
            return findValueonidx(idx, rnode, mid + 1, end);
        }
    }
};
template <typename T>
ostream &operator<<(ostream &os, V<T> &v)
{
    for (auto &&i : v)
    {
        os << i << " ";
    }
    return os;
}
void func()
{
    newint(n);
    vi vec = inputvec(n);
    range(i, vec.size()) vec[i] += i + 1; 
    set<ll> store; 
    sort(all(vec)); 
    vi ans; 
    range(i, n-1, -1, -1)
    {
        ll a = vec[i]; 
        if(store.count(a))
        {
            a = *store.begin() - 1; 
        }
        store.insert(a);
        ans.push_back(a);
    }
    print(ans); 
}
int main()
{
    FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
