#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll int
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
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define print(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define db(x) cout << #x << " = " << x << "\n"
#define range(i, n) for (ll i = 0; i < n; i++)
#define ranges(i, s, n) for (ll i = s; i < n; i++)
#define sranges(i, start, stop, step) for (ll i = start; i != stop; i = i + step)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define testcase(t) \
    new_int_1(t);   \
    range(i, t)
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
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef pair<string, ll> psi;
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
 
//code starts here ------------------------------------------->
//code starts here ------------------------------------------->
//code starts here ------------------------------------------->
//code starts here ------------------------------------------->
class Point
{
public:
    ll px, py, pxay, pxmy;
    Point() {}
    Point(ld x, ld y)
    {
        this->px = x;
        this->py = y;
        this->pxay = x + y;
        this->pxmy = x - y;
    }
    bool operator==(Point a)
    {
        if (a.px == px && a.py == py)
            return true;
        return false;
    }
    bool subset(Point a)
    {
        if (a.px == px || a.py == py || a.pxay == pxay || a.pxmy == pxmy)
            return true;
        return false;
    }
    bool operator<(const Point &rhs) const
    {
        if (px == rhs.px)
            return py < rhs.py;
        return px < rhs.px;
    }
};

vector<Point> allpoints(V<Point> points)
{
    set<Point> ap;
    for (auto i : points)
        ap.insert(i);

    for (ll i = 0; i < points.size(); i++)
    {
        for (ll j = 0; j < points.size(); j++)
        {
            if(points[i] == points[j]) continue;
            Point fix = points[i];
            Point var = points[j];
            // px
            ap.insert(Point(fix.px, var.py));
            ap.insert(Point(fix.px, var.pxay - fix.px));
            ap.insert(Point(fix.px, fix.px - var.pxmy));
            // py
            ap.insert(Point(var.px, fix.py));
            ap.insert(Point(var.pxay - fix.py, fix.py));
            ap.insert(Point(var.pxmy + fix.py, fix.py));
            // pxay
            ap.insert(Point(var.px, fix.pxay - var.px));
            ap.insert(Point(fix.pxay - var.py, var.py));
            ap.insert(Point((fix.pxay + var.pxmy) / 2, (fix.pxay - var.pxmy) / 2));
            // pxmy
            ap.insert(Point(var.px, -fix.pxmy + var.px));
            ap.insert(Point(fix.pxmy + var.py, var.py));
            ap.insert(Point((fix.pxmy + var.pxay) / 2, (-fix.pxmy + var.pxay) / 2));
        }
    }
    vector<Point> ans;
    for (auto &i : ap)
    {
        ans.push_back(i);
    }
    return ans;
}
ld func()
{
    new_int_1(n);
    vi xvec = inputvec(n);
    vi yvec = inputvec(n);
    V<Point> points(n);
    for (ll i = 0; i < n; i++)
    {
        points[i] = Point(xvec[i], yvec[i]);
    }
    ll ans = INT_MAX;
    auto ap = allpoints(points);

    for (auto i : ap)
    {
        ll tempans = 0;
        Point mainpoint = i;
        for (auto j : points)
        {
            if (mainpoint == j)
                continue;
            else if (mainpoint.subset(j))
                tempans++;
            else
                tempans += 2;
        }
        ans = min(ans, tempans);
    }
    cout << ans << endl;
    return 0;
}
int main()
{
    // FAST;
    testcase(t)
    {
        func();
    }
}
