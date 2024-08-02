class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st; // uaing stack DS
        string ans; // to store ans
        for(char ch: s) { // iterate through every char
            if (ch == '(') { // if '(' --> push in stack
                // if stack was initally empty that means this is the outermost parenthese, 
                // so that cannot be part of ans, Hence, add only when stack is not empty
                if(!st.empty()) {
                    ans+='('; 
                }
                st.push(ch);               
            } else { // if ')' --> pop out of stack
                // whenever we are popping elements stack can be empty, 
                // to only add to ans when popping the element isn't the outermost character
                if (st.size() > 1) {
                    ans+=')';
                }
                st.pop();
            }
        }
        return ans;
    }
};