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
        ListNode* dummy=new ListNode(); // created to store the head node of new LL
        ListNode* temp=dummy; // created to iterate in new LL
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry) { // while l1, l2 are not empty and carry is present
            int sum=0;
            if (l1!=NULL) { 
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL) {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry; // calculate total sum including carry
            carry=sum/10; // if sum is 18, carry will be one
            ListNode* node=new ListNode(sum%10); // if sum=19, then node data = 9
            temp->next=node;
            temp=temp->next; // go to next node
        }
        return dummy->next;   
    }
};