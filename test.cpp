#include<bits/stdc++.h>
using namespace std; 
int lis(vector<int> &height)
{
    vector<int> s;
    for (int i = 0; i < height.size(); i++)
    {
        auto a = lower_bound(s.begin(), s.end(), height[i]);
        if (a == s.end())
            s.push_back(height[i]);
        else
            *a = height[i];
    }
    return s.size();
}
int main()
{
    int n; cin >> n; 
    vector<int> vec; 
    for(int i = 0; i < n; i++)
    {
        int x; 
        cin >> x; 
        vec.push_back(x); 
    }
    if(lis(vec) >= 3) {
        cout << 1 << endl; 
    }
    else {
        cout << 0 << endl; 
    }
}