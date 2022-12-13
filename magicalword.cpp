#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int prime(int num){
	if(num == 2){
		return 1;
	}
	for(int i = 2; i <= sqrt(num); i++){
		if(num%i == 0){
			return 0;
		}	
	}
	return 1;
}

int main(){
	int test_cases, prime_arr[100],i = 0, len, ascii, upper_lim, lower_lim;
	cin >> test_cases;
	string s;
	
	for(int j = 0; j < 542; j++){//Getting prime numbers in arr
			if(prime(j) == 1){
				prime_arr[i] = j;
				i += 1; 
			}

	}

	while(test_cases > 0){
	cin >> len >> s;
    for (int k = 0; k < s.length(); k++)
    {
        // cout <<"Executed k-" << k; 
        ascii = (int)s[k];
        i = 0;
        upper_lim = 0, lower_lim = 600;
        while (upper_lim < ascii)
        {   
            upper_lim = prime_arr[i];
            i += 1;
        }
        i = 99;
        while (lower_lim > ascii)
        {
            lower_lim = prime_arr[i];
            i -= 1;
        }
        if(ascii - lower_lim <= upper_lim - ascii){
            cout << "old_ascii :- " << s[k] << "\n";
            s[k] = (char)lower_lim;
            cout << "lower_lim-" << lower_lim << "\n";
            cout << "new_ascii :- " << s[k] << "\n\n";
        }
        else{
            cout << "old_ascii :- " << s[k] << "\n";
            s[k] = (char)upper_lim;
            cout << "upper_lim-" << upper_lim <<"\n";
            cout << "new_ascii :- " << s[k] << "\n\n";
        }
        

    }
    
	test_cases -= 1;
    cout << s << "\n";
	}
    return 0;
}
	
