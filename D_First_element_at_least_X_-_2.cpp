#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
// for segment tree
#define mid (start+end)/2 
#define lnode (node*2+1)
#define rnode (node*2+2)
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
template<typename ...T>void take_input(T&&...args){((cin >> args), ...);}
vi inputvec(ll n, ll start = 0){vi vec(n);range(i, start, n)cin >> vec[i];return vec;}
template<typename T>bool btn(T a, T b, T c){if((a <= b && b <= c) || (a >= b && b >= c)) return true; return false;}
template<typename T>ostream& operator<<(ostream& os,const V<T>& v){for(int i=0;i<v.size();++i){os<<v[i];if(i!=v.size()-1)os<<" ";}return os;}
template <typename _A, typename _B>ostream &operator<<(ostream &os, const pair<_A, _B> &p){os<<"["<<p.first<<", "<<p.second<<"]";return os;}
template<typename... T>void print(T &&...args){((cout<<args<< " "), ...);cout<<endl;}
template<typename... T>void printl(T &&...args){ ((cout << args << " "), ...);}
inline ld TLD(ll n) {return n;}
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n);}
inline ll rs(ll n){return (n=n%mod)>=0?n:n+mod;}
ll power(ll x, ll y){ll res = 1;while (y){if(y&1LL)res=(res*x)%mod;y>>=1;x=(x*x)%mod;}return res % mod;}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */

class stree{
    public: 
    vi vec, tree; 
    ll n; 
    void buildtree(ll node, ll start, ll end)
    {
        if(start == end) {
            tree[node] = vec[start]; 
            return; 
        }
        buildtree(lnode, start, mid); 
        buildtree(rnode, mid+1, end); 
        tree[node] = max(tree[lnode], tree[rnode]); 
    }
    stree(vi v)
    {
        vec = move(v); 
        n = vec.size(); 
        tree.assign(n*4,0); 
        buildtree(0, 0, n-1); 
    }
    void update(ll ind, ll nele)
    {
        update(ind, nele, 0, 0, n-1); 
    }
    void update(ll ind, ll nele, ll node, ll start, ll end)
    {
        if(start == end){
            vec[start] = nele; 
            tree[node] = vec[start]; 
            return ;
        }
        if(ind <= mid) update(ind, nele, lnode, start, mid); 
        else update(ind, nele, rnode, mid+1, end); 
        tree[node] = max(tree[lnode], tree[rnode]); 
    }
    ll rangefind(ll lstele, ll lstind){
        return rangefind(lstele, lstind, 0, 0, n-1); 
    }
    ll rangefind(ll lstele, ll lstind, ll node, ll start, ll end)
    {
        if(tree[node] < lstele) return INT_INF; 
        if(end < lstind) return INT_INF; 
        if(start == end) return start; 
        if(start >= lstind && tree[lnode] >= lstele) 
            return rangefind(lstele, lstind, lnode, start, mid); 
        else {
            ll ans1 = rangefind(lstele, lstind, lnode, start, mid); 
            ll ans2 = rangefind(lstele, lstind, rnode, mid+1, end); 
            return min(ans1, ans2); 
        }
    }

};
void func()
{
    newint(n, q); 
    vi vec = inputvec(n); 
    stree seg(vec); 
    while(q--)
    {
        newint(a, b, c); 
        if(a == 1){
            seg.update(b, c); 
        }
        else {
            ll ans  = (seg.rangefind(b, c));
            if(ans == INT_INF) print(-1); 
            else print(ans); 
        }
    }

}
int main()
{
    // Uncomment for faster I/O
    // FAST;
    func(); 
}
