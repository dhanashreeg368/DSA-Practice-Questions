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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // start from the root node of the tree
        while (root) {
            // if p and q are greater than root, ans in the right
            if (p->val>root->val && q->val>root->val) { 
                root = root->right;
            // if p and q lesser than root, ans in the left
            } else if (p->val<root->val && q->val<root->val) { 
                root = root->left;
            // If one of p or q matches root, or they lie on opposite sides, we've found the LCA
            } else {
                return root;
            }   
        }
        return NULL;
    }
};