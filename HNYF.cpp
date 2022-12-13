// // #include<iostream>
// // #include<string>
// // #include<cmath>
// // using namespace std;

// // int func(){
// //     long long c_len, sum = 0;
// //     cin >> c_len;
// //     string str;
// //     // cin >> arr_len;
// //     cin >> str;
// //     for (long long i = 0; i < c_len; i++)
// //     {
// //         if(str[i] == '0'){
// //             continue;
// //         }
// //         sum += pow(2, c_len-i-1);
// //     }
// //     cout << sum << endl;
    
// //     return 0;
// // }
// // int main(){
// //     //write your code from here
// //     int testcases;
// //     cin >> testcases;
// //     while (testcases > 0)
// //     {
// //         func();
// //         testcases -=1;

// //     }
    

// //     return 0;
// // }
// #include <iostream>
// using namespace std;
// int fact(int num){
//     if(num == 0){
//     return 1;    
//     }
//     return fact(num-1)*num;
// }
// int main(){
//     int num;
//     cin >> num;
//     cout << fact(num);
//     return 0;
// }
#include<iostream>
using namespace std;
int main()
{
    int N; 
    int Factorial=1;
    cin >> N;
    for ( int a =1; a <= N; a++)
    {
        Factorial= Factorial*a;
    }
    cout << Factorial << endl;
return 0;
}