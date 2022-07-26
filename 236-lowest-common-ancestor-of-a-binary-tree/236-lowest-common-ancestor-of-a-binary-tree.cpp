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
        
        //base case 
        if(root==NULL || p==root || q==root) //if we found any of the required node return that node 
        {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q); //we go left
        TreeNode* right = lowestCommonAncestor(root->right, p, q); //we go right
        
        if(left==NULL)
        {
            return right;
        }
        else if(right==NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
};