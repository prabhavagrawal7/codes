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
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define new_string(str) \
    string str;         \
    cin >> str;
#define foreach(a, x) for (auto &a : x)
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
ostream &operator<<(ostream &os, const deque<T> &v)
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

void func()
{
    newint(r, g, b);
    ll tot = r + g + b;
    UM<ll, US<ll>> gr;
    if (tot - b < b)
        give(-1);
    gr[0].insert(1);
    gr[1].insert(0);
    US<ll> red, blue, green;
    red.insert(0), green.insert(1);
    ll thepi = 2;
    r--, g--;
    while (r || g)
    {
        if (r <= g)
        {
            gr[thepi].insert(0);
            gr[0].insert(thepi);
            green.insert(thepi);
            g--;
        }
        else
        {
            gr[thepi].insert(1);
            gr[1].insert(thepi);
            red.insert(thepi);
            r--;
        }
        thepi++;
    }

    while (b)
    {
        foreach (i, red)
        {
            if (!b)
                break;
            gr[thepi].insert(i);
            gr[i].insert(thepi);
            blue.insert(thepi);
            b--;
            thepi++;
        }
        foreach (i, green)
        {
            if (!b)
                break;
            gr[thepi].insert(i);
            gr[i].insert(thepi);
            blue.insert(thepi);
            b--;
            thepi++;
        }
    }

    string ans;
    ans.resize(tot);
    foreach (i, red)
        ans[i] = 'R';
    foreach (i, green)
        ans[i] = 'G';
    foreach (i, blue)
        ans[i] = 'B';

    print(ans); 
    // dfs here
    vi visited(tot, 0); 
    stack<ll> st; 
    st.push(1);
    while(st.size())
    {
        ll x = st.top();
        visited[x] = 1;
        st.pop();
        foreach (i, gr[x])
        {
            if (!visited[i])
            {
                st.push(i);
                print(i+1, x+1);
            }
        }
    }
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
