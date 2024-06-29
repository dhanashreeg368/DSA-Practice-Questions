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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans); // call inOrder method
        return ans;
    }
    
    void inOrder(TreeNode*  root, vector<int>& ans) {
        // if null is reached
        if (root==nullptr) {
            return;
        }
        inOrder(root->left, ans); // left
        ans.push_back(root->val); //root
        inOrder(root->right, ans); //right
    }
};