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
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }
    
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};

        // If it's a leaf node, return a vector with distance 1
        if (!node->left && !node->right) return {1};

        std::vector<int> leftDistances = dfs(node->left, distance, count);
        std::vector<int> rightDistances = dfs(node->right, distance, count);

        // Count pairs
        for (int ld : leftDistances) {
            for (int rd : rightDistances) {
                if (ld + rd <= distance) {
                    count++;
                }
            }
        }

        // Increase the distance by 1 for all children distances
        std::vector<int> result;
        for (int ld : leftDistances) {
            if (ld + 1 <= distance) result.push_back(ld + 1);
        }
        for (int rd : rightDistances) {
            if (rd + 1 <= distance) result.push_back(rd + 1);
        }

        return result;
    } 
       
};