#include<iostream>
using namespace std;
int swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return 0;
}
int main(){
    //write your code from here
    int arr_len, flag;
    cin >> arr_len;
    int arr[arr_len];
    for (int i = 0; i < arr_len; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < arr_len-1; j++){
        flag = 0;
        for (int i = 0; i < arr_len-j; i++)
        {
            if(arr[i+1] < arr[i]){
                swap(arr[i+1], arr[i]);
                flag += 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
    for (int i = 0; i < arr_len; i++)
    {
        cout << arr[i] << " ";
    }
    
    

    return 0;
}