#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define debug(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define debugp(x)          \
    for (auto element : x) \
    cout << element.first << " " << element.second << endl
#define db(x) cout << #x << " = " << x << "\n"
#define rep(i, k, n) for (ll i = k; i < n; i++)
#define rept(i, k, n) for (auto i = k; i != n; ++i)
#define drep(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define ld long double
#define clr(s) memset(s, 0, sizeof(s))
#define new_string(str) \
    string str;         \
    stringinput(str);
#define new_int_1(t) \
    ll t;            \
    scanf("%lld", &t);
#define new_int_2(a, b) \
    ll a, b;            \
    scanf("%lld %lld", &a, &b);
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    scanf("%lld %lld %lld", &a, &b, &c);
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    scanf("%lld %lld %lld %lld ", &a, &b, &c, &d);
#define new_int_5(a, b, c, d, e) \
    ll a, b, c, d, e;            \
    scanf("%lld %lld %lld %lld ", &a, &b, &c, &d, &e);
#define new_int_6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;            \
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
typedef vector<string> vs;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
typedef pair<ll, ll> pii;
typedef pair<ll, pair<ll, ll>> pipii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;
typedef map<char, ll> mci;
typedef map<string, string> mss;
typedef set<ll> si;
typedef set<pair<ll, ll>> spii;
typedef set<pair<string, ll>> spsi;
const ll mod = 1000000007;
const ll mod2 = 998244353;
char s[100005];
void stringinput(string &str)
{
    scanf("%s", s);
    str = s;
}
vector<ll> randvec(ll n, ll start = 0, ll end = 100)
{
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        arr[i] = rand() % end;
        if (arr[i] < start)
        {
            arr[i] = arr[i] + start;
        }
    }
    return arr;
}
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
        *(vec.begin() + i) = input();
    }
    return vec;
}
si inputset(ll n)
{
    si myset;
    for (ll i = 0; i < n; i++)
    {
        myset.insert(input());
    }
    return myset;
}

ll func()
{
    vs vec(3);
    //input
    for (ll i = 0; i < 3; i++)
    {
        stringinput(vec[i]);
    }

    vector<bool> Xhori(3, false);
    vector<bool> Xvert(3, false);
    vector<bool> Xdiag(2, false);

    vector<bool> Ohori(3, false);
    vector<bool> Overt(3, false);
    vector<bool> Odiag(2, false);
    ll Xcount = 0;
    ll Ocount = 0;

    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            if (vec[i][j] == 'X')
            {
                Xcount++;
            }
            else if (vec[i][j] == 'O')
            {
                Ocount++;
            }
        }
    }

    //horizontal data extraction
    for (ll i = 0; i < 3; i++)
    {
        if (vec[i] == "XXX")
        {
            Xhori[i] = true;
        }
        else if (vec[i] == "OOO")
        {
            Ohori[i] = true;
        }
    }
    //vertical data extraction
    for (ll i = 0; i < 3; i++)
    {
        if (vec[0][i] == vec[1][i] && vec[1][i] == vec[2][i])
        {
            if (vec[0][i] == 'X')
            {
                Xvert[i] = true;
            }
            else if (vec[0][i] == 'O')
            {
                Overt[i] = true;
            }
        }
    }
    //front diagonal extraction
    if (vec[0][0] == vec[1][1] && vec[1][1] == vec[2][2])
    {
        if (vec[0][0] == 'X')
        {
            Xdiag[0] = true;
        }
        else if (vec[0][0] == 'O')
        {
            Odiag[0] = true;
        }
    }
    //back diagonal extraction
    if (vec[0][2] == vec[1][1] && vec[1][1] == vec[2][0])
    {
        if (vec[0][2] == 'X')
        {
            Xdiag[1] = true;
        }
        else if (vec[0][2] == 'O')
        {
            Odiag[1] = true;
        }
    }

    //logic
    if (Xcount == Ocount)
    {
        for (auto i : Xhori)
        {
            if (i)
            {
                return 3;
            }
        }
        for (auto i : Xvert)
        {
            if (i)
            {
                return 3;
            }
        }
        for (auto i : Xdiag)
        {
            if (i)
            {
                return 3;
            }
        }
        ll perfecthorizontal = 0;
        for (auto i : Ohori)
            perfecthorizontal += i;
        ll perfectvertical = 0;
        for (auto i : Overt)
            perfectvertical += i;
        if (perfecthorizontal > 1 || perfectvertical > 1)
        {
            return 3;
        }

        else
        {
            if (perfecthorizontal || perfectvertical || Odiag[0] || Odiag[1])
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    else if (Xcount == Ocount + 1)
    {
        for (auto i : Ohori)
        {
            if (i)
            {
                return 3;
            }
        }
        for (auto i : Overt)
        {
            if (i)
            {
                return 3;
            }
        }
        for (auto i : Odiag)
        {
            if (i)
            {
                return 3;
            }
        }
        ll perfecthorizontal = 0;
        for (auto i : Xhori)
            perfecthorizontal += i;

        ll perfectvertical = 0;
        for (auto i : Xvert)
            perfectvertical += i;

        if (perfecthorizontal > 1 || perfectvertical > 1)
        {
            return 3;
        }
        else
        {
            if (perfecthorizontal || perfectvertical || Xdiag[0] || Xdiag[1] || Xcount == 5)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    else
    {
        return 3;
    }
}

int main()
{
    new_int_1(t);
    rep(i, 0, t)
    {
        cout << func() << endl;
    }
}