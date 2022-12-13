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
    ll n;
    // change operation here
    inline ll opr(ll a, ll b)
    {
        return (a ^ b);
    }
    inline ll mid(ll start, ll end)
    {
        return (start + end) / 2;
    }
    void constructTree(ll start, ll end, ll ind)
    {
        if (start == end)
        {
            tree[ind] = vec[start];
            return;
        }
        else
        {
            ll mid = this->mid(start, end);
            constructTree(start, mid, ind * 2 + 1);
            constructTree(mid + 1, end, ind * 2 + 2);
        }
    }

public:
    SegmentTree(vi &vec)
    {
        this->n = vec.size();
        tree = vi(vec.size() * 4 + 10);
        this->vec = vec;
        constructTree(0, vec.size() - 1, 0);
    }

    ll findelement(ll ind)
    {
        ll treeindex = 0;
        ll part1 = 0, part2 = n - 1;
        ll ans = 0;
        while (true)
        {
            ll mid = this->mid(part1, part2);
            if (part1 == part2)
            {
                ans += tree[treeindex];
                return ans;
            }
            if (btn(part1, ind, mid))
            {
                ans += tree[treeindex];
                treeindex = treeindex * 2 + 1;
                part2 = mid;
            }
            else
            {
                ans += tree[treeindex];
                treeindex = treeindex * 2 + 2;
                part1 = mid + 1;
            }
        }
        return 0;
    }
    void changeElement(ll fromindex, ll toindex, ll increment, ll part1 = -1,
                       ll part2 = -1, ll treeindex = 0)
    {
        if (part1 == -1)
            part1 = 0, part2 = n - 1;
        if (fromindex == part1 && toindex == part2)
        {
            tree[treeindex] += increment;
            return;
        }

        ll mid = this->mid(part1, part2);
        // debug
        if(mid > part2)
        {
            db(mid); db(part2);
        }
        
        
        if (btn(part1, toindex, mid))
        {
            changeElement(fromindex, toindex, increment, part1, mid, treeindex * 2 + 1);
        }
        else if (btn(mid + 1, fromindex, part2))
        {
            changeElement(fromindex, toindex, increment, mid + 1, part2, treeindex * 2 + 2);
        }
        else
        {
            changeElement(fromindex, mid, increment, part1, mid, treeindex * 2 + 1);
            changeElement(mid + 1, toindex, increment, mid + 1, part2, treeindex * 2 + 2);
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
        newint(x);
        if (x == 1)
        {
            newint(from, to, inc);
            seg.changeElement(from-1, to-1, inc);
        }
        else
        {
            newint(ind);
            print(seg.findelement(ind - 1));
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
