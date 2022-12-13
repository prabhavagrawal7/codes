
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
        if(q == nullptr) break;
        p = q;
        q = q->next;
        
    }
    return p;
}
int main()
{
    auto head = createhead(10);
    appendvaluelast(head, 20);
    appendvaluelast(head, 30);
    appendvaluelast(head, 40);
    appendvaluelast(head, 50);
    // print(head);
    auto newhead = reverseList(head);
    print(newhead);
}
