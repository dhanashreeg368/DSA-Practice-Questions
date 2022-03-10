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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy=new ListNode(); //crrsting new ll
        ListNode*ptr=dummy; //ptr for new ll
        int carry=0; //for carry
        while(carry || l1 || l2)
        {
            if(l1!=NULL)
            {
                carry+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                carry+=l2->val;
                l2=l2->next;
            }
            ptr->next=new ListNode(carry%10);
            carry/=10;
            ptr=ptr->next;
        }
        return dummy->next;
    }
};