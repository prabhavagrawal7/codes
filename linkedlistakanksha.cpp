#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct node *insert(struct node *head, int val)
{
    node* p = new node();

    p->next = head;
    p->data = val;
    head = p;

    return head;
}

void mid(struct node* head)
{
    node *p = new node();
    node *temp = head;
    node *t = head;
    int c = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        c++;
    }
    if (c % 2 == 0)
    {
        for (int i = 0; i < c / 2; i++)
        {
            t = t->next;
        }
        cout << t->data << endl;
    }

    else
    {
        for (int i = 0; i < c / 2; i++)
        {
            t = t->next;
        }
        cout << t->data << endl;
    }
}

struct node *midel(struct node *head)
{
    node *p = head;
    node *temp = head;
    node *t = head;
    int c = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        c++;
    }

    for (int i = 0; i < ceil(c / 2); i++)
    {
        t = t->next;
    }
    for (int i = 0; i < ceil(c / 2) - 1; i++)
    {
        p = p->next;
    }

    p->next = t->next;
    free(t);

    return p;
}

int display(node *head)
{
    node *temp = head;
    int c = 0;
    while (temp->next != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
        c++;
    }

    return c;
}

int main()
{

    node *head;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 7);
    head = insert(head, 54);
    head = insert(head, 34);
    // head= insert(head,13);
    mid(head);
    head = midel(head);

    display(head);
}