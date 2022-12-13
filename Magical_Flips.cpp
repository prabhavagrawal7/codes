#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
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
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL);

#define all(a) a.begin(), a.end()
#define print(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define db(x) cout << #x << " = " << x << "\n"
#define range(i, n) for (ll i = 0; i < n; i++)
#define ranges(i, s, n) for (ll i = s; i < n; i++)
#define sranges(i, start, stop, step) for (ll i = start; i < stop; i = i + step)
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


vi inttobinary(ll n)
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
int binarytoint(vi &num)
{
    int dec_value = 0;
    ll base = 1;
    ll maxi = *max_element(all(num));
    for (ll i = 0; i < num.size(); i++)
    {
        if (num[i] == maxi)
        {
            dec_value += base;
        }
        base = base * 2;
    }
    return dec_value;
}
vi andd(vi bin1, vi bin2)
{
    vi ans = inttobinary(0);
    range(i, bin1.size())
    {
        ans[i] = bin1[i] + bin2[i];
    }
    return ans;
}

vi randd(vi bin1, vi bin2)
{
    vi ans = inttobinary(0);
    range(i, bin1.size())
    {
        ans[i] = bin1[i] - bin2[i];
    }
    return ans;
}
bool equalcheck(vi bin1, vi bin2)
{
    ll mb1 = *max_element(all(bin1));
    ll mb2 = *max_element(all(bin2));
    bool equal = true;
    for(ll i = 0; i < bin1.size(); i++)
    {
        if(bin1[i] == mb1 || bin2[i] == mb2)
        {
            if(bin1[i] == mb1 && bin2[i] == mb2)
            {
                equal = false;
                return equal;
            }
        }
    }
    return equal;
}
bool greatercheck(vi bin1, vi bin2)
{
    ll mb1 = *max_element(all(bin1));
    ll mb2 = *max_element(all(bin2));
    bool equal = true;
    for(ll i = 0; i < bin1.size(); i++)
    {
        if(bin1[i] == mb1 || bin2[i] == mb2)
        {
            if(bin1[i] != mb1 && bin2[i] == mb2)
            {
                equal = false;
                return equal;
            }
        }
    }
    return equal;
}
// max, flipped
pair<vi, ll> recursion(V<vi> front, V<vi> back, vi sum, ll size)
{
    if(size == 0)
    {
        return mp(sum, 0);
    }
    // when not flipped
    auto ans = recursion(front, back, sum, size-1);
    // when flipped
    vi flipped = andd(back[size-1], randd(sum, front[size-1]));
    auto oans = recursion(front, back, flipped, size-1);
    oans.second++;
    // if(oans.first == ans.first)
    if(equalcheck(oans.first, ans.first))
    {
        if(oans.second > ans.second)
        {
            return ans;
        }
        else
        {
            return oans;
        }
    }
    // if(oans.first > ans.first)
    if(greatercheck(oans.first, ans.first))
    {
        return oans;
    }
    else
    {
        return ans;
    }
    return ans;
}
ll func()
{
    new_int_1(n);
    vi front = inputvec(n);
    vi back = inputvec(n);
    V<vi> bfront(n);
    range(i, n)
    {
        bfront[i] = inttobinary(front[i]);
    }
    V<vi> bback(n);
    range(i, n)
    {
        bback[i] = inttobinary(back[i]);
    }
    vi frontand = inttobinary(0);
    range(i,n)
    {
        frontand = andd(frontand, bfront[i]);
    }
    auto ans = recursion(bfront, bback, frontand, bfront.size());
    cout << binarytoint(ans.first) << " " << ans.second << endl;

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