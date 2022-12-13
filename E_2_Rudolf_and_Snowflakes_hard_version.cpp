#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llv __int128_t
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
const ll mod = 1000000007;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
// const ll mod = 998244353;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const long double pi = acos(-1);

#define object(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) object(__VA_ARGS__, range4, range3, range2, range1)(__VA_ARGS__)
#define range4(var, start, stop, step) for (ll var = start; step >= 0 ? var < stop : var > stop; var = var + step)
#define range2(var, end) for (ll var = 0; var < end; var++)
#define range1(stop) for (ll start_from_0 = 0; start_from_0 < stop; start_from_0++)

#define newinput(...) \
    ll __VA_ARGS__;   \
    take_input(__VA_ARGS__)

#define gvr(...)            \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    }
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define V vector
#define all(a) a.begin(), a.end()
#define newstr(str) \
    string str;     \
    cin >> str;
#define foreach(a, x) for (auto &a : x)

typedef pair<ll, ll> pii;
typedef vector<ll> vr;
typedef vector<vector<ll>> vvr;

template <typename... T>
void take_input(T &&...args) { ((cin >> args), ...); }
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
template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
template <typename... T>
void print(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename... T>
void printline(T &&...args) { ((cout << args << " "), ...); }
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T>;

vr inputvector(ll n, ll start = 0)
{
    vr vec(n);
    range(i, start, n, 1) cin >> vec[i];
    return vec;
}
char chart(ll a) { return char(a + 'a'); }
ll intt(char a) { return (a - 'a'); }
llv power(llv x, llv y)
{
    llv res = 1;
    while (y)
    {
        if (y & 1)
        {
            res = (res * x);
        }
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

void solve()
{
    newinput(n);
    range(i, 2, 60, 1)
    {
        ll l = 2, r = n;
        while (r - l > 1)
        {
            ll mid = (l + r) / 2;
            if ((pow(mid, i + 1) - 1) / (mid - 1) > 1e18)
            {
                r = mid;
                continue;
            }
            llv c = 0;
            c = (power(mid, i + 1) - 1) / (mid - 1);
            if (c == n)
            {
                gvr("YES");
            }
            if (c > n)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        llv c = (power(l, i + 1) - 1) / (l - 1);
        if (c == n)
        {
            gvr("YES");
        }
    }

    print("NO");
}
int main()
{
    FAST;

    newinput(t);
    range(t)
    {
        solve();
    }
}