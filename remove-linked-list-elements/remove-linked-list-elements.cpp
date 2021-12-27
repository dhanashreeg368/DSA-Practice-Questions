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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (head==NULL)  //if ll is empty
        {
            return NULL;  //return null
        }
        ListNode*temp=new ListNode(0);
        temp->next=head;
        head=temp;
        while(temp->next)
        {
            if(temp->next->val==val)
            {
                temp->next=temp->next->next;
            }
            else
            {
                temp=temp->next;
            }
        }
        return head->next;
    }
};