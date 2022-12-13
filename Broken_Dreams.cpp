#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
#define popcount(x) __builtin_popcount(x)
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

// string handleit(string str)
// {
    
// }
string func(ll n, ll k, string str)
{
    // if (k == 2)
    // {
    //     return handleit(str);
    // }
    string ans;
    range(k - 1)
    {
        n = str.size();
        string prefix(n, str[n - 1]);
        range(i, n - 2, -1, -1)
        {
            prefix[i] = min(prefix[i + 1], str[i]);
        }
        string nstr;
        range(i, n)
        {
            if (prefix[i] != str[i] || (nstr.size() != 0 && nstr[0] <= str[i]))
            {
                nstr.push_back(str[i]);
            }
            else
            {
                ans.push_back(str[i]);
            }
        }
        str = ans + nstr;
        ans.clear();
    }
    return (ans + str);
}

string brutefunc(ll n, ll k, string s)
{
    string s1 = s;
    sort(s1.begin(), s1.end());
    int i = 0, j = 0;
    if (n == k || k >= 26)
    {
        return s1;
    }
    int j1 = n;
    for (int i = 2; i <= k; i++)
    {
        if (j == n)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (s1[j] == s[i])
            {
                j++;
                s[i] = '_';
                j1 = i;
            }
        }
    }
    char x = '_';
    int g = 1;
    for (int i = 0; i < n; i++)
    {
        if (x == '_' && s[i] != '_')
        {
            x = s[i];
        }
        else if (x != '_' && s[i] != '_' && s[i] != x)
        {
            if (s[i] < x)
            {
                g = 0;
            }
            break;
            // else
        }
    }
    // vectpr <pair <char,int>> vp;
    if (g)
    {
        string s4 = "{";
        for (int i = j1 + 1; i < n; i++)
        {
            string s6 = "";
            int k = s4.length();
            for (int i1 = 0; i1 < s4.length(); i1++)
            {
                if (s[i] != '_' && s[i] < s4[i1] && s[i] <= x)
                {
                    k = i1;
                    break;
                }
            }
            s6 = s4.substr(0, k);
            s4 = s6;
            if (k == s4.length() && s[i] <= x && s[i] != '_')
            {
                s4 += s[i];
            }
        }
        string s2 = "";
        if (s4 != "{")
        {
            // s3+=s4;
            int k1 = 0;
            for (int i = j1 + 1; i < n; i++)
            {
                if (k1 == s4.length())
                {
                    break;
                }
                if (s4[k1] == s[i])
                {
                    s[i] = '_';
                    k1++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '_')
            {
                s2 += s[i];
            }
        }
        int l = s2.length();
        if (s4 != "{")
        {
            l += s4.length();
        }
        string s3 = s1.substr(0, n - l);
        if (s4 != "{")
        {
            s3 += s4;
        }
        s3 += s2;
        return s3;
    }
    else
    {
        string s4 = "{";
        for (int i = j1 + 1; i < n; i++)
        {
            string s6 = "";
            int k = s4.length();
            for (int i1 = 0; i1 < s4.length(); i1++)
            {
                if (s[i] != '_' && s[i] < s4[i1] && s[i] < x)
                {
                    k = i1;
                    break;
                }
            }
            s6 = s4.substr(0, k);
            s4 = s6;
            if (k == s4.length() && s[i] < x && s[i] != '_')
            {
                s4 += s[i];
            }
        }
        string s2 = "";
        if (s4 != "{")
        {
            // s3+=s4;
            int k1 = 0;
            for (int i = j1 + 1; i < n; i++)
            {
                if (k1 == s4.length())
                {
                    break;
                }
                if (s4[k1] == s[i])
                {
                    s[i] = '_';
                    k1++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '_')
            {
                s2 += s[i];
            }
        }
        int l = s2.length();
        if (s4 != "{")
        {
            l += s4.length();
        }
        string s3 = s1.substr(0, n - l);
        if (s4 != "{")
        {
            s3 += s4;
        }
        s3 += s2;
        return s3;
    }
}

int main()
{
    // Uncomment for faster I/O
    // FAST;
    while (true)
    {
        ll n = rand() % 10, k = 3;
        if (k > n)
            k = n;
        string str;
        range(i, n)
        {
            str.push_back('a' + rand() % 26);
        }
        string myans = func(n, k, str);
        string judge_ans = brutefunc(n, k, str);
        if (myans == judge_ans)
            continue;
        else
        {
            db(n);
            db(k);
            db(str);
            db(myans);
            db(judge_ans);
            func(n, k, str);
            break;
        }
    }
}
