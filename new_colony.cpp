#include <bits/stdc++.h>

using namespace std;

int func()
{
    int n, m; cin >> n >> m;
    int init_p[n], final_p[n], painter[100001] = {0};
    int dis[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> init_p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> final_p[i];
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        painter[num] +=1;
    }
    for (int i = 0; i < n; i++)
    {
        if(init_p[i] != final_p[i]){
            if(painter[final_p[i]] == 0){cout << "NO" << endl;}
            painter[final_p[i]] -= 1; 
        }
    }
    for (int i = 0; i < 100001; i++)
    {
        
    }
    




    
}

int main()
{
    //write your code from here
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        func();
    }

    return 0;
}