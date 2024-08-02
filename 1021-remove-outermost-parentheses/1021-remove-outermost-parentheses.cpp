class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0; // cntr to keep a track of parenthesis
        string ans; // to store ans
        for(char ch: s) { // iterate through every char
            if (ch == '(') { // if '(' --> increment open
                // if open is greater than 0, that means not outermost, push in ans
                if(open > 0) {
                    ans+='('; 
                }
                open++;               
            } else { // if ')' --> decr open
                open--;
                // when open is greater than 1 
                if (open>0) {
                    ans+=')';
                }
            }
        }
        return ans;
    }
};