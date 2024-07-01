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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (root==NULL) {
            return ans;
        }
        zigzag(root, ans);
        return ans;
    }
    
    void zigzag(TreeNode*root, vector<vector<int>>& ans) {
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for (int i=0; i<size; i++) {
                TreeNode*front=q.front();
                if (front->left!=NULL) {
                    q.push(front->left);
                }
                if (front->right!=NULL) {
                    q.push(front->right);
                }
                level.push_back(front->val);
                q.pop();
            }
            if (!leftToRight) {
                    reverse(level.begin(), level.end());
            }
            ans.push_back(level);
            leftToRight=!leftToRight;
        }
        
    }
};