#include<iostream>
using namespace std;

int main(){
    //write your code from here
    int a = 20;
    int &b = a;
    b += 1;
    cout<<b;
return 0;
}