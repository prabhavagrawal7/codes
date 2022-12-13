
#include <iostream>

using namespace std;

int main() {
	int arr_len, height1, height2, groups = 1;
	cin >> arr_len >> height1;
	for(int i = 1; i < arr_len; i++){
		cin >> height2;
		if(height2 >= height1){
			height1 = height2;
		}
		else{
			height1 = height2;
			groups += 1;
		}
	}
	cout << groups;
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
