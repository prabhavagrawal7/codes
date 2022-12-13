// #include <iostream>
// using namespace std;

// int lowerkey(int arr[], int r, int key)
// {
//     int l = 0, mid;
//     r = r - 1;

//     while (l <= r)
//     {
//         mid = (l + r) / 2;
//         if (arr[mid] == key)
//         {
//             // cout << "H";
//             return mid;
//         }
//         else if (arr[mid] < key)
//         {
//             l = mid + 1;
//         }
//         else
//         {
//             r = mid - 1;
//         }
//     }
//     if (arr[mid] > key)
//     {
//         return mid - 1;
//     }
//     else
//     {
//         return mid;
//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 7, 10, 18, 20};
//     for (int i = 0; i < 20; i++)
//     {
//         cout << lowerbound(arr, 8, i) << " " << i << endl;
//     }
// }