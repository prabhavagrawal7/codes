#include<iostream>
using namespace std;

int main(){
    //write your code from here
    int arr_len, num, right_max;
    cin >> arr_len;
    int arr[arr_len];
    for (int i = 0; i < arr_len; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < arr_len; i++)
    {
        right_max = arr[i];
        for (int j = i+1; j < arr_len; j++)
        {
                if(right_max < arr[j]){
                    right_max = arr[j];
                    i = j;
                }

        }
        cout << right_max << " ";
        // if(i == arr_len-1){
        //     cout<< arr[i];
        //     break;
        //     }       
        
    }
    // cout << arr[arr_len-1];
    

    return 0;
}
