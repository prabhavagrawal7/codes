#include<bits/stdc++.h>
// Uncomment them for optimisations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
#define r4(var, start, stop, step) for (auto var = start; start<=stop? var<stop:var>stop ; var = var + step)
#define r3(var, start, stop) for(auto var = start; var != stop; var++)
#define r2(var, stop) for(ll var = 0; var != stop; var++)
#define r1(stop) for(ll start_from_0 = 0; start_from_0 != stop; start_from_0++)
#define newint(...) ll __VA_ARGS__; take_input(__VA_ARGS__)
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
#define fi first
#define se second
#define FAST ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define new_string(str) string str; cin >> str;
const ll mod = 1000000007; const ll mod2 = 998244353; const ld pi = acos(-1);
typedef vector<string> vs; typedef pair<ll, ll> pii;typedef vector<ll> vi;typedef map<ll, ll> mii; typedef set<ll> si;
template<typename ...T>void take_input(T&&...args){((cin >> args), ...);}
ll input(){ newint(n); return n; }vi inputvec(ll n, ll start = 0){ vi vec(n); for (ll i = start; i < n; i++){ vec[i] = input(); } return vec; }
template<typename T>bool btn(T a, T b, T c){if((a <= b && b <= c) || (a >= b && b >= c)) return true; return false;}
template<typename T>ostream& operator<<(ostream& os,const V<T>& v){for(int i=0;i<v.size();++i){os << v[i];if(i!=v.size()-1)os<< " ";}return os;}
template<typename... T>void print(T &&...args){ ((cout << args << " "), ...); cout << endl;}
template<typename... T>void printl(T &&...args){ ((cout << args << " "), ...);}
template<typename... T,typename Q>Q max(Q arg1,T&&...args){Q ans=arg1;((ans=(args>ans?args:ans)),...);return ans;}
template<typename... T,typename Q>Q min(Q arg1,T&&...args){Q ans = arg1;((ans = (args < ans ? args : ans)), ...);return ans;}

ld TLD(ll n) { return TLD(n); }
UM<int, UM<int, int>> dp; 
int func(vector<vector<int>> &g, int start, int s, int parent = -1)
{
    int ans = 0;
    if(dp[start].find(s) != dp[start].end()) return dp[start][s];

    if (s == 0)
    {
        int ans1 = 0;
        for (auto i : g[start])
        {
            if (parent == i)
                continue;
            ans1 += func(g, i, 2, start);
        }
        ans = ans1;
    }
    else if (s == 1)
    {
        int ans1 = 0;
        for (auto i : g[start])
        {
            if (parent == i)
                continue;
            int gchild = func(g, i, 0, start);        // getting results from grand-child
            int aintchild = func(g, start, 0, parent); //getting results when node is not included
            int removechild = func(g, i, 1, start);   // the redundent child
            ans1 = max(ans1, aintchild - removechild + gchild + 1);
        }
        ans = ans1;
    }
    else
    {
        int ans1 = func(g, start, 0, parent);
        int ans2 = func(g, start, 1, parent);
        ans = max(ans1, ans2);
    }
    return dp[start][s] = ans;
}
int main()
{
    // FAST;
    newint(t);
    vector<vector<int>> g(t+1);
    range(t-1)  
    {
        newint(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    print(func(g, 1, 2, -1));
}
