#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
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
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define new_string(str) \
    string str;         \
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
Q max(Q arg1, T &&...args)
{
    Q ans = arg1;
    ((ans = (args > ans ? args : ans)), ...);
    return ans;
}
template <typename... T, typename Q>
Q min(Q arg1, T &&...args)
{
    Q ans = arg1;
    ((ans = (args < ans ? args : ans)), ...);
    return ans;
}
ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n)
{
    while (__n != 0)
    {
        ll __t = __m % __n;
        __m = __n;
        __n = __t;
    }
    return __m;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
ll U(ll x) { return x % 3; }
ll _func(vi &vec)
{
    set<pii> sor;
    range(i, vec.size()) sor.insert({vec[i], i});
    range(i, vec.size() - 2)
    {
        ll pi = i, pj = i + 1, pk = sor.begin()->second;
        if (pi == pk)
        {
            sor.erase(sor.begin());
        }
        else if (pj == pk)
        {
            pii deletepair1 = {vec[pi], pi};
            pii deletepair2 = {vec[pj], pj};
            pk++;
            pii deletepair3 = {vec[pk], pk};
            swap(vec[pi], vec[pj]);
            swap(vec[pj], vec[pk]);
            sor.erase(deletepair1);
            sor.erase(deletepair2);
            sor.erase(deletepair3);
            sor.insert({vec[pj], pj});
            sor.insert({vec[pk], pk});
        }
        else
        {
            pii deletepair1 = {vec[pi], pi};
            pii deletepair2 = {vec[pj], pj};
            pii deletepair3 = {vec[pk], pk};
            swap(vec[pi], vec[pk]);
            swap(vec[pj], vec[pk]);
            sor.erase(deletepair1);
            sor.erase(deletepair2);
            sor.erase(deletepair3);
            sor.insert({vec[pj], pj});
            sor.insert({vec[pk], pk});
        }
    }
    if (vec[vec.size() - 1] >= vec[vec.size() - 2])
        return 1;
    else
        return 0;
}
ll func()
{
    // write your code here
    newint(n);
    vi vec = inputvec(n);
    if (n == 1)
        return 1;
    else if (n == 2)
    {
        if (is_sorted(all(vec)))
            return 1;
        else
            return 0;
    }
    else
    {
        return _func(vec);
    }
    return 0;
}

int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    range(t)
    {
        if (func())
            print("YES");
        else
            print("NO");
    }
}
