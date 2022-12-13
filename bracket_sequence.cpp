#include <iostream>

using namespace std;

int main() {
	// your code goes here
	float c_money;
    int withdraw_mon;
	cin >> withdraw_mon >> c_money ;
	if(withdraw_mon % 5 != 0){
	    cout << c_money;
	}
	else if(withdraw_mon + 0.50 > c_money){
	    cout << c_money;
	}
	else{
	    cout << c_money - withdraw_mon - 0.50;
	}
	
	return 0;
}