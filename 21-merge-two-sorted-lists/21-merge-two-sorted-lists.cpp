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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==NULL) return list2; 
        if (list2==NULL) return list1;
        ListNode*dummy,*temp; //temp for traversing in new ll
        dummy=new ListNode(); //creating dummy ll
        temp=dummy; //initially
        while(list1 && list2) //when both doesn't reach end
        {
            if(list1->val < list2->val) 
            {
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next; //temp to next loc
        }
        //reached end of ll
        if(list1) temp->next=list1; //if end of list1 not reached 
        if(list2) temp->next=list2; //if end of list2 not reached 
        return dummy->next; //return new ll
    }
};