
// #include<iostream>
// using namespace std;
// int logic(int flag, string str){
//     int i, counter = 0, str_len = str.length();

//     for (i = flag; i < str_len; i++)
//     {
//         if(str[i] == '('){
//             counter += 1;
//         }
//         else{
//             counter -=1;
//         }
//         if(counter < 0){
//             return 0;
//         }
//     }

//     for (i = 0; i < flag; i++)
//     {
//         if(str[i] == '('){
//             counter += 1;
//         }
//         else{
//             counter -=1;
//         }
//         if(counter < 0){
//             return 0;
//         }
//     }
//     return 1;
    

    
    

    
    
    
// }
// int main(){
//     //write your code from here
//     int c1 =0;
//     string str;
//     cin >> str;
//     for (int i = 0; i < str.length(); i++)
//     {
//         if(logic(i, str) == 1){
//             c1 += 1;
//         }
        
//     }
//     cout << c1;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int logic(int flag, string str){
    int i, counter = 0, str_len = str.length();

    for (i = flag; i < str_len; i++)
    {
        if(str[i] == '('){
            counter += 1;
        }
        else{
            counter -=1;
        }
        if(counter < 0){
            return 0;
        }
    }

    for (i = 0; i < flag; i++)
    {
        if(str[i] == '('){
            counter += 1;
        }
        else{
            counter -=1;
        }
        if(counter < 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    //write your code from here
    string str;
    cin >> str;
    int c1 =0, jump = 0, counter = 0, str_len = str.length();
    for (int i = 0; i < str_len; i++)
    {
        if(logic(i, str) == 1){
            c1 = i;
            cout << endl << c1;
            break;

        }

    }

    for (int i = c1; i < str_len; i++)
    {
        if(str[i] == '('){
            counter += 1;
        }
        else{
            counter -= 1;
        }
        // cout << endl << counter;
        if(counter == 0){
            jump += 1;
            // cout << "Executed";
        }
    }
    
    // cout << jump+1;
    return 0;
}


