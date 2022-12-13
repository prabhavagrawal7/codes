#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
// for segment tree
// #define mid (start+end)/2 
// #define lnode (node*2+1)
// #define rnode (node*2+2)
#define popcount(x) __builtin_popcount(x)
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
#define r4(var, start, stop, step) for(ll var=start;step>=0?var<stop:var>stop;var=var+step)
#define r3(var, start, stop) for(ll var = start; var < stop; var++)
#define r2(var, stop) for(ll var = 0; var < stop; var++)
#define r1(stop) for(ll start_from_0 = 0; start_from_0 < stop; start_from_0++)
#define newint(...) ll __VA_ARGS__; take_input(__VA_ARGS__)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define give(...) {print(__VA_ARGS__); return ;}
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
#define pf push_front
const ll mod = 1000000007;
//const ll mod = 998244353; 
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define newstring(str) string str; cin >> str;
#define foreach(a, x) for (auto &&a : x)
const ld pi = acos(-1);
typedef vector<string> vs; typedef pair<ll, ll> pii;typedef vector<ll> vi;typedef map<ll, ll> mii; typedef set<ll> si; typedef vector<vector<ll>> vvi;
template<typename ...T>void take_input(T&&...args) { ((cin >> args), ...); }
vi inputvec(ll n, ll start = 0) { vi vec(n);range(i, start, n)cin >> vec[i];return vec; }
template<typename T>bool btn(T a, T b, T c) { if ((a <= b && b <= c) || (a >= b && b >= c)) return true; return false; }
template<typename T>ostream& operator<<(ostream& os, const V<T>& v) { for (int i = 0;i < v.size();++i) { os << v[i];if (i != v.size() - 1)os << " "; }return os; }
template <typename _A, typename _B>ostream& operator<<(ostream& os, const pair<_A, _B>& p) { os << "[" << p.first << ", " << p.second << "]";return os; }
template<typename... T>void print(T &&...args) { ((cout << args << " "), ...);cout << endl; }
template<typename... T>void printl(T &&...args) { ((cout << args << " "), ...); }
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
inline ll rs(ll n) { return (n = n % mod) >= 0 ? n : n + mod; }
ll power(ll x, ll y) { ll res = 1;while (y) { if (y & 1LL)res = (res * x) % mod;y >>= 1;x = (x * x) % mod; }return res % mod; }

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */


vi func1(ll n, vi vec)
{
    ll carry = -1;
    sort(all(vec));
    if (n % 2 != 0) {
        carry = vec[n - 1];
        vec.pop_back();
        n = n - 1;
    }
    vi nvec;
    range(i, n / 2) {
        nvec.push_back(vec[i]);
        nvec.push_back(vec[i + n / 2]);
    }
    if (carry != -1) nvec.push_back(carry), n++;
    range(i, n + 10) {
        if (nvec[i % n] < nvec[(i + 1) % n] && nvec[(i + 1) % n] > nvec[(i + 2) % n])
            continue;
        if (nvec[i % n] > nvec[(i + 1) % n] && nvec[(i + 1) % n] < nvec[(i + 2) % n])
            continue;
        return vi(1, -1);
    }
    return nvec;
}


vi func2(ll n, vi vec)
{
    ll carry = -1;
    sort(all(vec));
    if (n % 2 != 0) {
        carry = vec[0];
        vi cvec(vec.begin() + 1, vec.end());
        vec = move(cvec);
        n = n - 1;
    }
    vi nvec;
    range(i, n / 2) {
        nvec.push_back(vec[i]);
        nvec.push_back(vec[i + n / 2]);
    }
    if (carry != -1) nvec.push_back(carry), n++; 
    range(i, n + 10) {
        if (nvec[i % n] < nvec[(i + 1) % n] && nvec[(i + 1) % n] > nvec[(i + 2) % n])
            continue;
        if (nvec[i % n] > nvec[(i + 1) % n] && nvec[(i + 1) % n] < nvec[(i + 2) % n])
            continue;
        return vi(1, -1);
    }
    return nvec;
}

int main()
{
    // Uncomment for faster I/O
    // FAST;
    newint(t);
    range(t)
    {
        newint(n);
        vi vec = inputvec(n);

        vi ans1 = func1(n, vec);
        vi ans2 = func2(n, vec);
        if (ans1[0] != -1) {
            print("YES");
            print(ans1);
        }
        else if (ans2[0] != -1) {
            print("YES");
            print(ans2);
        }
        else {
            print("NO");
        }
    }
}