/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode *partition(ListNode *head, int x)
{
    ListNode *xg = nullptr;
    ListNode *hxg = nullptr;
    ListNode *xs = nullptr;
    ListNode *hxs = nullptr;

    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        if (ptr->val >= x)
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
};