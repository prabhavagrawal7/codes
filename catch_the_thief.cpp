#include<iostream>
using namespace std;
int catch_pow(int x, int y, int k, int n){
    int pos_dif = y-x;
    if(pos_dif < 0){ pos_dif = -pos_dif;}
    
    if( (pos_dif)%(2*k) == 0 ){
        return 1;
    }
    return 0;
}
int main(){
    //write your code from here
    int test_cases, x, y, k, n;
    cin >> test_cases;
    while (test_cases > 0)
    {
        cin >> x >> y >> k >> n;
        if(catch_pow(x, y, k, n) == 0){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
        test_cases -= 1;
    }
    
    return 0;
}