/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int look_for=target->val;
        return search(cloned,look_for);        
    }
        
    TreeNode* search(TreeNode* cloned, int look_for)
    {
        if (cloned==NULL) return NULL;
        if (look_for==cloned->val)
        {
            return cloned;
        }               
        TreeNode* left = search(cloned->left,look_for);
        if (left) return left;
            
        TreeNode* right = search(cloned->right,look_for);
        if (right) return right;
            
        return NULL;
    }
};