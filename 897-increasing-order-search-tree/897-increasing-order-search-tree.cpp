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
    TreeNode *result, *prev;
    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        return result;
    }
    void inOrder(TreeNode* root) {
        if(root == NULL) return;
        inOrder(root -> left);
        
        if(result == NULL) {
            result = root;
        } else {
            prev -> right = root;
        }
        
        prev = root;
        root -> left = NULL;
        
        inOrder(root -> right);
    }
};