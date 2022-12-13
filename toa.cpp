#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define V vector
#define P pair
#define S string
#define MS multiset
#define UM unordered_map
#define US unordered_set
#define MM multimap
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define print(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl
#define db(x) cout << #x << " = " << x << "\n"
#define range(i, n) for (ll i = 0; i < n; i++)
#define ranges(i, s, n) for (ll i = s; i < n; i++)
#define sranges(i, start, stop, step) for (ll i = start; i != stop; i = i + step)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define testcase(t) \
    new_int_1(t);   \
    range(i, t)
#define new_string(str) \
    string str;         \
    cin >> str;
#define new_int_1(t) \
    ll t;            \
    cin >> t;
#define new_int_2(a, b) \
    ll a, b;            \
    cin >> a >> b;
#define new_int_3(a, b, c) \
    ll a, b, c;            \
    cin >> a >> b >> c;
#define new_int_4(a, b, c, d) \
    ll a, b, c, d;            \
    cin >> a >> b >> c >> d;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ld pi = acos(-1);
typedef vector<string> vs;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef pair<ll, string> pis;
typedef pair<string, string> pss;
typedef pair<string, ll> psi;
typedef map<ll, ll> mii;
typedef set<ll> si;

const int NO_OF_STATES = 15;
int n1, n;

class States
{
public:
    char status;
    int sno;
    int gp;
    int *ts;

    States()
    {
        sno = gp = 0;
        ts = NULL;
    }
    States(int state_no)
    {
        gp = 0;
        sno = state_no;
        ts = new int[n];
        for (int i = 0; i < n; i++)
            ts[i] = -1;
    }

    void input()
    {
        char ch = 'a';
        cout << "\nEnter transition details for ";
        if (sno == 0)
            cout << "INITIAL ";
        cout << "state q" << sno << " : \n";
        for (int j = 0; j < n; j++, ch++)
        {
            cout << "State reached on Input " << ch << " : q";
            cin >> ts[j];
        }
        cout << "Non-final state or final? (N/F) : ";
        cin >> status;
        if (status == 'n' || status == 'N')
            gp = 0;
        else
            gp = 1;
    }

    void output()
    {
        if (sno == -1)
            return;
        cout << "\n\n    q" << sno << " |   ";
        for (int i = 0; i < n; i++)
            if (ts[i] != -1)
                cout << "     q" << ts[i];
            else
                cout << "    N/A";
        if (sno == 0)
            cout << "     Initial state";
        if ((status == 'f' || status == 'F') and (sno == 0))
            cout << " and Final state";
        else if (status == 'f' || status == 'F')
            cout << "     Final state";
    }
};

int exists(int s[], int ref)
{
    for (int i = 0; i < n1; i++)
        if (s[i] == ref)
            return i;
    return -1;
}

void check(vector<States> &state)
{
    int array[NO_OF_STATES], temp, newgp[NO_OF_STATES], flag = 0, count = 2;
    for (int outerloop = 0; outerloop < n1 - 2; outerloop++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int z = 0; z < NO_OF_STATES; z++)
                array[z] = -1;
            for (int i = 0; i < n1; i++)
            {
                temp = state[i].ts[j];
                for (int k = 0; k < n1; k++)
                    if (state[k].sno == temp)
                    {
                        array[i] = state[k].gp;
                        break;
                    }
            }

            for (int i = 0; i < n1 - 1; i++)
            {
                for (int z = 0; z < NO_OF_STATES; z++)
                    newgp[z] = -1;
                flag = 0;
                for (int k = i + 1; k < n1; k++)
                {
                    if (state[i].gp == state[k].gp)
                    {
                        if ((array[i] != array[k]) && ((flag == 0) || (exists(newgp, array[k]) == -1)))
                        {
                            state[k].gp = count;
                            count++;
                            newgp[k] = array[k];
                            flag++;
                        }
                        else if (array[i] != array[k])
                        {
                            state[k].gp = state[exists(newgp, array[k])].gp;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n1 - 1; i++)
    {
        if (state[i].sno != -1)
            for (int j = i + 1; j < n1; j++)
                if (state[i].gp == state[j].gp)
                {
                    for (int h = 0; h < n1; h++)
                        for (int z = 0; z < n; z++)
                            if (state[h].ts[z] == state[j].sno)
                                state[h].ts[z] = state[i].sno;
                    state[j].sno = -1;
                    if ((state[j].status == 'f') || (state[j].status == 'F'))
                        state[i].status = 'F';
                }
    }
}

int main()
{
    char ch = 'a';
    cout << "\nEnter DFA details : \n\n";
    cout << "\nHow many inputs? : ";
    cin >> n;
    cout << "\nEnter no. of states (max 15): ";
    cin >> n1;
    // States state[NO_OF_STATES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    vector<States> state = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    for (int i = 0; i < n1; i++)
        state[i].input();

    check(state);

    cout << "       |    Input Symbols\n";
    cout << "States |   ";
    for (int i = 0; i < n; i++, ch++)
        cout << "      " << ch;
    cout << endl;
    for (int i = 0; i < n + 3; i++)
        cout << "-----";

    for (int i = 0; i < n1; i++)
        state[i].output();
    cout << "\n\n";
}
