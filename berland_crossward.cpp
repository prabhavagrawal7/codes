// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// int mod(ll a)
// {
//     if (a < 0)
//     {
//         a = a + 4;
//     }
//     else
//     {
//         a = a % 4;
//     }
//     return a;
// }
// void inputarr(ll arr[], ll n, ll m = 0)
// {
//     for (int i = m; i < n; i++)
//     {
//         cin >> arr[i];
//     }
// }
// int func()
// {
//     ll n, u, r, d, l;
//     ll counter = 0;
//     ll arr[4];
//     cin >> n;
//     inputarr(arr, 4);

//     for (int i = 0; i < 4; i++)
//     {
//         if (arr[i] == n)
//         {
//             counter += 1;
//         }
//     }
//     if (counter == 0)
//     {
//         for (int i = 0; i < 4; i++)
//         {
//             if (arr[mod(i)] == n - 1 && arr[mod(i + 1)] == n - 1)
//             {
//                 if (arr[mod(i + 2)] < 1 || arr[mod(i + 3)] < 1)
//                 {
//                     cout << "NO" << endl;
//                     return 0;
//                 }
//             }

//             if (arr[mod(i)] == n - 1 && arr[mod(i + 2)] == n - 1)
//             {
//                 if ((arr[mod(i + 1)] < n - 2 && arr[mod(i + 3)] > 2) || (arr[mod(i + 3)] < n - 2 && arr[mod(i + 1)] > 2))
//                 {
//                     cout << "YES" << endl;
//                     return 0;
//                 }
//                 else if ((arr[mod(i + 1)] > 1 && arr[mod(i + 3)] > 1))
//                 {
//                     cout << "YES" << endl;
//                     return 0;
//                 }
//                 else
//                 {
//                     cout << "NO" << endl;
//                     return 0;
//                 }
//             }
//         }
//     }
//     if (counter == 1)
//     {
//         ll i = 0;
//         for (i = 0; i < 4; i++)
//         {
//             if (arr[i] == n)
//             {
//                 break;
//             }
//         }
//         if (arr[mod(i - 1)] == 0 || arr[mod(i + 1)] == 0)
//         {
//             cout << "NO" << endl;
//             return 0;
//         }
//     }
//     if (counter == 2)
//     {
//         if (arr[0] == n && arr[2] == n && arr[1] < 2 && arr[3] < 2)
//         {
//             cout << "NO" << endl;
//             return 0;
//         }
//         else if (arr[1] == n && arr[3] == n && arr[0] < 2 && arr[2] < 2)
//         {
//             cout << "NO" << endl;
//             return 0;
//         }
//         else if (arr[0] == n && arr[1] == n && arr[2] < 1 && arr[3] < 1)
//         {
//             cout << "NO" << endl;
//             return 0;
//         }
//         else if (arr[2] == n && arr[3] == n && arr[0] < 1 && arr[1] < 1)
//         {
//             cout << "NO" << endl;
//             return 0;
//         }
//     }
//     if (counter == 3)
//     {
//         ll i = 0;
//         for (i = 0; i < 4; i++)
//         {
//             if (arr[i] != n)
//             {
//                 if (arr[i] < 2)
//                 {
//                     cout << "NO" << endl;
//                     return 0;
//                 }
//             }
//         }
//     }
//     cout << "YES" << endl;
//     return 0;
// }
// int main()
// {
//     //write your code from here
//     int testcases;
//     cin >> testcases;
//     while (testcases--)
//     {
//         func();
//     }
//     return 0;
// }
