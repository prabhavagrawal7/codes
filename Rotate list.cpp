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
class Solution
{
public:
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
};