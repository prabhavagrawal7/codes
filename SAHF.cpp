#include<iostream>
using namespace std;

int func(){
    int arr_len, num;
    int a = 0;
    cin >> arr_len;
    for (int i = 0; i < arr_len; i++)
    {
        cin >> num;
        if(num == 0){
            a = 1;
        }
    }
    if(a == 1){
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}
int main(){
    //write your code from here
    int test_cases;
    cin >> test_cases;
    while(test_cases>0){
        func();
        test_cases-=1;
    }

    return 0;
}