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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0; // for root
        return build(preorder, i, INT_MAX);
    }
    
    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        if (i==preorder.size() || preorder[i]>bound) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]); // construct node and increment index
        root->left = build(preorder, i,root->val); // go for left
        root->right = build(preorder, i, bound); // go for right
        return root;
    }
};