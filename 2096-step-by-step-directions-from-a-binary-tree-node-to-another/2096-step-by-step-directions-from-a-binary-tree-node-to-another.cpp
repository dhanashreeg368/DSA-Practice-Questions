class Solution {
public:
    bool findPath(TreeNode* root, int value, string& path) {
        if(!root) return false;
        if (root->val == value) return true; // if we find value return true
        
        path.push_back('L'); // check for left nodes 
        if (findPath(root->left, value, path)) return true;
        path.pop_back(); // pop while backtracking if a node is not found
        
        path.push_back('R'); // check for right nodes
        if (findPath(root->right, value, path)) return true;
        path.pop_back(); // pop while backtracking if a node is not found
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        // find path from root to both start and dest
        findPath(root, startValue, pathToStart); 
        findPath(root, destValue, pathToDest);  
        
        // find the divergence point
        int i=0, n = min(pathToStart.size(), pathToDest.size()); 
        //while values are equal, we do not find the divergence pt
        while(i<n && pathToStart[i]==pathToDest[i]) { 
            i++;
        }
        
        // generate the directions
        string path = string(pathToStart.size()-i, 'U'); // start to root path
        path+=pathToDest.substr(i); // root to destination path
        
        return path;

    }
};