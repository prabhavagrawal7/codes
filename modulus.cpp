#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    //write your code from here
    int test_cases, a, b, c, x;
    cin >> test_cases;
    while (test_cases > 0)
    {
        cin >> a >> b >> c;
        x = 2*b -a -c;
        if(x < 0){x = -x;} //making result positive

        if(x % 2 == 0){
            cout << x/2 << "\n";
        }
        else
        {
            cout << x/2+1 << "\n";
        }
        test_cases -= 1;
    }
    

    return 0;
    abs()
}