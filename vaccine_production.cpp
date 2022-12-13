#include<iostream>
using namespace std;

int main(){
    //write your code from here
    int d1, v1, d2, v2, p, days =1 , tot_vaccines =0;
    cin >> d1 >> v1 >> d2 >> v2>> p;
    while (tot_vaccines < p)
    {
        if(days >= d1){
            tot_vaccines += v1;
        }
        if(days >= d2){
            tot_vaccines += v2;
        }
        days += 1;
    }
    days -= 1;
    cout << days;

    return 0;
}