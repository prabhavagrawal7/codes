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
ostream& operator<<(ostream& os, const V<T>& v)
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
//      to find using segment tree

class SegmentTree
{
private:
    vi tree;
    vi vec;
    // change operation here
    inline ll opr(ll a, ll b)
    {
        return a + b;
    }
    ll constructTree(ll start, ll end, ll ind)
    {
        if (start == end) return tree[ind] = vec[start];
        // change operator here
        return tree[ind] = opr(constructTree(start, (start + end) / 2, ind * 2 + 1),
            constructTree(1 + (start + end) / 2, end, ind * 2 + 2));
    }

public:
    SegmentTree(vi& vec)
    {
        ll n = vec.size();
        tree = vi(vec.size() * 4 + 10);
        this->vec = vec;
        constructTree(0, vec.size() - 1, 0);
    }

    ll rangeFind(ll start, ll end, ll index = 0, ll fullstart = -1, ll fullend = -1)
    {
        if (fullstart == -1)
            fullstart = 0, fullend = vec.size() - 1;
        if (start == fullstart && end == fullend)
            return tree[index];
        ll mid = (fullstart + fullend) / 2;
        if (btn(fullstart, end, mid))
        {
            return rangeFind(start, end, index * 2 + 1, fullstart, mid);
        }
        if (btn(mid + 1, start, fullend))
        {
            return rangeFind(start, end, index * 2 + 2, mid + 1, fullend);
        }
        else
        {

            return opr(rangeFind(start, mid, index * 2 + 1, fullstart, mid),
                rangeFind(mid + 1, end, index * 2 + 2, mid + 1, fullend));
        }
    }
    void changeElement(ll index, ll newelement)
    {
        ll fullstart = 0, fullend = vec.size() - 1;
        ll treeindex = 0;
        vec[index] = newelement;

        // going to all the indexes
        while (true)
        {
            if (btn(fullstart, index, (fullstart + fullend) / 2))
            {
                fullend = (fullstart + fullend) / 2;
                treeindex = treeindex * 2 + 1;
            }
            else
            {
                fullstart = 1 + (fullstart + fullend) / 2;
                treeindex = treeindex * 2 + 2;
            }
            if (fullstart == fullend)
                break;
        }
        tree[treeindex] = newelement;
        // update all parents
        while (true)
        {
            treeindex = treeindex & 1 ? treeindex / 2 : treeindex / 2 - 1;
            if (treeindex < 0)
                break;
            tree[treeindex] = opr(tree[treeindex * 2 + 1], tree[treeindex * 2 + 2]);
        }
    }
};

void func()
{
    newint(n);
    newstring(str);
    if (n % 2 != 0)
    {
        give("NO");
    }
    map<char, ll> x;
    foreach(i, str)
    {
        x[i]++;
    }
    set<pair<ll, char>> store;
    foreach(i, x)
    {
        pii u = i;
        swap(u.first, u.second);
        store.insert(u);
    }
    ll i = 0;
    string ans(n, 'a');
    while (store.size())
    {
        auto c1 = *store.begin();
        auto c2 = *prev(store.end());
        if (c1 == c2)
        {
            give("NO");
        }
        store.erase(c1), store.erase(c2);
        ans[i] = c1.second, ans[n - i - 1] = c2.second;
        c1.first--, c2.first--;
        if (c1.first != 0)
            store.insert(c1);
        if (c2.first != 0)
            store.insert(c2);
        i++;
    }
    print("YES");
    print(ans);
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
