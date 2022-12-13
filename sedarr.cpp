#include <iostream>
using namespace std;
int operations(){
    int sum = 0, arr_len, k;
    cin >> arr_len >> k;
    int arr[arr_len];
    for (int i = 0; i < arr_len; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < arr_len; i++)
    {
        sum += arr[i];
    }

    if(sum % k == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main() {
	// your code goes here
    int test_cases, arr_len, k;
    cin >> test_cases;
    while (test_cases > 0)
    {
        cout << operations() << "\n";
        
        test_cases -= 1;
    }
    
	return 0;
}
