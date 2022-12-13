#include<iostream>
using namespace std;

int main(){
    //write your code from here
    int test_cases, n, d, days, not_waste_num, risk = 0, n_risk = 0;
    cin >> test_cases;
    while (test_cases > 0)
    {
        risk = 0, n_risk = 0;
        cin >> n >> d;
        for (int i = 0; i < n; i++)
        {
            cin >> not_waste_num;
            if(not_waste_num >= 80 || not_waste_num <= 9){
                risk += 1;
            }
        }
        if(risk % d == 0){
        days = risk/d;
        }
        else{
            days = risk/d + 1;
        }
        
        n_risk = n-risk;
        
        if(n_risk % d == 0){
        days += n_risk/d;
        }
        else{
            days += n_risk/d + 1;
        }
        cout << days;
        test_cases -= 1;
    }
    

    return 0;
}