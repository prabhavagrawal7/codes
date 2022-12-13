#include <bits/stdc++.h>

using namespace std;

string s = "";
int func()
{
    long long attack, health, monsters;
    cin >> attack >> health >> monsters;
    long long m_attack[monsters], m_fights[monsters];
    for (long i = 0; i < monsters; i++)
    {
        cin >> m_attack[i];
    }
    for (long i = 0; i < monsters; i++)
    {
        long a;
        cin >> a;
        if (a % attack == 0)
        {
            m_fights[i] = a / attack;
        }
        else
        {
            m_fights[i] = a / attack + 1;
        }
    }
    for (long i = 0; i < monsters; i++)
    {
        health -= m_fights[i] * m_attack[i];
    }
    health += *max_element(m_attack, m_attack + monsters);
    if (health <= 0)
    {
        // cout << "NO" << endl;
        s += "NO\n";
        return 0;
    }
    else
    {
        // cout << "YES" << endl;
        s += "YES\n";
        return 0;
    }
    return 0;
}

int main()
{
    //write your code from here
    long test_case;
    cin >> test_case;
    while (test_case--)
    {
        func();
    }
    cout << s;
    return 0;
}
