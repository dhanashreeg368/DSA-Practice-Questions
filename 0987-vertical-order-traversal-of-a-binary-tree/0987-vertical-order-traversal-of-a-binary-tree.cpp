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
    
    void inorder(TreeNode* root,  map<int,multiset<pair<int,int>>>&mp, int vertical,int level) {
       if(root==NULL)return ;       
        
       mp[vertical].insert({level,root->val}); // for every vertical insert the value
       inorder(root->left, mp,vertical-1,level+1);  // go left
       inorder(root->right, mp,vertical+1,level+1); // go right

  }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,multiset<pair<int,int>>> mp; // {vertical --> {level, node}}
        int vertical=0, level = 0; // start from root 
        
        inorder(root, mp, vertical, level); // inorder for traversing all the nodes 
        
        for(auto it=mp.begin(); it!=mp.end(); it++){
              vector<int>l;
              for(auto i:it->second){
                l.push_back(i.second);
              }
            ans.push_back(l);
        }

        return ans;
    }
};