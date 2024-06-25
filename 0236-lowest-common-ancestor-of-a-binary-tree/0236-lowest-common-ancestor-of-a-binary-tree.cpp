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
        // If the root is null, return null
        if (root == nullptr) {
            return nullptr;
        }
        
        // If either p or q is the root, then root is LCA
        if (root == p || root == q) {
            return root;
        }
        
        // Look for keys in left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right subtrees have returned a non-null value,
        // then one node is found in one subtree and the other is found in the other subtree
        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }
        
        // Otherwise, check if left subtree or right subtree is LCA
        return (leftLCA != nullptr) ? leftLCA : rightLCA;
        
    }
};