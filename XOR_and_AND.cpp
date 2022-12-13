#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
template<typename... T>void print(T &&...args){((cout<<args<< " "), ...);cout<<endl;}
template<typename... T>void printl(T &&...args){ ((cout << args << " "), ...);}
inline ld TLD(ll n) {return n;}
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n);}
inline ll rs(ll n){return n%mod >= 0 ? n % mod : (n%mod)+mod;}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */


//      inttobinary
vi intToBinary(ll n)
{
    vi binary(63);
    for (ll i = 0; i < 64 && n != 0; i++)
    {
        if (n % 2 == 0)
        {
            binary[i] = 0;
        }
        else
        {
            binary[i] = 1;
        }
        n = n / 2;
    }
    return binary;
}

//      binarytoint
int binaryToInt(vi &num)
{
    int dec_value = 0;
    ll base = 1;

    for (ll i = 0; i < num.size(); i++)
    {
        if (num[i] == 1)
        {
            dec_value += base;
        }
        base = base * 2;
    }
    return dec_value;
}

//      ncr of a number
ll NCR(ll n, ll r)
{
    if (r > n)
        return 0;
    // ll inv[r + 1] = {0};
    vi inv(r+1, 0); 
    inv[0] = 1;
    if (r + 1 >= 2)
        inv[1] = 1;

    // Getting the modular inversion
    // for all the numbers
    // from 2 to r with respect to m
    // here m = 1000000007
    for (ll i = 2; i <= r; i++)
    {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }

    ll ans = 1;

    // for 1/(r!) part
    for (ll i = 2; i <= r; i++)
    {
        ans = ((ans % mod) * (inv[i] % mod)) % mod;
    }

    // for (n)*(n-1)*(n-2)*...*(n-r+1) part
    for (ll i = n; i >= (n - r + 1); i--)
    {
        ans = ((ans % mod) * (i % mod)) % mod;
    }
    return ans;
}

void func()
{
    newint(n); 
    vi vec = inputvec(n); 
    // sort on msb; 
    map<ll, ll> mp; 
    foreach(i, vec)
    {
        ll c = 0; 
        while(i){
            i >>= 1; 
            c++; 
        }
        mp[c]++; 
    }
    ll ans = 0; 
    foreach(i, mp)
    {
        ans += i.second* (i.second-1)/2; 
    }
    print(ans); 
    

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
