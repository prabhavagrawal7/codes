
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *createhead(int x)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void appendvaluelast(Node *head, int x)
{
    for (Node *itr = head;; itr = itr->next)
    {
        if (itr->next == NULL)
        {
            itr->next = createhead(x);
            break;
        }
    }
}
void deletefirstnode(Node *&head)
{
    if (head->next == NULL)
    {
        head = NULL;
        cout << "LIST IS EMPTY" << endl;
        return;
    }
    Node *deletehead = head;
    head = head->next;
    free(deletehead);
}
void deletelastnode(Node *head)
{
    if (head->next == NULL)
    {
        cout << "LIST IS EMPTY NOW" << endl;
        free(head);
        return;
    }
    for (head; head->next->next != NULL; head = head->next)
        ;

    Node *deletehead = head->next;
    head->next = NULL;
    free(deletehead);
}
void deletenode(Node *head, int x)
{
    if (x == 0)
    {
        deletefirstnode(head);
        return;
    }
    x = x - 1;
    while (x--)
        head = head->next;

    Node *p = head->next;
    head->next = head->next->next;
    free(p);
}
void print(Node *head)
{
    for (Node *itr = head; itr != NULL; itr = itr->next)
    {
        cout << itr->data << endl;
    }
}
struct Node *insertion(int val, struct Node *ptr)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = ptr;
    return temp;
}

Node *reverseList(Node *head)
{
    Node *lastadd = nullptr;
    auto p = head;
    auto q = head->next;
    while (true)
    {
        p->next = lastadd;
        lastadd = p;
        if (q == nullptr)
            break;
        p = q;
        q = q->next;
    }
    return p;
}

#include <bits/stdc++.h>

Node *cycle(Node *head)
{
    set<Node *> si;
    while (si.find(head) != si.end())
    {
        si.insert(head);
        head = head->next;
        if (head->next == nullptr)
            return nullptr;
    }
    return head;
}
Node *oddeven(Node *head)
{
    Node *p = head;
    Node *q = head->next;
    Node *o = head;
    Node *e = head->next;
    while (p != nullptr && q != nullptr)
    {
        if (p->next == nullptr)
            break;
        p->next = p->next->next;
        if (p->next == nullptr)
            break;
        q->next = q->next->next;
        p = p->next;
        q = q->next;
    }
    Node *i;
    for (i = o; i->next != nullptr; i = i->next)
    {
    }
    i->next = e;
    return o;
}
Node *mergesortedlist(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        if (head1 == nullptr && head2 == nullptr)
            return nullptr;
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
    }
    Node *ptr = nullptr;
    if (head1->data <= head2->data)
    {
        ptr = head1;
        ptr->next = mergesortedlist(head1->next, head2);
    }
    else
    {
        ptr = head2;
        ptr->next = mergesortedlist(head1, head2->next);
    }
    return ptr;
}
Node *sortList(Node *head, int k = -1)
{
    // when length of list is not known
    if (k == -1)
    {
        if (head != nullptr)
        {
            k = 1;
            Node *q = head;
            while (q->next != nullptr)
            {
                q = q->next;
                k++;
            }
        }
        else
            k = 0;
    }
    // when base condition is applied
    if (k == 1)
        return head;

    Node *q = head;
    for (int i = 1; i < k / 2; i++)
    {
        q = q->next;
    }
    Node *shead = q->next;
    q->next = nullptr;
    Node *a = sortList(head, k / 2);
    Node *b = sortList(shead, k - k / 2);
    
    Node *m = mergesortedlist(a, b);
    return m;
}

Node *mergeKLists(vector<Node *> &lists)
{
    while (lists.size() >= 2)
    {
        //[[1,4,5],[1,3,4],[2,6]]
        Node *h = mergesortedlist(lists[lists.size() - 1], lists[lists.size() - 2]);
        lists.pop_back();
        lists.pop_back();
        lists.push_back(h);
    }
    if (lists.size() < 1)
        return nullptr;
    else
        return lists[0];
}
Node *reverseKGroup(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;
    Node *p = head;
    Node *q = nullptr;
    for (int i = 0; i < k; i++)
    {
        if (p == nullptr)
        {
            return head;
        }
        if (i == k - 1)
            q = p;
        p = p->next;
    }
    q->next = nullptr;
    Node *jrhead = reverseKGroup(p, k);
    Node *rhead = reverseList(head);
    for (Node *ptr = rhead;; ptr = ptr->next)
    {
        if (ptr->next == nullptr)
        {
            ptr->next = jrhead;
            break;
        }
    }
    return rhead;
}

int main()
{
    auto head1 = createhead(1);
    appendvaluelast(head1, 3);
    appendvaluelast(head1, 5);
    appendvaluelast(head1, 2);
    appendvaluelast(head1, 4);
    print(sortList(head1));
}
