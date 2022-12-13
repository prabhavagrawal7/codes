#include<iostream>
#include<string>
using namespace std;
int min_attendence(int N, string str){
    int n_refined = 0;
    for (int i = 0; i < N; i++)
    {
        if(str[i] == '1'){
            n_refined += 1;
        }
    }
    if(120 + n_refined - N >= 90){
        return 1;
    }
    return 0;
}
int main(){
    //write your code from here
    int test_cases, N;
    string str;
    cin >> test_cases;
    while (test_cases > 0)
    {
        cin >> N;
        cin >> str;
        if(min_attendence(N, str) == 1){
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        test_cases-= 1;
    }
    

    return 0;
}