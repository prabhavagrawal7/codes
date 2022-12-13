#include <bits/stdc++.h>

using namespace std;
int timetaker()
{
    int HH, MM, num;
    char a, waste;
    scanf("%d:%d %c%c", &HH, &MM, &a, &waste);
    if (a == 'A')
    {
        num = 100 * HH + MM;
    }
    else
    {
        num = 100 * HH + MM + 1200;
    }

    if (HH == 12)
    {
        return num - 1200;
    }
    return num;
}
int func()
{
    int ltime, rtime, time, test_case;
    string s = "";
    time = timetaker();
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        ltime = timetaker();
        rtime = timetaker();
        if(ltime > rtime){
            rtime += 2400;
        }
        if(rtime >= time && ltime <= time){
            s += "1";
        }
        else
        {
            s += "0";
        }
    }
    cout << s << '\n';
    return 0;
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