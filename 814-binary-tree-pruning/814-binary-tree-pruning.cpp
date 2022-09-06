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
    TreeNode* pruneTree(TreeNode* root) {
        find(root);
        if(root->left==NULL && root->right==NULL && root->val==0)
            return NULL;
        return root;
    }
    
    TreeNode* find(TreeNode* root)
    {
        if(root==NULL)
            return NULL;
        root->left=find(root->left);
        root->right=find(root->right);
        if(root->left==NULL && root->right==NULL && root->val==0)
            return NULL;
        return root;
    }
};