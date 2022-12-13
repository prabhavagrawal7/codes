#include<iostream>
using namespace std;

int main(){
	//write your code from here
	long arr_len, num, sum, gen_num_check;
	cin >> arr_len;
	for (int i = 0; i < arr_len; i++)
	{
		cin >> num;
		while (num >= 10)
		{
			if(i < arr_len/2){
				num = num/10;	// retriving first digit
				}
			else
			{
				num = num%10;	// retriving last digit
			}
			
		}
		if (i%2 == 0)	//adding elements in sum2
		{
			sum += num;
		}
		else	//adding elements in sum1
		{
			sum -= num;
		}
		
		
	}
	if(sum % 11 == 0){
		cout << "OUI";
		return 0;
	}
	cout << "NON";
	
	
	return 0;
}