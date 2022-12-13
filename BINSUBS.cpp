#include <iostream>
using namespace std;
int func()
{
    string str;
    int str_len;
    cin >> str_len;
    int zeros = 0, ones = 0, sum = 0, high_index = 0, before_index = 0, after_index = 0, not_considered = 0;
    cin >> str;
    for (int i = 0; i < str_len; i++)
    {
        if (str[i] == '0')
        {
            zeros += 1;
        }
        else
        {
            ones += 1;
        }
    }
    after_index = ones;
    sum = after_index;
    for (int i = 0; i < str_len; i++)
    {
        if (str[i] == '0')
        {
            before_index += 1;
        }
        else
        {
            // not_considered += 1;
            after_index -= 1;
        }
        if (sum < before_index + after_index)
        {
            sum = before_index + after_index;
            high_index = i;
        }
    }
    cout << str_len - sum << endl;

    return 0;
}
int main()
{
    
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }

    return 0;
}