// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define ll long long
// #define debug(x)                \
//     for (auto element : x)      \
//         cout << element << " "; \
//     cout << endl
// #define debugp(x)          \
//     for (auto element : x) \
//     cout << element.first << " " << element.second << endl
// #define db(x) cout << #x << " = " << x << "\n"
// #define rep(i, k, n) for (ll i = k; i < n; i++)
// #define rept(i, k, n) for (auto i = k; i != n; ++i)
// #define drep(i, k, n) for (ll i = k; i >= n; i--)
// #define pb push_back
// #define mp make_pair
// #define all(a) a.begin(), a.end()
// #define ld long double
// #define clr(s) memset(s, 0, sizeof(s))
// #define new_string(str) \
//     string str;         \
//     stringinput(str);
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
// #define new_int_5(a, b, c, d, e) \
//     ll a, b, c, d, e;            \
//     cin >> a >> b >> c >> d >> e;
// #define new_int_6(a, b, c, d, e, f) \
//     ll a, b, c, d, e, f;            \
//     cin >> a >> b >> c >> d >> e;
// typedef vector<string> vs;
// typedef vector<vector<ll>> vvi;
// typedef vector<ll> vi;
// typedef vector<pair<ll, ll>> vii;
// typedef vector<set<ll>> vsi;
// typedef vector<set<pair<ll, ll>>> vspii;
// typedef vector<vector<pair<ll, ll>>> vvpii;
// typedef pair<ll, ll> pii;
// typedef pair<ll, pair<ll, ll>> pipii;
// typedef pair<ll, string> pis;
// typedef pair<string, string> pss;
// typedef map<ll, ll> mii;
// typedef map<string, ll> msi;
// typedef map<char, ll> mci;
// typedef map<string, string> mss;
// typedef set<ll> si;
// typedef set<pair<ll, ll>> spii;
// typedef set<pair<string, ll>> spsi;
// const ll mod = 1000000007;
// const ll mod2 = 998244353;
// void stringinput(string &str)
// {
//     cin >> str;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Person
// {
// protected:
//     string name;

// public:
//     void setName(string iname)
//     {
//         name = iname;
//     }
// };
// class student : private Person
// {
// public:
//     void display()
//     {
//         cout << name << endl;
//     }
//     void setstud(string iname)
//     {
//         setName(iname);
//     }
// };
// class gsstudent : public student
// {
// public:
//     void setgs(string iname)
//     {
//         name = iname;
//     }
// };
// int main()
// {
//     gsstudent tanu;
//     //tanu.setstud("Tanu");
//     tanu.setgs("tanu");
//     // tanu.setName("Tanu");
//     // tanu.name="anu";    give an error becose name is protected
//     tanu.display();
// }