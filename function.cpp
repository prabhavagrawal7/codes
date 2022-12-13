#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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
#define INF LONG_LONG_MAX
#define INT_INF INT_MAX
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

// lis -- longest increasing subsequence
ll lis(vi &height)
{
    vi s; 
    range(i, height.size())
    {
        auto a = lower_bound(all(s), height[i]); 
        if (a == s.end())
            s.push_back(height[i]);
        else
            *a = height[i]; 
    }
    return s.size();
}

ll power(ll x, ll y)
{
    x = x % mod;
    ll res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x) % mod;

        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
}
vector<ll> randvec(ll n, ll start = 0, ll end = 10)
{
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        arr[i] = rand() % (end - start + 1) + start;
    return arr;
}
ll randint(ll start, ll end)
{
    return rand() % (end - start + 1) + start;
}

ll inv(ll n) { return power(n, mod - 2); }
ll NCR(ll n, ll r)
{
    auto inv = [](ll n)
    { return power(n, mod - 2); };
    if (r > n || r < 0)
        return 0;
    static vi mul = {1};
    range(i, mul.size(), n + 1)
    {
        mul.push_back(rs(mul[i - 1] * i));
    }
    return rs(mul[n] * rs(inv(mul[r]) * inv(mul[n - r])));
}

//      inttobinary
vi inttobinary(ll n)
{
    vi binary(63);
    for (ll i = 0; i < 63; i++)
    {
        binary[i] = (n & 1); 
        n >>= 1LL;
    }
    return binary;
}
//      binarytoint
ll binarytoint(vi &&num)
{
    ll ans = 0; 
    for(int i = num.size()-1; i >= 0; i--)
    {
        ans <<= 1; 
        ans ^= num[i]; 
    }
    return ans; 
}

//      TO FIND NO OF PRIME FACTORS OF A NUMBER
ll noOfFactors(ll n)
{
    ll ans = 0; // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        ans++;
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i * i <= n; i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            ans++;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        ans++;
    return ans;
}

//      sieve starts here |sieve modified to provide smallest factors of a number|
const ll range = 1000006;
vi prime(range + 1, 1);
void sieve()
{
    for(int p = 0; p < range; ++p) prime[p] = p;
    for (int p = 2; p * p <= range; ++p)
    {
        if (prime[p] == p)
        {
            for (int i = p * p; i <= range; i += p)
                if (prime[i] == i)
                    prime[i] = p;
        }
    }
}

//      to find using segment tree

struct seg
{
#define mid (start + end) / 2
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
    vi vec;
    vi tree;
    ll n;
    ll opr(ll a, ll b)
    {
        // critical
        return a + b;
    }
    seg(vi v)
    {
        vec = v;
        tree.assign(vec.size() * 4, 0);
        n = vec.size();
        buildtree(0, 0, n - 1);
    }
    void buildtree(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = vec[start];
            return;
        }
        buildtree(lnode, start, mid);
        buildtree(rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
        return;
    }
    ll rangefind(ll l, ll r)
    {
        return rangefind(l, r, 0, 0, n - 1);
    }
    ll rangefind(ll l, ll r, ll node, ll start, ll end)
    {
        // l-r-start-end | start-end-l-r
        // critical
        if (r < start || end < l)
            return 0;
        // l-start-end-r
        if (l <= start && end <= r)
            return tree[node];
        else
            return opr(rangefind(l, r, lnode, start, mid), rangefind(l, r, rnode, mid + 1, end));
    }
    void update(ll ind, ll val)
    {
        update(ind, val, 0, 0, n - 1);
    }
    void update(ll ind, ll val, ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }
        if (ind <= mid)
            update(ind, val, lnode, start, mid);
        else
            update(ind, val, rnode, mid + 1, end);
        tree[node] = opr(tree[lnode], tree[rnode]);
    }
};

// find factors of given number (heavy preprocessing)
const ll limit = 1e6;
V<vi> factors(limit + 1);
void find_factors()
{
    // range(i, factors.size()) {factors[i].reserve(20);}
    range(i, 2, limit)
    {
        for (ll j = i * i; j < limit; j += i)
        {
            factors[j].push_back(i);
        }
    }
}

// lazy propogation
struct seg
{
#define mid (start + end) / 2
#define lnode (node * 2 + 1)
#define rnode (node * 2 + 2)
    V<vi> tree;
    seg(ll n)
    {
        tree.assign(1 << (clz(n) + 2), {0, 1, 0});
    }
    void push(ll node, ll start, ll end)
    {
        if (tree[node][1] == 0)
        {
            // assign
            tree[lnode][1] = 0, tree[rnode][1] = 0;
            tree[lnode][2] = tree[node][2], tree[rnode][2] = tree[node][2];
            tree[lnode][0] = tree[lnode][2] * (mid - start + 1);
            tree[rnode][0] = tree[rnode][2] * (end - (mid + 1) + 1);
        }
        else
        {
            // update
            tree[lnode][2] += tree[node][2], tree[rnode][2] += tree[node][2];
            tree[lnode][0] += tree[node][2] * (mid - start + 1);
            tree[rnode][0] += tree[node][2] * (end - (mid + 1) + 1);
        }
        tree[node][1] = 1, tree[node][2] = 0;
    }
    void update(ll l, ll r, ll type, ll val, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return;
        else if (l <= start && end <= r)
        {
            if (type == 0)
                tree[node] = {(end - start + 1) * val, type, val};
            else
            {
                tree[node][0] += (end - start + 1) * val;
                tree[node][2] += val;
            }
            return;
        }
        push(node, start, end);
        update(l, r, type, val, lnode, start, mid);
        update(l, r, type, val, rnode, mid + 1, end);
        tree[node][0] = tree[lnode][0] + tree[rnode][0];
    }
    ll rfind(ll l, ll r, ll node, ll start, ll end)
    {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
        {
            return tree[node][0];
        }
        push(node, start, end);
        return rfind(l, r, lnode, start, mid) +
               rfind(l, r, rnode, mid + 1, end);
    }
};

// lps/longest prefix suffix
vector<ll> get_lps(string s)
{
    vector<ll> lps(s.size(), -1);
    ll lptr = -1, rptr = 0;
    while (true)
    {
        if (rptr == s.size())
            break;
        if (s[lptr + 1] == s[rptr + 1])
        {
            lps[rptr + 1] = lptr + 1;
            lptr++;
            rptr++;
        }
        else if (lptr != -1 && s[lptr + 1] != s[rptr + 1])
            lptr = lps[lptr];
        else
        {
            lps[rptr + 1] = -1;
            rptr++;
        }
    }
    return lps;
}
// string matching algo, requires lps table
bool match(string bigstr, string smallstr)
{
    if (smallstr.size() > bigstr.size())
        return 0;
    ll i = -1, j = -1;
    ll n = bigstr.size(), m = smallstr.size();
    vector<ll> lps = get_lps(smallstr);
    while (i + 1 < n && j + 1 < m)
    {
        if (bigstr[i + 1] == smallstr[j + 1])
            i++, j++;
        else if (j != -1 && bigstr[i + 1] != smallstr[j + 1])
            j = lps[j];
        else
            i++;
    }
    return j == m - 1;
}

// hash
pii nexthash(pii oldhash, char ch)
{
    oldhash.first *= 257, oldhash.second *= 257;
    oldhash.first += ch, oldhash.second += ch;
    oldhash.first %= 1000000009;
    oldhash.second %= 252097800623;
    return oldhash;
}