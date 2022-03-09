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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) //if singly linkedlist or ll is empty
            return head;
        ListNode*dummy=new ListNode(-100); //creating dummy node which acts as prev pts
        ListNode*prev=dummy; //previous ptr
        ListNode*curr=head; //current ptr
        while(curr) //traversing till current reaches end
        {
            if(curr->next && curr->val==curr->next->val)
            {
                while(curr->next && curr->val == curr->next->val)
                {
                    curr=curr->next;
                }

            }
            else
            {
                prev->next=curr;
                prev=curr;
            }
            curr=curr->next;
        }
        prev->next=NULL;
        return dummy->next;
    }
};