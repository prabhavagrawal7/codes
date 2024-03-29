#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define ll long long
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define os_at(k) find_by_order(k)
#define os_lb(k) order_of_key(k) // lower_bound key
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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
//const ll mod = 998244353; 
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define newstring(str) string str; cin >> str;
#define foreach(a, x) for (auto &a : x)
const ld pi = acos(-1);
typedef vector<string> vs; typedef pair<ll, ll> pii;typedef vector<ll> vi;typedef map<ll, ll> mii; typedef set<ll> si; typedef vector<vector<ll>> vvi; 
template<typename ...T>void take_input(T&&...args){((cin >> args), ...);}
vi inputvec(ll n, ll start = 0){vi vec(n);range(i, start, n)cin >> vec[i];return vec;}
template<typename T>bool btn(T a, T b, T c){if((a <= b && b <= c) || (a >= b && b >= c)) return true; return false;}
template<typename T>ostream& operator<<(ostream& os,const V<T>& v){for(int i=0;i<v.size();++i){os<<v[i];if(i!=v.size()-1)os<<" ";}return os;}
template <typename _A, typename _B>ostream &operator<<(ostream &os, const pair<_A, _B> &p){os<<"["<<p.first<<", "<<p.second<<"]";return os;}
template<typename... T>void print(T &&...args){((cout<<args<< " "),...);cout<<endl;}
template<typename...T>void printl(T&&...args){((cout<<args<<" "),...);}
string binary_debug(ll n){string ans;while(n){ans.push_back((n&1)+'0');n>>=1;}reverse(all(ans));return ans;}
inline ld TLD(ll n) {return n;}
inline ll gcd(ll m, ll n){return __gcd(m, n);}
inline ll rs(ll n){return n%mod;}
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
void insert(ordered_set &orc, ll ele)
{
    auto _y = orc.lower_bound(mp(ele, -INT_INF * 1LL));
    if (_y == orc.end() || _y->first != ele)
    {
        orc.insert(mp(ele, 0LL));
    }
    else
    {
        pii x = *_y;
        x.second--;
        orc.insert(x);
    }
}
void erase(ordered_set &orc, ll ele)
{
    orc.erase(orc.lower_bound({ele, -INT_INF * 1LL}));
}
void func()
{
    newint(n, k);
    vi vec = inputvec(n);
    ordered_set orc;
    foreach (i, vec)
    {
        insert(orc, i);
    }
    orc.insert({INT_INF*1LL, INT_INF*1LL}); 
  
    range(k)
    {
        char ch;
        cin >> ch;
        if (ch == '!')
        {
            newint(a, b);
            erase(orc, vec[a - 1]);
            insert(orc, b);
            vec[a - 1] = b;
        }
        else
        {
            newint(a, b);
            ll u = orc.os_lb(*orc.lower_bound({a, -INT_INF * 1LL}));
            ll v = orc.os_lb(*orc.lower_bound({b, INT_INF * 1LL}));
            print(abs(v - u));
        }
    }
}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    {
        func();
    }
}
