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
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        //inorder reversal
        //recursive function
        if (root!=NULL)
        {
            convertBST(root->right); //right
            sum+=root->val; 
            root->val=sum;
            convertBST(root->left); //left
        }     
        return root;
    }
};