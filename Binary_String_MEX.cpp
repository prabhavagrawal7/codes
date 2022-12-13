#include <bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1) \
(__VA_ARGS__)
#define r4(var, start, stop, step) for (auto var = start; var != stop; var = var + step)
#define r3(var, start, stop) for (auto var = start; var != stop; var++)
#define r2(var, stop) for (ll var = 0; var != stop; var++)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 != stop; start_from_0++)
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
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define new_string(str) \
    string str;         \
    cin >> str;
#define new_int_1(t) \
    ll t;            \
    cin >> t;
#define new_int_2(a, b) \
    ll a, b;            \
    cin >> a >> b;
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    cin >> a >> b >> c;
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    cin >> a >> b >> c >> d;
#define new_int_5(a, b, c, d, e) \
    ll a, b, c, d, e;            \
    cin >> a >> b >> c >> d >> e;
#define new_int_6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;            \
    cin >> a >> b >> c >> d >> e >> f;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef map<ll, ll> mii;
typedef set<ll> si;
ll input()
{
    new_int_1(n);
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
    for (int i = 0; i < v.size();
         ++i)
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

ll isSubstring(string &s1, string &s2, ll pos1 = 0, ll pos2 = 0)
{
    if (pos1 == s1.length() && pos2 == s2.length())
    {
        return pos1;
    }
    if (pos1 == s1.length() && pos2 != s2.length())
        return -1;
    if (pos1 != s1.length() && pos2 == s2.length())
        return pos1;

    if (s1[pos1] == s2[pos2])
        return isSubstring(s1, s2, pos1 + 1, pos2 + 1);
    else
        return isSubstring(s1, s2, pos1 + 1, pos2);
}
vector<string> operator+(vector<string> &s, vector<string> &s1)
{
    vector<string> ans;
    for(auto &i : s) ans.push_back(i);
    for(auto &i : s1) ans.push_back(i);
    return ans;
}
string func()
{
    // write your code here
    new_string(str);
    if(str.find('0') == string::npos) return "0";
    string s, s1;
    s += "1";
    s1 += "1";
    
    range(i, 10e6)
    {
        range(j, s.size())
        {
            auto a = isSubstring(str, s);
            auto b = isSubstring(str, s1);
            if (isSubstring(str, s) == -1)
                return s;
            if (isSubstring(str, s1) == -1)
                return s1;
            if(a > b) s1 = s;
            else s = s1;
        }
        s += '0';
        s1 += '1';
    }
    return "";
}

int main()
{
    // Uncomment for faster I/O
    // FAST;
    new_int_1(t);
    range(t)
    {
        print(func());
    }
    // print(isSubstring(b, a));
}
