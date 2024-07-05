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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int index = 1;
        vector<int> criticalPoints;
        vector<int> ans;
        int mini=INT_MAX;
        if (!head || !head->next || !head->next->next) {
            return vector<int>{-1, -1};
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        while(next!=NULL) {
            if ((curr->val>prev->val && curr->val>next->val) || 
                (curr->val<prev->val && curr->val<next->val)) {
                criticalPoints.push_back(index); 
            }
            index+=1;
            prev=curr;
            curr=next;
            next=next->next;
        }
        if (criticalPoints.size()<2) {
            return vector<int>{-1, -1};
        }
        int size = criticalPoints.size();
        int maxi=criticalPoints[size-1] - criticalPoints[0];
        for (int i=1; i<size; i++) {
            mini=min(mini, criticalPoints[i]-criticalPoints[i-1]);
        }
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};