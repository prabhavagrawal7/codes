#include <iostream>
using namespace std;
#define ll long long
class stack
{
    struct node
    {
        ll value;
        node *node;
    };
    node *head = NULL;

public:
    template <typename T>
    stack(T container)
    {
        for (auto i : container)
        {
            this->push(i);
        }
    }
    stack() {}

    void push(ll value)
    {
        if (head == NULL)
        {
            node *q = new node;
            q->node = NULL;
            q->value = value;
            head = q;
        }
        else
        {
            node *q = new node;
            q->node = head;
            q->value = value;
            head = q;
        }
    }

    ll pop()
    {
        node *&head = this->head;
        ll value = -10e7;

        if (head == NULL)
        {
            cout << "Empty Queue" << endl;
        }
        else if (head->node == NULL)
        {
            ll value = head->value;
            cout << value << endl;
            free(head);
            head = NULL;
        }
        else
        {
            node *q = head->node;
            ll value = head->value;
            free(head);
            head = q;
            cout << value << endl;
        }
        return value;
    }
};
int main()
{
    stack q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
}
