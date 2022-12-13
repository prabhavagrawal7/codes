#include<bits/stdc++.h>

using namespace std;

int primesieve[2000001];


int sieve(){
	int n; cin >> n;	
	cout << primesieve[n] << endl;
	return 0;    
}

int main(){
	//write your code from here
	int test_case;
	int last_no = 1000000;
	cin >> test_case;
	//primesieve<start>
	
	for (int i = 0; i <= last_no; i++)
	{
		primesieve[i] = true;
	}
	
	for (int i = 2; i*i <= last_no; i++)
	{
		if(primesieve[i] == true){
			for(int j = i*i; j <= last_no; j+= i){
			primesieve[j] = false;
			}
		}
	}
	primesieve[0] = 0; primesieve[1] = 0;
	//prime sieve<end>	
	
    //sieve<modification>
    for (int i = last_no; i >= 2; i--)
    {
        if(primesieve[i] == 0){continue;}
        if(primesieve[i - 2] == 0){primesieve[i] = 0;} 
    }
    //Sieve</modification>
	
	//sieve<modification2>
	for (int i = 1; i <= last_no; i++)
	{
		primesieve[i] += primesieve[i-1];
	}
	
	while (test_case--)
	{
		sieve();
	}
	
	
	
	return 0;
}




