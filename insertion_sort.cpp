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
    int arr_len, flag, j, hole;
    cin >> arr_len;
    int arr[arr_len];
    for(int i = 0; i < arr_len; i++){
        cin >> arr[i];
    }
    
    for (int i = 1; i < arr_len; i++)
    {
        hole = i;
        flag = arr[hole];
        while (arr[hole-1] > flag && hole > 0)
        {
            arr[hole] = arr[hole-1];
            hole = hole -1;
        }
        arr[hole] = flag;
    }
    
    for (int i = 0; i < arr_len; i++)
    {
        cout << arr[i] << " ";
    }
    
    

    return 0;
}