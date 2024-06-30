/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // balanced binary tree is a tree whose (height of left tree - height of right tree <=1)
    bool isBalanced(TreeNode* root) {
        return calculateHeight(root) != -1;
    }
    
    int calculateHeight(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        int leftHeight = calculateHeight(root->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = calculateHeight(root->right);
        if (rightHeight == -1) {
            return -1;
        }
        if ((abs(leftHeight - rightHeight)) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
};