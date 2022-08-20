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
    //finding length
    int length(ListNode* head) {
        int cnt=0;
        while(head!=NULL) {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //step 0: check length
        if(length(head)<k) {
            return head;
        }
        
        //Step 1: Ek ko khud karlo(That is ek group ko khudse reverse karlo)
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        int cnt=0;
        
        while(cnt<k && curr!=NULL) { //iterative reversal approach
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        
        //Step 2: Recursion aage kaa dekh lega
        if(next!=NULL) {
            head->next=reverseKGroup(next,k);
        }
        
        //Step 3: Return head of reversed ll
        return prev;        
    }
};