#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

#define mid (start + end) / 2
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)

template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os
        << "[" << p.first << "," << p.second << "]";
    return os;
}
template <typename T, typename = void>
struct is_iterable : false_type
{
};
template <typename T>
struct is_iterable<T, void_t<decltype(begin(declval<T &>())), decltype(end(declval<T &>()))>> : true_type
{
};
template <typename T>
using is_string = is_same<decay_t<T>, string>;
template <typename T>
constexpr bool is_iterable_v = is_iterable<T>::value;
template <typename T>
typename enable_if<!is_iterable_v<T>, void>::type
__print(T &&container) { cout << container; }
template <typename T>
typename enable_if<is_iterable_v<T> && !is_string<T>::value, void>::type __print(T &&container)
{
    for (auto
             itr = container.begin();
         itr != container.end(); itr++)
    {
        __print(*itr);
        if (next(itr) != container.end())
            cout << ' ';
    }
}
template <typename T>
typename enable_if<is_string<T>::value, void>::type
__print(T &&string_container) { cout << string_container; }
template <typename T>
typename enable_if<is_same<T, const char *>::value, void>::type __print(T &&string_container) { cout << string_container; }
template <size_t N>
void __print(const char (&str)[N]) { cout << str; }
template <typename... T>
inline void print(T &&...args)
{
    ((__print(args), cout << " "), ...);
    cout << endl;
}
template <typename... T>
inline void printl(T &&...args) { ((__print(args), cout
                                                       << " "),
                                   ...); }

#define popcount(x) __builtin_popcountll(x)
#define clz(x) (63 - __builtin_clzll(x))
#define ctz(x) __builtin_ctzll(x)
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

inline ll rs(ll n) { return (n %= mod) >= 0 ? n : n + mod; }

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

class segtree
{
public:
    vvi tree;
    ll n;
    vi arr;
    segtree(vi &arr)
    {
        this->n = arr.size();
        tree.assign(4 * n, vi(2, INT_INF));
        this->arr = arr;
        buildtree(0, 0, n - 1);
    }

    void buildtree(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = {arr[start], start};
            return;
        }
        buildtree(lnode, start, mid);
        buildtree(rnode, mid + 1, end);
        tree[node] = min(tree[lnode], tree[rnode]);
    }
    vi findMinIdx(ll l, ll r, ll node, ll start, ll end)
    {
        if (l > end || r < start)
            return {INT_INF, -1};
        if (l <= start && end <= r)
            return tree[node];
        return min(findMinIdx(l, r, lnode, start, mid), findMinIdx(l, r, rnode, mid + 1, end));
    }
};
void func()
{
    newint(n);
    vi vec = inputvec(n);
    vi target = inputvec(n);

    V<pii> store(n, {-1, -1});
    mii values;
    range(i, n)
    {
        while (values.size() && prev(values.end())->first < vec[i])
        {
            values.erase(prev(values.end()));
        }
        values[vec[i]] = i;
        if (values.count(target[i]))
            store[i].first = values[target[i]];
    }
    values.clear();
    for (ll i = n - 1; i >= 0; --i)
    {
        while (values.size() && prev(values.end())->first < vec[i])
        {
            values.erase(prev(values.end()));
        }
        values[vec[i]] = i;
        if (values.count(target[i]))
            store[i].second = values[target[i]];
    }
    range(i, store.size())
    {
        if (store[i].first == -1 && store[i].second == -1)
            give("NO");
    }

    segtree st(target);

    queue<pii> q;
    q.push({0, n - 1});
    while (q.size())
    {
        ll l = q.front().first, r = q.front().second;
        q.pop();
        if (l > r)
            continue;
        auto idx = st.findMinIdx(l, r, 0, 0, n - 1)[1];
        if (!btn(l - 1, store[idx].first, r + 1) && !btn(l - 1, store[idx].second, r + 1))
            give("NO");
        q.push({l, idx - 1});
        q.push({idx + 1, r});
    }
    give("YES");
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
