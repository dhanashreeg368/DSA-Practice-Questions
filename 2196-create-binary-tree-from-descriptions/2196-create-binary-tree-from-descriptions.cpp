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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> children; // stores children
        unordered_map<int, TreeNode*> nodes; // stores all the nodes
        
        for (auto& description: descriptions) {
            int parentVal = description[0];
            int childVal = description[1];
            int isLeft = description[2];
            
            // create parent node if not already present 
            if (nodes.find(parentVal)==nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
             
            // create childnode if not already present
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }
            
            // define the relationship between parent and child
            if(isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }
            children.insert(childVal);          
        }
        
        // The root is the node that is not in the children set
        for (auto& nodePair: nodes) {
            if (children.find(nodePair.first) == children.end()) {
                return nodePair.second;
            }
        }
        return NULL;
    }
};