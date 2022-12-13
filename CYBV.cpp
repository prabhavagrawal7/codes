#include<iostream>
using namespace std;
int min_weapons(){
    long k, n;
    cin >> k >> n;
    return n/k;
}
int main(){
    //write your code from here
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        cout << min_weapons();
        test_cases -= 1;
    }
    

    return 0;
}