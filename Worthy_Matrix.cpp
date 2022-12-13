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
inline ld TLD(ll n) { return n; }
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

inline ll prec(V<vi> &pre, ll x2, ll y2, ll x1, ll y1)
{
    if (x1 < 0 || y1 < 0)
        return 0;
    return pre[y2][x2] - pre[y2][x1] - pre[y1][x2] + pre[y1][x1];
}
ll func()
{
    // write your code here
    newint(n, m, k);
    ll ans = 0;
    V<vi> vec;
    vec.push_back(vi(m + 1, 0));
    range(i, n) { vec.push_back(inputvec(m + 1, 1)); }
    V<vi> pre(n + 1, vi(m + 1, 0));
    range(i, 1, n + 1)
    {
        range(j, 1, m + 1)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + vec[i][j];
        }
    }
    range(st, 1, n + 1)
    {
        range(l, 1, 1 + max(m, n))
        {
            if (st - l < 0)
                break;
            ll left = l, right = m, mid = m + 1;
            while (left <= right)
            {
                mid = (left + right) / 2;
                ll midc = prec(pre, mid, st, mid - l, st - l);
                // if(st == 2 && l == 2)
                // print("hello");
                if ((midc >= l * l * k && prec(pre, mid - 1, st, mid - l - 1, st - l) < l * l * k))
                {
                    // db(st);
                    // db(midc);
                    // db(l);
                    // db(m + 1 - mid);
                    // print(" ");
                    ans += m + 1 - mid;
                    break;
                }
                else if (midc >= l* l * k)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
    }
    return ans;
} 

int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    range(t)
    {
        print(func());
    }
}
