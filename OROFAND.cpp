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
    cin >> t;
#define new_int_2(a, b) \
    ll a, b;            \
    cin >> a >> b
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    cin >> a >> b >> c
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    cin >> a >> b >> c >> d
#define new_int_6(a, b, c, d, e, f) \
    ll a, b, c, d, e, f;            \
    cin >> a >> b >> c >> d >> e >> f
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
vi decToBinary(ll n)
{
    // array to store binary number
    // ll binaryNum[32];
    vi binaryNum(32, 0);
    // counter for binary array
    ll i = 0;
    while (n > 0)
    {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    return binaryNum;
}
ll BinaryTodec(vi binarynum)
{
    ll ans = 0;
    for (ll i = 0; i < binarynum.size(); i++)
    {
        ans += (binarynum[i] ? 1 : 0) * (pow(2, i));
    }
    return ans;
}
ll summing(vi &mainbin, vi &bin)
{
    for (ll i = 0; i < mainbin.size(); i++)
    {
        mainbin[i] += bin[i];
    }
    return 0;
}
ll differencing(vi &mainbin, vi bin)
{
    for (ll i = 0; i < mainbin.size(); i++)
    {
        mainbin[i] -= bin[i];
    }
    return 0;
}
ll func()
{
    new_int_2(n, k);
    vi vec = inputvec(n);
    vi mainbin(32, 0);
    for (ll i = 0; i < n; i++)
    {
        vi dtb = decToBinary(vec[i]);
        summing(mainbin, dtb);
    }
    cout << BinaryTodec(mainbin) << endl;

    for (ll i = 0; i < k; i++)
    {
        new_int_2(pos, num);
        vi dtb = decToBinary(num);
        vi olddtb = decToBinary(vec[pos - 1]);
        differencing(mainbin, olddtb);
        summing(mainbin, dtb);
        cout << BinaryTodec(mainbin) << endl;
        vec[pos-1] = num;
    }

    return 0;   
}

int main()
{
    ll t;
    cin >> t;
    rep(i, 0, t)
    {
        func();
    }
}