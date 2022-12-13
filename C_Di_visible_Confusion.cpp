#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
typedef long double ld;

#define debug(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl;
#define debugp(x)          \
    for (auto element : x) \
    cout << element.first << " " << element.second << endl
#define db(x) cout << #x << "=" << x << '\n'

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define os_find(k) find_by_order(k)
#define os_order(k) order_of_key(k)

/* Definitions */
#define f(i, k, n) for (int i = k; i < n; i++)
#define fr(i, k, n) for (int i = k; i >= n; i--)
#define gsort(x) sort(all(x), greater<int>())
#define cntpop(x) __builtin_popcount(x)
#define cntzeroes(x) __builtin_ctzll(x)
#define nah cout << "NO" << endl
#define yeah cout << "YES" << endl
#define all(a) a.begin(), a.end()
#define mp(a, b) make_pair(a, b)
#define pb(k) push_back(k)
#define br cout << endl
#define endl '\n'
#define gcd __gcd
#define fo return

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(x, y) uniform_int_distribution<long long int>(x, y)(rng)

typedef vector<int> vec;
typedef vector<pair<int, int>> vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef map<int, int> mi;
typedef map<char, int> mc;
typedef map<string, int> ms;

const int intmax = 2147483647;
const int intmin = -2147483648;
const int mod = 1000000007; //998244353;
const int pi = 3.141592653589;

int power(int a, int b)
{
    int p = 1;
    while (b){
        if(b & 1 == 1)p *= a;
        a *= a;
        b = b >> 1;
    }
    return p;
}
int modInv(int i,int mod) {return power(i,mod-2);}
int fact[300000];
int ncr(int n,int r) {return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
void in(vec &v) { f(i, 0, v.size()) cin >> v[i]; }
void in1(vec &v, int n){ f(i, 0, n) {int h;cin >> h;v.pb(h);}}
void out(vec v){f(i, 0, v.size()) cout << v[i] << ' ';cout << endl;}

void solve()
{
    int n;
    cin>>n;
    vec v(n);
    in(v);
    int curr=1;
    f(i,0,n){
        if(gcd(curr,(i+2))!=(i+2))curr*=(i+2)/(gcd(i+2,curr));
        if(v[i]%curr==0){
            nah;
            return;
        }
        // db(curr);
    }
    yeah;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    int t;
    cin>>t;
    f(i,1,t+1){
        //cout<<"Case #"<<i<<": ";
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr<<"Time elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms"<<endl;
#endif

    fo 0;
}
/* Aditya Agrawal */