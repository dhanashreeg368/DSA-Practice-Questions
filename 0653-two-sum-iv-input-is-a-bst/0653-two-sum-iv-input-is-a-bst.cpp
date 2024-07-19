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
    bool reverse; // rev = false --> next, rev = true--> before 
public:
    BSTIterator(TreeNode* root, bool reverse) : reverse(reverse) {
        pushAll(root); // calls the pushAll function to push all the lefts
    }
    
    int next() { // this basically prints our ans, we are printing ans while popping the elements
        TreeNode* temp = st.top();
        st.pop(); 
        if (!reverse) {
            pushAll(temp->right);
        } else {
            pushAll(temp->left);
        }
        return temp->val;
    }
    
    bool hasNext() { // if stack is not empty that means it has next else it returns false
        return !st.empty(); 
    }
    
    void pushAll(TreeNode* node) { // push all the left in the stack
        while (node != NULL) {
            st.push(node);
            if (reverse) {
                node = node->right;
            } else {
                node = node->left;
            }          
        } 
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
if (root == NULL) return false;
        BSTIterator l(root, false); // Initialize iterator for in-order traversal
        BSTIterator r(root, true);  // Initialize iterator for reverse in-order traversal
        int i = l.next(); // Get the next element in in-order
        int j = r.next(); // Get the next element in reverse in-order
        while (i < j) { // Check if the two pointers have met or crossed
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }
        return false;     
    }
};