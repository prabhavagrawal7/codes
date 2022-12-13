#include <iostream>
#include <tuple>
using namespace std;
#define ll long long
class queue
{
    struct node
    {
        ll value;
        node *node;
    };
    node *head = NULL;
    node *tail = NULL;

public:
    template <typename T>
    queue(T container)
    {
        for (auto i : container)
        {
            this->enqueue(i);
        }
    }
    queue() {}

    void enqueue(ll value)
    {
        if (head == NULL)
        {
            node *q = new node;
            q->node = NULL;
            q->value = value;
            head = q;
            tail = head;
        }
        else
        {
            node *q = new node;
            q->node = head;
            q->value = value;
            head = q;
        }
    }

    ll dequeue()
    {
        node *&tail = this->tail;
        ll value = -10e7;

        if (tail == NULL)
        {
            cout << "Empty queue" << endl;
        }
        else if (tail->node == NULL)
        {
            ll value = tail->value;
            cout << value << endl;
            free(tail);
            tail = NULL;
        }
        else
        {
            node *q = tail->node;
            ll value = tail->value;
            free(tail);
            tail = q;
            cout << value << endl;
        }
        return value;
    }
};
int main()
{
    queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
}
