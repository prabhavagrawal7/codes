#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...)                         \
    GET_MACRO(__VA_ARGS__, r4, r3, r2, r1) \
    (__VA_ARGS__)
#define r4(var, start, stop, step) for (auto var = start; start <= stop ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (auto var = start; var != stop; var++)
#define r2(var, stop) for (ll var = 0; var != stop; var++)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 != stop; start_from_0++)
#define newint(...) \
    ll __VA_ARGS__; \
    take_input(__VA_ARGS__)
using namespace std;
#define endl "\n"
#define FULL_INF numeric_limits<double>::infinity()
#define INF LONG_LONG_MAX
#define INT_INF INT_MAX
#define ll long long
#define ld long double
#define V vector
#define P pair
#define S string
#define MS multiset
#define UM unordered_map
#define US unordered_set
#define MM multimap
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define pf push_front
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define newstring(str) \
    string str;        \
    cin >> str;
const ll mod = 1000000007;
const ll mod2 = 998244353;
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
template <typename... T, typename Q>
inline Q max(Q arg1, T &&...args)
{
    Q ans = arg1;
    ((ans = (args > ans ? args : ans)), ...);
    return ans;
}
template <typename... T, typename Q>
inline Q min(Q arg1, T &&...args)
{
    Q ans = arg1;
    ((ans = (args < ans ? args : ans)), ...);
    return ans;
}
inline ld TLD(ll n) { return n; }
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

class SegmentTree
{
private:
    vi tree;
    vi vec;
    // change operation here
    inline ll opr(ll a, ll b)
    {
        return (a ^ b);
    }
    ll constructTree(ll start, ll end, ll ind)
    {
        if (start == end)
            return tree[ind] = vec[start];
        // change operator here
        return tree[ind] = opr(constructTree(start, (start + end) / 2, ind * 2 + 1),
                               constructTree(1 + (start + end) / 2, end, ind * 2 + 2));
    }

public:
    SegmentTree(vi &vec)
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

ll func()
{
    // write your code here
    newint(a, b);
    vi vec = inputvec(a);
    SegmentTree seg(vec);

    range(b)
    {
        newint(y, z);
        {
            print(seg.rangeFind(y - 1, z - 1));
        }
    }

    return 0;
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    // newint(t);
    // range(t)
    {
        func();
    }
}
