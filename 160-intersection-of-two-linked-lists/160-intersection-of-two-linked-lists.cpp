/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1=headA, *cur2=headB;
        while(cur1!=cur2)
        {
            cur1=!cur1 ? headB: cur1->next;
            cur2=!cur2 ? headA: cur2->next;
        }
        return cur1;
    }
};