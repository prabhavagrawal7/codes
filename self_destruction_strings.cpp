#include<iostream>
#include<string>
using namespace std;

int string_destructor(string str){
    
    int _0s = 0, _1s, str_len = str.length();
    

    
    for (int i = 0; i < str_len; i++)
    {
        if(str[i] == '0'){
            _0s += 1;
        }      
    }

    if(str_len %2 != 0 || _0s == 0 || _0s == str_len){
        return -1;
    }

    _1s = str_len-_0s; // now we got how many zeros & ones are there in string

    if(_1s >= _0s){
        return (str_len-2*_0s)/2;
    }
    else{
        return (str_len-2*_1s)/2;
    }
    
}
int main(){
    //write your code from here
    int test_cases, ans;
    cin >> test_cases;
    string str;
    while (test_cases > 0)
    {
        cin >> str;
        ans = string_destructor(str);
        cout << ans << "\n";
        test_cases -= 1;
    }
    

    return 0;
}