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
class BSTIterator {
private: stack<TreeNode*> st; //stack for storing elements
public:
    BSTIterator(TreeNode* root) {
        pushAll(root); // calls the pushAll function to push all the lefts
    }
    
    int next() { // this basically prints our ans, we are printing ans while popping the elements
        TreeNode* temp = st.top();
        st.pop(); 
        if (temp->right!=NULL) {
            pushAll(temp->right);
        }
        return temp->val;
    }
    
    bool hasNext() { // if stack is not empty that means it has next else it returns false
        return !st.empty(); 
    }
    
    void pushAll(TreeNode* node) { // push all the left in the stack
        while (node != NULL) {
            st.push(node);
            node = node->left;
        } 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */