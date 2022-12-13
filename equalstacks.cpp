// #include <bits/stdc++.h>
// using namespace std;
// #define ll signed long long int
// ll func()
// {
//     ll i, num1, num2, num3;
//     cin >> num1 >> num2 >> num3;
//     ll arr1[num1], arr2[num2], arr3[num3];
//     for (i = 0; i < num1; i++)
//     {
//         cin >> arr1[i];
//     }
//     for (i = 0; i < num2; i++)
//     {
//         cin >> arr2[i];
//     }
//     for (i = 0; i < num3; i++)
//     {
//         cin >> arr3[i];
//     }

//     // 	ll pre1[num1],pre2[num2],pre3[num3];
//     vector<ll> pre1(num1);
//     vector<ll> pre2(num2);
//     vector<ll> pre3(num3);

//     pre1[num1 - 1] = arr1[num1 - 1];
//     for (i = num1 - 2; i >= 0; i--)
//     {
//         pre1[i] = pre1[i + 1] + arr1[i];
//     }
//     pre2[num2 - 1] = arr2[num2 - 1];
//     for (i = num2 - 2; i >= 0; i--)
//     {
//         pre2[i] = pre2[i + 1] + arr2[i];
//     }
//     pre3[num3 - 1] = arr3[num3 - 1];
//     for (i = num3 - 2; i >= 0; i--)
//     {
//         pre3[i] = pre3[i + 1] + arr3[i];
//     }

//     reverse(pre1.begin(), pre1.end());
//     reverse(pre2.begin(), pre2.end());
//     reverse(pre3.begin(), pre3.end());

//     // 	ll check=0;
//     ll ans = 0;

//     for (i = num1; i >= 0; i--)
//     {
//         // pre1[i]
//         ll val = pre1[i];

//         if (binary_search(pre2.begin(), pre2.end(), val))
//         {
//             if (binary_search(pre3.begin(), pre3.end(), val))
//             {
//                 ans = val;
//                 // check=1;
//                 break;
//             }
//         }
//     }

//     cout << ans << endl;
// }
// int main()
// {

//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// typedef long double ld;
// typedef std::vector<ll> vll;
// typedef std::vector<int> vi;

// #define endl '\n'
// #define mp make_pair
// #define pb(x) push_back((x))
// #define what_is(x) cerr << #x << " is " << x << endl;

// ll MOD = 1e9 + 7;
// ll INF = LLONG_MAX;

// vector<string> &split(const std::string &s, char delim, vector<string> &e)
// {
//     stringstream ss(s);
//     string item;
//     while (getline(ss, item, delim))
//         e.push_back(item);
//     return e;
// }

// ll Pow(ll a, ll b, ll Mo)
// {
//     ll ans = 1;
//     for (; b; b >>= 1, a = a * a % Mo)
//         if (b & 1)
//             ans = ans * a % Mo;
//     return ans;
// }

// vector<int> Zfunc(string &s)
// {
//     int n = s.length();
//     vector<int> z(n, 0);
//     for (int i = 1, l = 0, r = 0; i < n; i++)
//     {
//         if (i <= r)
//             z[i] = min(z[i - l], r - i + 1);
//         while (i + z[i] < n && s[i + z[i]] == s[z[i]])
//             z[i]++;
//         if (r < i + z[i] - 1)
//             l = i, r = i + z[i] - 1;
//     }
//     return z;
// }

// ll solve()
// {
//     ll n, m, x;
//     cin >> n >> m >> x;
//     std::vector<ll> v1(n + 1, 0), v2(m + 1, 0);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> v1[i + 1];
//         v1[i + 1] += v1[i];
//     }
//     for (int i = 0; i < m; ++i)
//     {
//         cin >> v2[i + 1];
//         v2[i + 1] += v2[i];
//     }
//     ll mn = 0;
//     for (int i = 0; v1[i] <= x && i <= n; ++i)
//     {
//         ll canm = x - v1[i];
//         ll l = 0, u = m;
//         ll ans = 0;
//         while (l <= u)
//         {
//             ll m = (l + u) / 2;
//             if (v2[m] <= canm)
//             {
//                 ans = m;
//                 l = m + 1;
//             }
//             else
//                 u = m - 1;
//         }
//         mn = max(mn, ans + i);
//     }
//     cout << mn;

//     return 0;
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0);
//     // cout<<fixed<<setprecision(1);

//     int T;
//     cin >> T;
//     for (int i = 0; i < T; ++i)
//     {
//         //        cout<<"Case #"<<i+1<<": ";
//         solve();
//         cout << endl;
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int p[100000000];

int main()
{

    int n, q, x;
    cin >> n >> q;
    stack<int> original;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        original.push(x);
    }

    for (int i = 0; i < 100000000; i++)
        p[i] = 1;
    p[0] = p[1] = 0;

    for (int i = 2; i < 10000; i++)
    {
        if (p[i] == 1)
        {
            for (int j = i * i; j < 100000000; j = j + i)
                p[j] = 0;
        }
    }

    vector<int> primes;
    for (int i = 2; i < 100000000; i++)
        if (p[i] == 1)
            primes.push_back(i);

    stack<int> divisible, not_divisible;
    int m = 0;
    while (q--)
    {

        while (!original.empty())
        {
            if (original.top() % primes[m] == 0)
                divisible.push(original.top());
            else
                not_divisible.push(original.top());

            original.pop();
        }

        while (!divisible.empty())
        {
            cout << divisible.top() << "\n";
            divisible.pop();
        }

        stack<int> aux;
        while (!not_divisible.empty())
        {
            aux.push(not_divisible.top());
            not_divisible.pop();
        }

        while (!aux.empty())
        {
            original.push(aux.top());
            aux.pop();
        }

        m++;
    }

    while (!original.empty())
    {
        cout << original.top() << "\n";
        original.pop();
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}