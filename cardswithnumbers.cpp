#include <bits/stdc++.h>
using namespace std;
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
#define endl "\n"
#define ld long double
#define clr(s) memset(s, 0, sizeof(s))
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
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
typedef pair<ll, ll> ii;
typedef pair<ll, pair<ll, ll>> iii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;
typedef map<char, ll> mci;
typedef set<ll> si;
const ll mod = 1000000007;
const ll mod2 = 998244353;
using namespace std;
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
string stringvec(vector<ll> vec, ll start = 0, ll end = INT_MIN)
{
    if (end == INT_MIN)
    {
        end = vec.size();
    }
    string str = "";
    for (ll i = start; i < end; i++)
    {
        str += to_string(vec[i]) + " ";
    }
    str += "\n";
    return str;
}
vector<ll> inputvec(ll n, ll start = 0)
{
    vector<ll> vec(n);
    for (ll i = start; i < n; i++)
    {
        ll num;
        scanf("%lld", &num);
        *(vec.begin() + i) = num;
    }
    return vec;
}

ll func()
{

    map<ll, set<ll>> cards;
    new_int_1(n);
    for (ll i = 0; i < 2*n; i++)
    {
        new_int_1(num);
        if(cards.find(num) != cards.end())
        {
            cards[num].insert(i);
        }
        else
        {
            cards[num] = set<ll>{i};
        }
    }
    for (auto i : cards)
    {
        if(i.second.size() % 2 != 0)
        {
            printf("%lld", -1ll);
        }
    }
    while (cards.size() > 0)
    {
        if(cards.begin()->second.size() == 0)
        {
            cards.erase(cards.begin());
            continue;
        }
        auto vec = &cards.begin()->second;
        printf("%lld ", 1+*vec->begin());
        vec->erase(vec->begin());

        auto vec1 = &cards.begin()->second;
        printf("%lld\n", 1+*vec1->begin());
        vec1->erase(vec1->begin());
    }
    
    return 0;
}

int main()
{
    func();
}