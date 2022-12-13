
#include <iostream>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
};
ListNode *createhead(int x)
{
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void appendvaluelast(ListNode *head, int x)
{
    for (ListNode *itr = head;; itr = itr->next)
    {
        if (itr->next == NULL)
        {
            itr->next = createhead(x);
            break;
        }
    }
}
void deletefirstnode(ListNode *&head)
{
    if (head->next == NULL)
    {
        head = NULL;
        cout << "LIST IS EMPTY" << endl;
        return;
    }
    ListNode *deletehead = head;
    head = head->next;
    free(deletehead);
}
void deletelastnode(ListNode *head)
{
    if (head->next == NULL)
    {
        cout << "LIST IS EMPTY NOW" << endl;
        free(head);
        return;
    }
    for (head; head->next->next != NULL; head = head->next)
        ;

    ListNode *deletehead = head->next;
    head->next = NULL;
    free(deletehead);
}
void deletenode(ListNode *head, int x)
{
    if (x == 0)
    {
        deletefirstnode(head);
        return;
    }
    x = x - 1;
    while (x--)
        head = head->next;

    ListNode *p = head->next;
    head->next = head->next->next;
    free(p);
}
void print(ListNode *head)
{
    for (ListNode *itr = head; itr != NULL; itr = itr->next)
    {
        cout << itr->data << " ";
    }
    cout << endl;
}
struct ListNode *insertion(int val, struct ListNode *ptr)
{
    struct ListNode *temp;
    temp = new ListNode;
    temp->data = val;
    temp->next = ptr;
    return temp;
}
ListNode *reverseList(ListNode *head)
{
    ListNode *lastadd = nullptr;
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
ListNode *rotateRight(ListNode *head, int k)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    int length = 1;

    ListNode *tracker = head;
    for (length; tracker->next != nullptr; length++)
    {
        tracker = tracker->next;
    }
    k = k % length;
    if (k == 0)
        return head;
    ListNode *last = tracker;
    tracker = head;
    for (int i = 1; i < length - k; i++)
    {
        tracker = tracker->next;
    }
    auto ans = tracker->next;
    tracker->next = nullptr;
    last->next = head;
    return ans;
}
ListNode *partition(ListNode *head, int x)
{
    ListNode *xg = nullptr;
    ListNode *hxg = nullptr;
    ListNode *xs = nullptr;
    ListNode *hxs = nullptr;

    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        if (ptr->data >= x)
        {
            if (xg == nullptr)
            {
                xg = ptr;
                hxg = ptr;
            }
            else
            {
                xg->next = ptr;
                xg = xg->next;
            }
        }
        else
        {
            if (xs == nullptr)
            {
                xs = ptr;
                hxs = ptr;
            }
            else
            {
                xs->next = ptr;
                xs = xs->next;
            }
        }
    }
    if (xs != nullptr)
        xs->next = hxg;
    if (hxg != nullptr)
        xg->next = nullptr;
    if (hxs == nullptr)
        return hxg;
    return hxs;
}
int main()
{
    auto head = createhead(50);
    // appendvaluelast(head, 40);
    // appendvaluelast(head, 30);
    // appendvaluelast(head, 20);
    // appendvaluelast(head, 10);
    print(head);
    auto n = partition(head, 0);
    print(n);
}
