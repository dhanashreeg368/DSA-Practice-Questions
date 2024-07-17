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
TreeNode* dfs(TreeNode* node, unordered_set<int> &delete_map, vector<TreeNode*> &ans) {
        if (!node) {
            return nullptr;
        }

        node->left = dfs(node->left, delete_map, ans);
        node->right = dfs(node->right, delete_map, ans);

        if (delete_map.find(node->val) != delete_map.end()) {
            if (node->left) {
                ans.push_back(node->left);
            }

            if (node->right) {
                ans.push_back(node->right);
            }

            return nullptr;
        }

        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delete_map(to_delete.begin(), to_delete.end());

        vector<TreeNode*> ans;

        if(dfs(root, delete_map, ans)) {
            ans.push_back(root);
        }

        return ans;
    }
};