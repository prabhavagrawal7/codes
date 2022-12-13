// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define ll long long
// #define ld long double
// #define V vector
// #define P pair
// #define S string
// #define MS multiset
// #define UM unordered_map
// #define US unordered_set
// #define MM multimap
// #define mp make_pair
// #define pb push_back
// #define pf push_front
// #define fi first
// #define se second
// #define FAST ios_base::sync_with_stdio(false), cin.tie(NULL);

// #define all(a) a.begin(), a.end()
// #define print(x)                \
//     for (auto element : x)      \
//         cout << element << " "; \
//     cout << endl
// #define db(x) cout << #x << " = " << x << "\n"
// #define range(i, n) for (ll i = 0; i < n; i++)
// #define ranges(i, s, n) for (ll i = s; i < n; i++)
// #define sranges(i, start, stop, step) for (ll i = start; i < stop; i = i + step)
// #define pb push_back
// #define mp make_pair
// #define all(a) a.begin(), a.end()
// #define testcase(t) \
//     new_int_1(t);   \
//     range(i, t)
// #define new_string(str) \
//     string str;         \
//     cin >> str;
// #define new_int_1(t) \
//     ll t;            \
//     cin >> t;
// #define new_int_2(a, b) \
//     ll a, b;            \
//     cin >> a >> b;
// #define new_int_3(a, b, c) \
//     ll a, b, c;            \
//     cin >> a >> b >> c;
// #define new_int_4(a, b, c, d) \
//     ll a, b, c, d;            \
//     cin >> a >> b >> c >> d;
// const ll mod = 1000000007;
// const ll mod2 = 998244353;
// const ld pi = acos(-1);
// typedef vector<string> vs;
// typedef vector<ll> vi;
// typedef pair<ll, ll> pii;
// typedef pair<ll, string> pis;
// typedef pair<string, string> pss;
// typedef pair<string, ll> psi;
// typedef map<ll, ll> mii;
// typedef set<ll> si;

// ll input()
// {
//     new_int_1(n);
//     return n;
// }
// vi inputvec(ll n, ll start = 0)
// {
//     vi vec(n);
//     for (ll i = start; i < n; i++)
//     {
//         vec[i] = input();
//     }
//     return vec;
// }
// ll func()
// {
//     new_int_2(a, b);
//     if (b > a)
//         swap(b, a);
//     if (a == b)
//     {
//         cout << 0 << " " << 0 << endl;
//         return 0;
//     }
//     ll ans1 = a - b;
//     if (a % ans1 == 0)
//     {
//         cout << ans1 << " " << 0 << endl;
//         return 0;
//     }
//     else
//     {
//         ll base = a / ans1 * ans1;
//         ll up = base + ans1;
//         if (abs(up - a) > abs(base - a))
//         {
//             cout << ans1 << " " << abs(base - a) << endl;
//             return 0;
//         }
//         else
//         {
//             cout << ans1 << " " << abs(up - a) << endl;
//             return 0;
//         }
//     }

//     return 0;
// }
// ll main()
// {
//     // FAST;
//     testcase(t)
//     {
//         func();
//     }
// }

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a == b)
            cout << 0 << " " << 0 << endl;
        else
        {
            ll dif = abs(b - a);
            cout << dif << " " << min(a % (dif), dif - a % (dif)) << endl;
        }
    }
}