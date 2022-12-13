#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

// Uncomment them for optimisations
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

// for segment tree
// #define mid (start+end)/2
// #define lnode (node*2+1)
// #define rnode (node*2+2)

// printing bullshits open
template <typename _A, typename _B>
ostream &operator<<(ostream &os, const pair<_A, _B> &p)
{
    os
        << "[" << p.first << "," << p.second << "]";
    return os;
}
template <typename T, typename = void>
struct is_iterable : false_type
{
};
template <typename T>
struct is_iterable<T, void_t<decltype(begin(declval<T &>())), decltype(end(declval<T &>()))>> : true_type
{
};
template <typename T>
using is_string = is_same<decay_t<T>, string>;
template <typename T>
constexpr bool is_iterable_v = is_iterable<T>::value;
template <typename T>
typename enable_if<!is_iterable_v<T>, void>::type
__print(T &&container) { cout << container; }
template <typename T>
typename enable_if<is_iterable_v<T> && !is_string<T>::value, void>::type __print(T &&container)
{
    for (auto
             itr = container.begin();
         itr != container.end(); itr++)
    {
        __print(*itr);
        if (next(itr) != container.end())
            cout << ' ';
    }
}
template <typename T>
typename enable_if<is_string<T>::value, void>::type
__print(T &&string_container) { cout << string_container; }
template <typename T>
typename enable_if<is_same<T, const char *>::value, void>::type __print(T &&string_container) { cout << string_container; }
template <size_t N>
void __print(const char (&str)[N]) { cout << str; }
template <typename... T>
inline void print(T &&...args)
{
    ((__print(args), cout << " "), ...);
    cout << endl;
}
template <typename... T>
inline void printl(T &&...args) { ((__print(args), cout
                                                       << " "),
                                   ...); }
// printing bullshits close

#define popcount(x) __builtin_popcountll(x)
#define clz(x) (63 - __builtin_clzll(x)) // count leading zeros
#define ctz(x) __builtin_ctzll(x)        // count trailing zeros
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define range(...) GET_MACRO(__VA_ARGS__, r4, r3, r2, r1)(__VA_ARGS__)
#define r4(var, start, stop, step) for (ll var = start; step > 0 ? var < stop : var > stop; var = var + step)
#define r3(var, start, stop) for (ll var = start; var < stop; ++var)
#define r2(var, stop) for (ll var = 0; var < stop; ++var)
#define r1(stop) for (ll start_from_0 = 0; start_from_0 < stop; ++start_from_0)
#define newint(...) \
    ll __VA_ARGS__; \
    take_input(__VA_ARGS__)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define give(...)           \
    do                      \
    {                       \
        print(__VA_ARGS__); \
        return;             \
    } while (false)
#define endl "\n"
#define FULL_INF numeric_limits<double>::infinity()
#define INF INT64_MAX
#define INT_INF INT32_MAX
#define ld long double
#define V vector
#define P pair
#define S set
#define MS multiset
#define M map
#define UM unordered_map
#define US unordered_set
#define MM multimap
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(a) a.begin(), a.end()
#define db(x) cout << #x << " = " << x << "\n"
string db_bin(ll n)
{
    string ans;
    while (n)
    {
        ans.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(all(ans));
    return ans;
}
#define newstring(str) \
    string str;        \
    cin >> str;
#define foreach(a, x) for (auto &&a : x)
const ld pi = acos(-1);
typedef vector<string> vs;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef map<ll, ll> mii;
typedef set<ll> si;
typedef vector<vector<ll>> vvi;
template <typename... T>
inline void take_input(T &&...args) { ((cin >> args), ...); }
vi inputvec(ll n, ll start = 0)
{
    vi vec(n);
    range(i, start, n) cin >> vec[i];
    return vec;
}
template <typename T>
inline bool btn(T a, T b, T c)
{
    if ((a <= b && b <= c) || (a >= b && b >= c))
        return true;
    return false;
}
template <typename T>
istream &operator>>(istream &is, V<T> &v)
{
    range(i, v.size()) { is >> v[i]; }
    return is;
}
inline ld TLD(ll n) { return n; }
ll gcd(ll __m, ll __n) { return __n == 0 ? __m : gcd(__n, __m % __n); }
const ll mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n %= mod) >= 0 ? n : n + mod; }
// define rll above this
#ifndef __RLL__
ll power(ll x, ll y)
{
    x %= mod, y %= mod - 1;
    ll res = 1;
    while (y)
    {
        if (y & 1LL)
            res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res % mod;
}
ll inv(ll n) { return power(n, mod - 2); }
#endif
/* ----------------------------------------------------------------------------------------------*/

void func()
{
    newint(n);
    vi attack = inputvec(n + 1, 1);
    vi defence = inputvec(n + 1, 1);
    attack[0] = 0;
    defence[0] = 1e9 * 1e6;
    attack.push_back(0);
    defence.push_back(1e9 * 1e6);

    vi imleft(n + 2, 0), imright(n + 2, n + 1);
    range(i, 1, n + 2)
    {
        imleft[i] = i - 1;
        imright[i] = i + 1;
    }
    set<pair<ll, ll>> rounds;
    range(i, 1, n + 1)
    {
        ll left = 0, right = 0;
        if (i != 0)
            left = attack[i - 1];
        if (i != n - 1)
            right = attack[i + 1];
        ll total = left + right;
        rounds.insert({(defence[i] + total - 1) / total, i});
    }
    map<ll, ll> mapround;
    foreach (i, rounds)
        mapround[i.second] = i.first;

    vi ans(n + 1);
    while (rounds.size() > 1)
    {
        auto val = *rounds.begin();
        rounds.erase(rounds.begin());
        ll node = val.second;
        ll round = val.first;
        mapround.erase(node);
        if (round > ans.size())
            break;
        ans[round]++;
        ll left = imleft[node], right = imright[node];

        // update left node
        if (left != 0)
        {
            rounds.erase({mapround[left], left});
            mapround.erase(left);
            ll defenceleft = defence[left];
            ll oldattackleft = attack[imleft[left]] + attack[imright[left]];
            ll newattackleft = attack[imleft[left]] + attack[right];
            ll leftH = defenceleft - round * oldattackleft;
            ll leftV = (leftH + (newattackleft - 1)) / newattackleft;
            ll newleftdefence = ˝(round + leftV) * newattackleft;
            mapround[left] = (newleftdefence + newattackleft - 1) / newattackleft;
            rounds.insert({mapround[left], left});
        }

        // update right node
        if (right != n + 1)
        {
            rounds.erase({mapround[right], right});
            mapround.erase(right);
            ll defenceright = defence[right];
            ll oldattackright = attack[imleft[right]] + attack[imright[right]];
            ll newattackright = attack[left] + attack[imright[right]];
            ll rightH = defenceright - round * oldattackright;
            ll rightV = (rightH + (newattackright - 1)) / newattackright;
            ll newrightdefence = (round + rightV) * newattackright;
            mapround[right] = (newrightdefence + newattackright - 1) / newattackright;
            rounds.insert({mapround[right], right});
        }

        imright[left] = right;
        imleft[right] = left;
    }
    print(ans);
}
int main()
{
    FAST;
    newint(t);
    range(t)
    {
        func();
    }
}
