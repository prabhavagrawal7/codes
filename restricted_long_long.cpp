#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const ll mod = 1000000007;
// const ll mod = 998244353;
inline ll rs(ll n) { return (n %= mod) >= 0 ? n : n + mod; }
/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define __RLL__ 1
template <typename T> ll power(T, ll);
inline ll inv(ll n) { return power(n, mod - 2); }
class rll
{
private:
    int64_t val;

public:
    rll power(unsigned long long y) { return ::power(val, y); }
    rll div_by(ll x) { return val / x; }
    friend inline istream &operator>>(istream &cc, rll &a) { return (cc >> a.val), (a += 0), cc; }
    operator int64_t() const { return val; }
    template <typename T>
    rll(T _val) : val(rs(_val)) {}
    rll() : val(0) {}
    // arithmetic operators
    inline rll operator++() { return val++; }
    inline rll operator--() { return val--; }
    inline rll operator+(rll a) { return rs(val + a.val); }
    inline rll operator-(rll a) { return rs(val - a.val); }
    inline rll operator*(rll a) { return rs(a.val * val); }
    inline rll operator/(rll a) { return inv(a) * *this; }
    inline rll operator%(rll a) { return rs(val % a.val); }
    template <typename T, typename U>
    friend inline rll operator+(T &&a, U &&b) { return rll(a) + rll(b); }
    template <typename T, typename U>
    friend inline rll operator-(T &&a, U &&b) { return rll(a) - rll(b); }
    template <typename T, typename U>
    friend inline rll operator*(T &&a, U &&b) { return rll(a) * rll(b); }
    template <typename T, typename U>
    friend inline rll operator/(T &&a, U &&b) { return rll(a) / rll(b); }
    template <typename T, typename U>
    friend inline rll operator%(T &&a, U &&b) { return rll(a) % rll(b); }

    template <typename T, typename U>
    friend inline rll operator+=(T &&a, U &&b) { return a = rll(a) + rll(b); }
    template <typename T, typename U>
    friend inline rll operator-=(T &&a, U &&b) { return a = rll(a) - rll(b); }
    template <typename T, typename U>
    friend inline rll operator*=(T &&a, U &&b) { return a = rll(a) * rll(b); }
    template <typename T, typename U>
    friend inline rll operator/=(T &&a, U &&b) { return a = rll(a) / rll(b); }
    template <typename T, typename U>
    friend inline rll operator%=(T &&a, U &&b) { return a = rll(a) % rll(b); }

    // logical operators
    inline bool operator<(rll &&a) { return (val < a.val); }
    inline bool operator>(rll &&a) { return (val > a.val); }
    inline bool operator<=(rll &&a) { return (val <= a.val); }
    inline bool operator>=(rll &&a) { return (val >= a.val); }
    inline bool operator!() { return !val; }

    template <typename T, typename U>
    friend inline bool operator<(T &&a, U &&b) { return (ll)a < (ll)b; }
    template <typename T, typename U>
    friend inline bool operator>(T &&a, U &&b) { return (ll)a > (ll)b; }
    template <typename T, typename U>
    friend inline bool operator<=(T &&a, U &&b) { return (ll)a <= (ll)b; }
    template <typename T, typename U>
    friend inline bool operator>=(T &&a, U &&b) { return (ll)a >= (ll)b; }
};
template <typename T>
ll power(T _x, ll _y)
{
    rll x = _x;
    _y %= mod - 1;
    rll res = 1;
    while (_y)
    {
        if (_y & 1LL)
            res *= x;
        _y >>= 1;
        x = x * x;
    }
    return res;
}


int main()
{
    rll x = -2;
    cerr << (inv(2)); 
    return 0;
}