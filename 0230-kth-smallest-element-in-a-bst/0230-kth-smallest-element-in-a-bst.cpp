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
    void inorder(TreeNode* root, int k, int& count, int& kSmallest) {
        if (!root || count>=k) {
            return;
        }
        inorder(root->left, k, count, kSmallest); // go left
        count++; // at left we find smallest, so incr count
        if (count == k) { // if condition achieve return kSmallest
            kSmallest = root->val;
            return;
        }
        inorder(root->right, k, count, kSmallest); // go right
    }
    
    int kthSmallest(TreeNode* root, int k) {
       int kSmallest = INT_MIN; // to store kth Smallest element
        int count = 0; // count to check if kth Smallest is achieve
        inorder(root, k, count, kSmallest); // call inorder traversal
        return kSmallest;
    }
};