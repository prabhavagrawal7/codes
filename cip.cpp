#include<iostream>
#include<string>
using namespace std;


int main(){
    //write your code from here
    int round;
    string str;
    cin >> str;
    int str_int, sum;
    cin >> round;

    for (int i = 0; i < str.length(); i++)
    {
        str_int = (int)str[i];
        sum = str_int +round;
        
        if((str_int >= 65 && str_int <= 90) || (str_int >= 97 && str_int <= 122) ||(str_int >= 48 && str_int <= 57)){
            
			if((int)str[i] >= 97 && sum >= 122 && str[i] <= 122){
                sum = 97+(sum-97)%26;
                
            }
            else if ((int)str[i] >= 65 && sum >= 90 && str[i] <= 90)
            {
                sum = 65 + (sum-65)%26;
                
            }
            else if ((int)str[i] >= 48 && sum >= 57 && str[i] <= 57)
            {
                sum = 48 + (sum-48)%10;
                
            }
            
            str[i] = (char)(sum);
            
        }
        
        
    }
    cout << str;

    return 0;
}