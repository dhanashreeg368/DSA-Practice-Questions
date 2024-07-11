class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string temp="";
        for (int i=0; i<s.length(); i++) {
            char ch = s[i];
            if (ch!=')') {
                st.push(ch);
            } else if (ch==')') {
                while (st.top()!='(') {
                    if (st.top()!='(') {
                        temp+=st.top();
                    }
                    st.pop();                    
                }
                st.pop();
            }
            for (int i = 0; i <temp.length(); i++) {
                st.push(temp[i]);
            }
            temp.clear();
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};