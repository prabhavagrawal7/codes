#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define endl "\n"
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
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
#define range(i, stop) for (ll i = 0; i != stop; i++)
#define ranges(i, start, stop) for (ll i = start; i != stop; i++)
#define sranges(i, start, stop, step) for (ll i = start; i != stop; i = i + step)
#define iterate(i, start, end) for (auto i = start; i != end; i++)

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
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ld pi = acos(-1);
typedef vector<string> vs;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef map<ll, ll> mii;
typedef set<ll> si;
template <typename T>
bool btn(T a, T b, T c)
{
    if ((a <= b && b <= c) || (a >= b && b >= c))
        return true;
    return false;
}
void print(ll x)
{
    cout << x << endl;
}
void print(vi x)
{
    for (auto &i : x)
        cout << i << " ";
    cout << endl;
}
void print(string s) { cout << s << endl; }

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
ll n, m;
V<V<bool>> visited;

bool isValid(ll i, ll j)
{
    if (!btn(0LL, i, n) || !btn(0LL, j, m))
        return false;
    if (visited[i][j] == true)
        return false;
    return true;
}

int main()
{
    FAST;
    cin >> n >> m;
    vs vec(n);
    range(i, n) cin >> vec[i];
    pii spath;
    pii endpath;
    visited = V<V<bool>>(n, V<bool>(m, 0));
    V<pii> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    V<V<pii>> path(n, V<pii>(m));
    range(i, n)
    {
        range(j, m)
        {
            if (vec[i][j] == '#')
                visited[i][j] = true;
            if (vec[i][j] == 'A')
            {
                spath.first = i;
                spath.second = j;
            }
            if (vec[i][j] == 'B')
            { 
                endpath.first = i;
                endpath.second = j;
            }
        }
    }

    queue<tuple<ll, ll>> opr; // position, string
    opr.push({spath.first, spath.second});
    while (opr.size() != 0)
    {
        auto [sx, sy] = opr.front();
        visited[sx][sy] = true;
        opr.pop();
        for (auto u : moves)
        {
            ll ux = u.second;
            ll uy = u.first;
            if (isValid(sx + ux, sy + uy))
            {
                opr.push({sx + ux, sy + uy});
                direction[sx + ux][sy + uy] = 'U';
                if (sx - 1 == endpath.first && sy == endpath.second)
                    break;
            }
        }
    }

    if (opr.size() == 0)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        string st = "";
        ll fpy = endpath.first;
        ll fpx = endpath.second;

        while (spath.first != fpy || spath.second != fpx)
        {
            if (direction[fpy][fpx] == 'U')
            {
                st += 'U';
                fpy += 1;
            }
            else if (direction[fpy][fpx] == 'D')
            {
                st += 'D';
                fpy -= 1;
            }
            else if (direction[fpy][fpx] == 'R')
            {
                st += 'R';
                fpx -= 1;
            }
            else
            {
                st += 'L';
                fpx += 1;
            }
        }
        reverse(all(st));
        cout << st.size() << endl;
        cout << st << endl;
    }

    return 0;
}
