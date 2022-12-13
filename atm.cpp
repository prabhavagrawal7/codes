#include <iostream>
using namespace std;

int main() {
	// your code goes here
	float c_money;
    int withdraw_mon;
	cin >> withdraw_mon >> c_money ;
	withdraw_mon = withdraw_mon + 0.50;
	if(withdraw_mon % 5 != 0){
	    cout << c_money << ".00";
	    return 0;
	}
	else if(withdraw_mon > c_money){
	    cout << c_money << ".00";
	    return 0;
	}
	else{
	    cout << c_money - withdraw_mon;
	    return 0;
	}
	
	return 0;
}