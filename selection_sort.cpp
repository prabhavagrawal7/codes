#include<iostream>
using namespace std;
int swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    return 0;
}
int main(){
    //write your code from here
    int arr_len, min_num = 10000, index;
    cin >> arr_len;
    int arr[arr_len];
    for (int i = 0; i < arr_len; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < arr_len; i++)
    {
        min_num = 10000;
        
        for (int j = i; j < arr_len; j++)
        {
            if(min_num > arr[j]){
                min_num = arr[j];
                index = j;
            }
        }
        swap(arr[index], arr[i]);
    }
    for (int i = 0; i < arr_len; i++)
    {
        cout << arr[i] << " ";
    }
    
    

    return 0;
}