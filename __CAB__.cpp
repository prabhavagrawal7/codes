#include <iostream>
#include <cmath>
using namespace std;
string stringmaker()
{
    int n, k, temp, r = 25;
    string str = "";
    cin >> n >> k;
    if (n > k)
    {
        return "-1";
    }
    while (r >= 0)
    {
        temp = k - pow(2, r);
        if (n > temp && temp >= 0)
        {
            n = n - 1;
            k = temp;
            str = str + (char)(97 + r);
            cout << "exxecuted" << endl;

            if (n == 0)
            {
                break;
            }
            continue;
        }
        r -= 1;
    }

    if (k > 0)
    {
        cout << k << endl;
        return "-1";
    }
    return str;
}
int main()
{
    //write your code from here
    cout << stringmaker();

    return 0;
}