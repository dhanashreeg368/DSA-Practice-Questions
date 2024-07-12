class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points = 0;
        // need to solve this problem greedily
        // the one with max points should be consider first
        if (x>y) {
            // first remove ab and then ba
            points+=removePairs(s, 'a', 'b', x); 
            points+= removePairs(s, 'b', 'a', y);
        } else {
            // first remove ba and then ab
            points+= removePairs(s, 'b', 'a', y);
             points+=removePairs(s, 'a', 'b', x);
        } 
        return points;
    }
    
    int removePairs(string& s, char first, char second, int bonus) {
        int points = 0;
        string temp="";
        stack<char> st;
        for (char ch: s) {
            // put chars in the string until ab or ba is encountered
            if (!st.empty() && st.top()==first && ch==second) { 
                st.pop();
                points+=bonus;
            } else {
                st.push(ch);
            }
        }
        // for the remaining string - prepare string and consider again 
        while(!st.empty()) {
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end()); // reverse as we are removing it from stack
        s=temp;
        return points;
    }
};