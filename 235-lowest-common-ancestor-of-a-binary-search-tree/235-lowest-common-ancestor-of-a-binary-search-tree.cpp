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
    
    //check left and right first
//     Case1: Both p & q are smaller than the root node, then both elements, as well as LCA, will be in the left subtree.
// Case2: Both are greater than the root node, then both elements, as well as LCA, will be in the right subtree.
// Case3: If 1 element is greater than the root and the other is smaller than the root, that means both elements are in different subtrees. That means the root node is the LCA.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val>q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val && root->val<q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};