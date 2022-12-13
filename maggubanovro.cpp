#include <bits/stdc++.h>
using namespace std;

int main()
{
    //write your code from here
    int testcases;
    cin >> testcases;
    map <int, int> marks;
    int x, y, highest = 0, roll = INT_MAX;
    for (int i = 0; i < testcases; i++)
    {
        cin >> x >> y;
        if(marks.find(x) == marks.end()){
            marks[x] = y;
        }
        else
        {
            marks[x] += y;
        }
        if(highest <= marks[x]){
            if(highest < marks[x]){
                highest = marks[x];
                roll = x;
            }
            else if(highest == marks[x] && x < roll){
                roll = x;
            }
        }
        cout << roll << endl;
    }

    return 0;
}
