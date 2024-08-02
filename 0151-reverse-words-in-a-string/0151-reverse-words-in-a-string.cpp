class Solution {
public:
    string reverseWords(string s) {
        int left = 0; 
        int n = s.length();
        string ans;
        string temp;
        
        while(left<n) {
            char ch = s[left];
            if (ch == ' ') {
                if (temp != "") {
                    if (ans == "") {
                        ans = temp;
                    } else {
                        ans = temp + " " + ans;
                    }
                    temp.clear();
                } 
            } else {
                temp+=ch;
            }
            left++;
        }
        
        if (temp!="") { // for last word
            if (ans!="") {
                ans = temp + " " + ans;
            } else {
                ans = temp;
            }
        }
        return ans;
    }
};