#include<iostream>
using namespace std;

long long evenpairsum(long long a, long long b){
    if(a % 2 == 0 && b % 2 == 0){
        return ((a/2)*(b/2)*2);
    }
    else if(a % 2 != 0 && b % 2 == 0){
        return ((a/2)*(b/2)+((a+1)/2)*(b/2));
    }
    else if(a % 2 == 0 && b % 2 != 0){
        return ((a/2)*(b/2)+((b+1)/2)*(a/2));
    }
    else
    {
        return ((a-1)/2)*((b-1)/2) + ((b+1)/2)*((a+1)/2);
    }
    return 0;
}

int main(){
    //write your code from here
    int test_cases;
    long long a, b, value_storer;
    cin >> test_cases;
    while (test_cases> 0)
    {
        cin >> a >> b;
        value_storer = evenpairsum(a,b);
        cout << value_storer << "\n";
        test_cases -= 1;
    }
    

    return 0;
}